#include "Helpers.h"
#include "../../../Global.h"
#include <vector>

#if defined(__APPLE__) || defined(__linux__)
    // OpenGL forward declarations to avoid conflicts with FTL headers
    typedef int GLint;
    extern "C" {
        void glReadPixels(int x, int y, int width, int height, unsigned int format, unsigned int type, void* pixels);
        void glGetIntegerv(unsigned int pname, GLint* params);
    }
    #define GL_RGB 0x1907
    #define GL_UNSIGNED_BYTE 0x1401
    #define GL_VIEWPORT 0x0BA2
#elif defined(_WIN32)
    #include <GL/gl.h>
#endif

namespace TestHelpers
{

    // ============================================
    // Screenshot Utilities
    // ============================================

    bool takeScreenshot(const std::string& filename)
    {
        hs_log_file("[SCREENSHOT] Starting screenshot capture...\n");

        // Create screenshots directory
        system("mkdir -p tests/screenshots");

        // Build filepath
        std::string filepath = "tests/screenshots/" + filename;
        if (filepath.find(".bmp") == std::string::npos)
        {
            filepath += ".bmp";
        }

        hs_log_file(("[SCREENSHOT] Target filepath: " + filepath + "\n").c_str());

        // Get screen size from OpenGL viewport (works on all platforms)
        int width, height;
        GLint viewport[4];
        hs_log_file("[SCREENSHOT] Getting OpenGL viewport...\n");
        glGetIntegerv(GL_VIEWPORT, viewport);
        width = viewport[2];
        height = viewport[3];
        hs_log_file(("[SCREENSHOT] Viewport size: " + std::to_string(width) + "x" + std::to_string(height) + "\n").c_str());

        if (width == 0 || height == 0)
        {
            hs_log_file(("[SCREENSHOT] Failed: invalid size (" + std::to_string(width) + "x" + std::to_string(height) + ")\n").c_str());
            return false;
        }

        // Read pixels from OpenGL
        hs_log_file("[SCREENSHOT] Allocating pixel buffer...\n");
        std::vector<unsigned char> pixels(width * height * 3);
        hs_log_file("[SCREENSHOT] Calling glReadPixels...\n");
        glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels.data());
        hs_log_file("[SCREENSHOT] glReadPixels complete\n");

        // Write BMP file
        hs_log_file(("[SCREENSHOT] Opening file: " + filepath + "\n").c_str());
        FILE* f = fopen(filepath.c_str(), "wb");
        if (!f)
        {
            hs_log_file(("[SCREENSHOT] Failed: cannot open file: " + filepath + "\n").c_str());
            return false;
        }
        hs_log_file("[SCREENSHOT] File opened successfully\n");

        // BMP header (54 bytes)
        unsigned char header[54] = {
            'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
        };

        int rowPadding = (4 - (width * 3) % 4) % 4;
        int rowSize = width * 3 + rowPadding;
        int imageSize = rowSize * height;
        int fileSize = 54 + imageSize;

        *(int*)&header[2] = fileSize;
        *(int*)&header[18] = width;
        *(int*)&header[22] = height;
        *(int*)&header[34] = imageSize;

        fwrite(header, 1, 54, f);

        // Write pixels row by row (BMP is bottom-up, swap RGB to BGR)
        hs_log_file("[SCREENSHOT] Writing pixel data...\n");
        std::vector<unsigned char> row(rowSize);
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                int srcIdx = (y * width + x) * 3;
                int dstIdx = x * 3;
                row[dstIdx + 0] = pixels[srcIdx + 2];  // B
                row[dstIdx + 1] = pixels[srcIdx + 1];  // G
                row[dstIdx + 2] = pixels[srcIdx + 0];  // R
            }
            for (int p = 0; p < rowPadding; p++)
                row[width * 3 + p] = 0;
            fwrite(row.data(), 1, rowSize, f);
        }

        fclose(f);
        hs_log_file(("[SCREENSHOT] SUCCESS: Screenshot saved: " + filepath + " (" + std::to_string(width) + "x" + std::to_string(height) + ")\n").c_str());
        return true;
    }
}
