#include "CustomTextStyle.h"
#include <sstream>
#include <boost/algorithm/string.hpp>

bool TextMultiLineCalculator::measureLines_is_busy = false;

// calculate where line breaks will occur when passing a text to freetype::easy_printAutoNewlines
TextMultiLineCalculator::TextMultiLineCalculator(const std::string &_text, int _fontSize, int _line_length) : text(_text), fontSize(_fontSize), line_length(_line_length)
{
    line_height = G_->GetResources()->GetFontData(fontSize, false).lineHeight;
    ParseText();
}

int TextMultiLineCalculator::MeasureLines(const std::string &text)
{
    TextMultiLineCalculator::measureLines_is_busy = true;
    int ret = static_cast<int>(freetype::easy_measurePrintLines(fontSize, 0, 0, line_length, text).y) / line_height;
    TextMultiLineCalculator::measureLines_is_busy = false;
    return ret;
}

/* why freetype::easy_print instead of measure method?
You need to understand what each return value of freetype::easy_ functions means.

easy_measurePrintLines -> Pointf : vertical and horizontal length of the imaginary rectangle surrounding a text.
easy_measureWidth -> int : horizontal length of the imaginary rectangle surrounding a text.
So the arguments x and y make no sense in these functions I guess?

easy_printAutoNewlines -> Pointf : the position of the last word's texture (containing blank space) of a text.

In FTL fonts, every character has its own texture and defines its blank space before and after.
The point is easy_measure-- functions do NOT take "blank space after of the far right character" into return value and easy_print-- functions DO.
The condition for line break is "the pixel length from the start x to the x of the far right character's texture" > the line length, so you need to use the return value of easy_print-- for calculating line breaks.
*/
int TextMultiLineCalculator::MeasureWidth(const std::string &text)
{
    return static_cast<int>(freetype::easy_print(fontSize, 0, 0, text).x);
}

// long word means a word potentially divided by line breaks
std::string TextMultiLineCalculator::ProcessLongWord(const std::string &word, int start_pos)
{
    int break_point = 0;
    int d;
    for (int i = 0; i < word.length(); i += d)
    {
        unsigned char c = word[i];
        if ((c & 0x80) == 0) d = 1;         // c is 1 byte character
        else if ((c & 0xE0) == 0xC0) d = 2; // c is the first byte of 2 byte character
        else if ((c & 0xF0) == 0xE0) d = 3; // c is the first byte of 3 byte character
        else if ((c & 0xF8) == 0xF0) d = 4; // c is the first byte of 4 byte character
        
        if (MeasureWidth(word.substr(break_point, i + d - break_point)) > line_length)
        {
            break_point = i;
            linePositions.push_back(start_pos + i);
        }
    }
    return word.substr(break_point);
}

void TextMultiLineCalculator::ProcessWord(int pos)
{
    string_buffer = string_buffer + text.substr(word_start, pos - word_start);
    int line = MeasureLines(string_buffer);
    if (line > 2)
    {
        if (!current_line_is_empty) linePositions.push_back(word_actual_start);
        std::string word = text.substr(word_actual_start, pos - word_actual_start);
        string_buffer = ProcessLongWord(word, word_actual_start);
    }
    else if (line == 2)
    {
        if (current_line_is_empty)
        {
            string_buffer = ProcessLongWord(string_buffer, linePositions[linePositions.size() - 1]);
        }
        else
        {
            linePositions.push_back(word_actual_start);
            string_buffer = text.substr(word_actual_start, pos - word_actual_start);
        }
    }
    current_line_is_empty = false;
}

void TextMultiLineCalculator::ParseText()
{
    int text_length = text.length();
    CharType previous = space;

    for (int i = 0; i < text_length; i++)
    {
        if (i == text_length - 1)
        {
            if (text[i] == '\n')
            {
                ProcessWord(i);
                linePositions.push_back(i);
            }
            else
            {
                ProcessWord(line_length);
            }
        }
        else if (text[i] == ' ')
        {
            if (previous == normal)
            {
                ProcessWord(i);
                word_start = i;
            }
            else if (previous == newline)
            {
                word_start = i;
            }
            previous = space;
        }
        else if (text[i] == '\n')
        {
            if (previous == space)
            {
                string_buffer = string_buffer + text.substr(word_start, i - word_start);
                int line = MeasureLines(string_buffer);
                if (line > 1)
                {
                    linePositions.push_back(word_start);
                }
            }
            else if (previous == normal)
            {
                ProcessWord(i);
            }
            linePositions.push_back(i);
            word_start = i;
            word_actual_start = i;
            string_buffer = "";
            current_line_is_empty = true;
            previous = newline;
        }
        else
        {
            if (previous == space)
            {
                word_actual_start = i;
            }
            else if (previous == newline)
            {
                word_start = i;
                word_actual_start = i;
            }
            previous = normal;
        }
    }
}

// Custom Text Style Cell Primitive

CustomTextStyleCellPrimitive::CustomTextStyleCellPrimitive(const std::string &_flagContent, int _begin_pos, int _end_pos, int _fontSize) : flagContent(_flagContent), begin_pos(_begin_pos), end_pos(_end_pos), fontSize(_fontSize)
{
    boost::algorithm::replace_all(flagContent, " ", "");
    ParseFlag();
}

char hexCharToInt(char ch)
{
    if ('A' <= ch && ch <= 'F') // ABCDEF
    {
        return ch - 55;
    }
    else if ('a' <= ch && ch <= 'f') // abcdef
    {
        return ch - 87;
    }
    else if ('0' <= ch && ch <= '9') // 0123456789
    {
        return ch - 48;
    }
    else return 15; // undefined
}

void CustomTextStyleCellPrimitive::ParseFlag()
{
    if (flagContent.empty() || flagContent.length() < 12) return;
    if (flagContent[0] == 'c' && flagContent[1] == 'o'
    && flagContent[2] == 'l' && flagContent[3] == 'o'
    &&flagContent[4] == 'r' && flagContent[5] == ':')
    {
        colored = true;
        uint8_t r = (hexCharToInt(flagContent[6]) << 4) | hexCharToInt(flagContent[7]);
        uint8_t g = (hexCharToInt(flagContent[8]) << 4) | hexCharToInt(flagContent[9]);
        uint8_t b = (hexCharToInt(flagContent[10]) << 4) | hexCharToInt(flagContent[11]);
        uint8_t a;
        if (flagContent.length() > 13)
        {
            a = (hexCharToInt(flagContent[12]) << 4) | hexCharToInt(flagContent[13]);
        }
        else{
            a = 255;
        }
        colorKey = (r << 24) | (g << 16) | (b << 8) | a; // used for vector sorting
        textColor = GL_Color(r / 255.f, g / 255.f, b / 255.f, a / 255.f);
    }
}

void CustomTextStyleCellPrimitive::DivideSelfByLineBreaks(const std::vector<int> &linePositions, std::vector<CustomTextStyleCellPrimitive> &distContainer)
{
    bool first = true;
    int original_begin_pos = begin_pos;
    int original_end_pos = end_pos;
    for (int i = 0; i + 1 < linePositions.size(); i++)
    {
        int pos = linePositions[i];
        int next_pos = linePositions[i + 1];
        if (next_pos <= original_begin_pos) continue;
        if (first && next_pos > original_end_pos)
        {
            firstCell_of_thisLine = pos == original_begin_pos;
            distContainer.emplace_back(*this);
            return;
        }
        if (first)
        {
            end_pos = next_pos - 1;
            firstCell_of_thisLine = pos == original_begin_pos;
            distContainer.emplace_back(*this);
            first = false;
            continue;
        }
        firstCell_of_thisLine = true;
        if (next_pos > original_end_pos)
        {
            begin_pos = pos;
            end_pos = original_end_pos;
            distContainer.emplace_back(*this);
            return;
        }
        begin_pos = pos;
        end_pos = next_pos - 1;
        distContainer.emplace_back(*this);
    }
    if (first)
    {
        begin_pos = original_begin_pos;
        end_pos = original_end_pos;
        firstCell_of_thisLine = original_begin_pos == linePositions[linePositions.size() - 1];
    }
    else
    {
        begin_pos = linePositions[linePositions.size() - 1];
        end_pos = original_end_pos;
        firstCell_of_thisLine = true;
    }
    distContainer.emplace_back(*this);
}

void CustomTextStyleCellPrimitive::SetText(const std::string &fullText)
{
    text = fullText.substr(begin_pos, end_pos - begin_pos + 1);
    // remove newlines; the first letter of text could be \n, which is unnecessary
    boost::algorithm::replace_all(text, "\n", "");
}

// Custom Text Style Cache

Pointf CustomTextStyleCache::Measure()
{
    age = 0;
    return Pointf(ret_measured_x, ret_y);
}

Pointf CustomTextStyleCache::Print(float base_x, float base_y)
{
    age = 0;
    const GL_Color originalColor = CSurface::GL_GetColor();
    GL_Color currentColor = originalColor;

    for (auto &cell : cells)
    {
        if (cell.colored && currentColor != cell.textColor)
        {
            CSurface::GL_SetColor(cell.textColor);
            currentColor = cell.textColor;
        }
        else if (!(cell.colored) && currentColor != originalColor)
        {
            CSurface::GL_SetColor(originalColor);
            currentColor = originalColor;
        }
        freetype::easy_print(cell.fontSize, base_x + cell.x, base_y + cell.y, cell.text);
    }

    CSurface::GL_SetColor(originalColor);
    return Pointf(ret_x + base_x, ret_y + base_y);
}

// Custom Text Style Manager

CustomTextStyleManager CustomTextStyleManager::instance = CustomTextStyleManager();

bool CustomTextStyleManager::IsFlagExist(const std::string &text)
{
    if (text.length() < 31) return false; // the shortest text containing flag: [style[color:XXXXXX]][[/style]]
    return text.find("[style[") != std::string::npos;
}

std::string CustomTextStyleManager::GetKey(const std::string &text, int fontSize, int line_length)
{
    std::stringstream stream;
    stream << text << ";" << fontSize << ";" << line_length;
    return stream.str();
}

void CustomTextStyleManager::CreateCustomTextStyle(const int fontSize, const int line_length, const std::string &originalText)
{
    const GL_Color originalColor = CSurface::GL_GetColor();
    CSurface::GL_SetColor(GL_Color(0.f, 0.f, 0.f, 0.f));

    // step 1: find flags and divide texts into cells with a flag
    std::string sanitizedText;
    std::vector<CustomTextStyleCellPrimitive> primitiveCells;

    int len = originalText.length();
    std::string tmp_flagContent;
    FindingTarget findingTarget = startFlag_begin;
    int pureTextBegin = 0;
    int maybeNextPlainTextBegin = 0;
    int flagContentBegin = 0;
    int pureTextPositionDecrement = 0;
    for (int i = 0; i < len; i++)
    {
        if (findingTarget == startFlag_begin)
        {
            if (originalText[i] != '[' || len - i < 9) continue;
            if (!(originalText[i + 1] == 's' && originalText[i + 2] == 't'
             && originalText[i + 3] == 'y' && originalText[i + 4] == 'l' 
             && originalText[i + 5] == 'e' && originalText[i + 6] == '[')) continue;
            
            sanitizedText += originalText.substr(pureTextBegin, i - pureTextBegin);
            if (i - maybeNextPlainTextBegin > 0)
            {
                primitiveCells.emplace_back("", pureTextBegin - pureTextPositionDecrement, i - 1 - pureTextPositionDecrement, fontSize);
            }
            flagContentBegin = i + 7;
            findingTarget = startFlag_termination;
            i += 6;
        }
        else if (findingTarget == startFlag_termination)
        {
            if (originalText[i] != ']' || len - i < 3) continue;
            if (originalText[i + 1] != ']') continue;

            pureTextPositionDecrement += i - flagContentBegin + 9;
            tmp_flagContent = originalText.substr(flagContentBegin, i - flagContentBegin);
            pureTextBegin = i + 2;
            findingTarget = closeFlag;
            i += 1;
        }
        else if (findingTarget == closeFlag)
        {
            if (originalText[i] != '[' || len - i < 10) continue;
            if (!(originalText[i + 1] == '[' && originalText[i + 2] == '/'
             && originalText[i + 3] == 's' && originalText[i + 4] == 't'
             && originalText[i + 5] == 'y' && originalText[i + 6] == 'l'
             && originalText[i + 7] == 'e' && originalText[i + 8] == ']' && originalText[i + 9] == ']')) continue;
            
            sanitizedText += originalText.substr(pureTextBegin, i - pureTextBegin);
            primitiveCells.emplace_back(tmp_flagContent, pureTextBegin - pureTextPositionDecrement, i - 1 - pureTextPositionDecrement, fontSize);
            pureTextPositionDecrement += 10;
            pureTextBegin = i + 10;
            maybeNextPlainTextBegin = i + 10;
            findingTarget = startFlag_begin;
            i += 9;
        }
    }
    if (findingTarget != startFlag_termination) sanitizedText += originalText.substr(pureTextBegin, len - pureTextBegin);
    if (primitiveCells.size() > 0 && sanitizedText.length() - 1 > primitiveCells[primitiveCells.size() - 1].end_pos)
    {
        primitiveCells.emplace_back("", primitiveCells[primitiveCells.size() - 1].end_pos + 1, sanitizedText.length() - 1, fontSize);
    }

    // step 2: adjust cells; some cells may span multiple lines. this step divide such cells and makes sure each cell fits within one line.
    std::vector<CustomTextStyleCellPrimitive> dividedPrimitiveCells;
    TextMultiLineCalculator calculator(sanitizedText, fontSize, line_length);
    for (auto &cell : primitiveCells)
    {
        cell.DivideSelfByLineBreaks(calculator.GetLinePositions(), dividedPrimitiveCells);
    }

    // step 3: set text and position
    int height = calculator.GetLineHeight();
    float next_x = 0.f;
    float next_y = -height;
    float last_measured_x;
    for (int i = 0; i < dividedPrimitiveCells.size(); i++)
    {
        auto &cell = dividedPrimitiveCells[i];
        cell.SetText(sanitizedText);
        if (cell.firstCell_of_thisLine)
        {
            next_x = 0.f;
            next_y += height;
        }
        cell.x = next_x;
        cell.y = next_y;
        if (i == dividedPrimitiveCells.size() - 1)
        {
            last_measured_x = next_x + freetype::easy_measureWidth(fontSize, cell.text);
        }
        next_x += freetype::easy_print(fontSize, 0.f, 0.f, cell.text).x;
    }

    // step 4: sort cells by color for reducing color switching
    std::sort(dividedPrimitiveCells.begin(), dividedPrimitiveCells.end(), [](const CustomTextStyleCellPrimitive &a, const CustomTextStyleCellPrimitive &b){
        if (!(a.colored) && !(b.colored)) return false;
        else if (a.colored && !(b.colored)) return false;
        else if (!(a.colored) && b.colored) return true;
        else return a.colorKey < b.colorKey;
    });

    // step 5: transfer info from primitives into cells
    std::vector<CustomTextStyleCell> cacheCells;
    for (auto &cell: dividedPrimitiveCells)
    {
        cacheCells.emplace_back(cell);
    }

    // step 6: store cache
    std::string key = GetKey(originalText, fontSize, line_length);
    cache[key] = CustomTextStyleCache(cacheCells, next_x, next_y + height, last_measured_x);

    CSurface::GL_SetColor(originalColor);
}

// for freetype::easy_measurePrintLines
Pointf CustomTextStyleManager::Measure(int fontSize, int line_length, const std::string &text)
{
    std::string key = GetKey(text, fontSize, line_length);
    if (cache.count(key) == 0)
    {
        CreateCustomTextStyle(fontSize, line_length, text);
    }
    return cache[key].Measure();
}

// for freetype::easy_printAutoNewlines
Pointf CustomTextStyleManager::Print(int fontSize, float x, float y, int line_length, const std::string &text)
{
    std::string key = GetKey(text, fontSize, line_length);
    if (cache.count(key) == 0)
    {
        CreateCustomTextStyle(fontSize, line_length, text);
    }
    return cache[key].Print(x, y);
}

void CustomTextStyleManager::AgeCache()
{
    cacheAgingCount++;
    if (cacheAgingCount > cacheAgingInterval)
    {
        cacheAgingCount = 0;
        for (auto it = cache.begin(); it != cache.end();)
        {
            (it->second.age)++;
            if (it->second.age > deadAgeThreshold)
            {
                it = cache.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
}

void CustomTextStyleManager::ClearCache()
{
    cache.clear();
}


HOOK_METHOD(CApp, OnLanguageChange, () -> void)
{
    LOG_HOOK("HOOK_METHOD -> CApp::OnLanguageChange -> Begin (CustomTextStyle.cpp)\n")
    if (CustomTextStyleManager::GetInstance()->enabled) CustomTextStyleManager::GetInstance()->ClearCache();
    return super();
}

HOOK_STATIC(freetype, easy_measurePrintLines, (int fontSize, float x, float y, int line_length, const std::string &text) -> Pointf)
{
    LOG_HOOK("HOOK_STATIC -> freetype::easy_measurePrintLines -> Begin (CustomTextStyle.cpp)\n")
    if(!CustomTextStyleManager::GetInstance()->enabled ||
     TextMultiLineCalculator::measureLines_is_busy ||
     !CustomTextStyleManager::IsFlagExist(text)) return super(fontSize, x, y, line_length, text);

    return CustomTextStyleManager::GetInstance()->Measure(fontSize, line_length, text);
}

HOOK_STATIC(freetype, easy_printAutoNewlines, (int fontSize, float x, float y, int line_length, const std::string &text) -> Pointf)
{
    LOG_HOOK("HOOK_STATIC -> freetype::easy_printAutoNewlines -> Begin (CustomTextStyle.cpp)\n")
    if (!CustomTextStyleManager::GetInstance()->enabled) return super(fontSize, x, y, line_length, text);

    CustomTextStyleManager::GetInstance()->AgeCache();
    if (!CustomTextStyleManager::IsFlagExist(text)) return super(fontSize, x, y, line_length, text);

    return CustomTextStyleManager::GetInstance()->Print(fontSize, x, y, line_length, text);
}
