#include "Global.h"

// calculate where line breaks will occur when passing a text to freetype::easy_printAutoNewlines
class TextMultiLineCalculator
{
public:
    TextMultiLineCalculator(const std::string &_text, int _fontSize, int _line_length);
    int GetLineHeight() {return line_height;}
    std::vector<int> &GetLinePositions() {return linePositions;}

    static bool measureLines_is_busy;

private:
    void ParseText();
    int MeasureLines(const std::string &text);
    int MeasureWidth(const std::string &text);
    void ProcessWord(int pos);
    std::string ProcessLongWord(const std::string &word, int start_pos);

    enum CharType
    {
        normal,
        space,
        newline
    };

    std::string text;
    int fontSize;
    int line_length;
    int line_height;
    std::vector<int> linePositions = std::vector<int>(1, 0);
    std::string string_buffer;
    int word_start = 0;
    int word_actual_start = 0;
    bool current_line_is_empty = true;
};

struct CustomTextStyleCellPrimitive
{
    CustomTextStyleCellPrimitive(const std::string &_flagContent, int _begin_pos, int _end_pos, int _fontSize) : flagContent(_flagContent), begin_pos(_begin_pos), end_pos(_end_pos), fontSize(_fontSize)
    {
        flagContent.erase(std::remove_if(flagContent.begin(), flagContent.end(), [](char c){return c == ' ';}), flagContent.end());
        ParseFlag();
    }

    void ParseFlag();
    void DivideSelfByLineBreaks(const std::vector<int> &linePositions, std::vector<CustomTextStyleCellPrimitive> &distContainer);
    void SetText(const std::string &fullText);

    std::string flagContent;
    std::string text;
    int begin_pos;
    int end_pos;
    bool firstCell_of_thisLine = false;
    float x;
    float y;
    int fontSize;

    bool colored = false;
    uint32_t colorKey;
    GL_Color textColor;
};

struct CustomTextStyleCell
{
    CustomTextStyleCell(const CustomTextStyleCellPrimitive &primitive) : text(primitive.text), fontSize(primitive.fontSize), x(primitive.x), y(primitive.y), colored(primitive.colored), textColor(primitive.textColor) {}

    std::string text;
    int fontSize;
    float x;
    float y;
    bool colored;
    GL_Color textColor;
};

struct CustomTextStyleCache
{
    CustomTextStyleCache() {}
    CustomTextStyleCache(std::vector<CustomTextStyleCell>_cells, float _ret_x, float _ret_y, float _ret_measured_x) : cells(_cells), ret_x(_ret_x), ret_y(_ret_y), ret_measured_x(_ret_measured_x) {}
    Pointf Measure();
    Pointf Print(float base_x, float base_y);

    int age = 0;

private:
    std::vector<CustomTextStyleCell> cells;
    float ret_measured_x;
    float ret_x;
    float ret_y;
};

class CustomTextStyleManager
{
public:
    static bool IsFlagExist(const std::string &text);

    Pointf Measure(int fontSize, int line_length, const std::string &text);
    Pointf Print(int fontSize, float x, float y, int line_length, const std::string &text);
    void AgeCache();
    void ClearCache();

    bool enabled = false;

    static CustomTextStyleManager *GetInstance() {return &instance;}
private:

    void CreateCustomTextStyle(const int fontSize, const int line_length, const std::string &originalText);
    
    enum FindingTarget
    {
        startFlag_begin,
        startFlag_termination,
        closeFlag
    };

    const int deadAgeThreshold = 10;
    const int cacheAgingInterval = 1000;

    std::unordered_map<std::string, CustomTextStyleCache> cache = std::unordered_map<std::string, CustomTextStyleCache>();
    int cacheAgingCount = 0;

    static CustomTextStyleManager instance;
};
