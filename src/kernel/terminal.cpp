//
// Created by dev on 19/03/18.
//

#include "arch/i386/include/terminal.h"
#include "arch/i386/include/memory.h"
#include "arch/i386/include/string.h"

uint8_t Terminal::vga_entry(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

void Terminal::init() {
    cursor_x = 0;
    cursor_y = 0;
    color = vga_entry(VGA_COLOR_BLUE, VGA_COLOR_CYAN);

    unsigned char* _video_memory = video_memory;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *_video_memory = ' ';
        *(_video_memory+1) = color;
        _video_memory += 2;
    }
}

void Terminal::putchar(char c) {
    if (c == '\n' || c == '\r')
    {
        cursor_x = 0;
        cursor_y++;

    }
    else
    {
        unsigned int position = cursor_y * VGA_WIDTH + cursor_x;
        unsigned char* memory = video_memory + position*2;
        *memory = c;
        *(memory+1) = color;
        cursor_x++;
        if (cursor_x == VGA_WIDTH)
        {
            cursor_x = 0;
            cursor_y++;
        }
    }

    if (cursor_y == VGA_HEIGHT) {
        memmove(video_memory, video_memory + (VGA_WIDTH * 2), (VGA_WIDTH * (VGA_HEIGHT - 1)) * 2);
        memset(video_memory + ((VGA_WIDTH * (VGA_HEIGHT - 1)) * 2), 0, VGA_WIDTH * 2);
        cursor_y--;
    }
}
void Terminal::set_pos(int x, int y) {
    cursor_x = x;
    cursor_y = y;
}

void Terminal::print(const char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len; i++)
    {
        putchar(str[i]);
    }
}

void Terminal::println(const char *str) {
    print(str);
    putchar('\n');
}

void Terminal::linebreak() {
    for(uint8_t i = 0; i < 80; i++) {
        print("-");
    }
}

void Terminal::cls(void) {
    unsigned char* _video_memory = video_memory;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *_video_memory = ' ';
        *(_video_memory+1) = color;
        _video_memory += 2;
    }
    cursor_x = 0;
    cursor_y = 0;
}
