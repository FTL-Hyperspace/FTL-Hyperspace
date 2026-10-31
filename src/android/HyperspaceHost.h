#pragma once

#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define HS_HOST_VERSION 1

typedef struct hs_host_info
{
    uint32_t version;
    uint32_t size;

    const void *mach_header;
    intptr_t slide;
    size_t image_size;

    const char *log_dir;
    const char *data_dir;

    void (*log)(int level, const char *message);

    int (*find_macho_unwind)(uintptr_t pc, uintptr_t *mh, uintptr_t *text_len, uintptr_t *compact_unwind,
                             size_t *compact_unwind_len, uintptr_t *eh_frame, size_t *eh_frame_len);
} hs_host_info;

int hs_android_init(const hs_host_info *info, char *error, size_t error_size);
typedef int (*hs_android_init_fn)(const hs_host_info *info, char *error, size_t error_size);

enum { HS_RIGHT_BUTTON_DOWN = 0, HS_RIGHT_BUTTON_MOVE = 1, HS_RIGHT_BUTTON_UP = 2 };
int hs_android_wants_right_click(void);
void hs_android_right_button(int action, int x, int y);
typedef int (*hs_android_wants_right_click_fn)(void);
typedef void (*hs_android_right_button_fn)(int action, int x, int y);

#ifdef __cplusplus
}
#endif
