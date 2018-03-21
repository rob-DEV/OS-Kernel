//
// Created by dev on 19/03/18.
//

#include "include/terminal.h"
#include "include/mem_util.h"
#include "include/string.h"

const uint16_t VGA_WIDTH = 80;
const uint16_t VGA_HEIGHT = 25;
unsigned char*  VGA_MEMORY = (unsigned char*)0xb8000;


static size_t terminal_row;
static size_t terminal_column;
static uint8_t terminal_color;
unsigned char*  terminal_buffer;


uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

uint16_t vga_entry(unsigned char uc, uint8_t color) {
    return (uint16_t) uc | (uint16_t) color << 8;
}


void terminal_initialize(void) {
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_CYAN);

    terminal_buffer = VGA_MEMORY;
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }

}

void terminal_putchar(char c) {
    if (c == '\n' || c == '\r')
    {
        terminal_row = 0;
        terminal_column++;

    }
    else
    {
        unsigned int position = terminal_column * VGA_WIDTH + terminal_row;
        unsigned char*  memory = VGA_MEMORY + position*2;
        *memory = c;
        *(memory+1) = terminal_color;
        terminal_row++;
        if (terminal_row == VGA_WIDTH)
        {
            terminal_row = 0;
            terminal_column++;
        }
    }

    if (terminal_column == VGA_HEIGHT) {
        memmove(VGA_MEMORY, VGA_MEMORY + (VGA_WIDTH * 2), (VGA_WIDTH * (VGA_HEIGHT - 1)) * 2);
        memset(VGA_MEMORY + ((VGA_WIDTH * (VGA_HEIGHT - 1)) * 2), 0, VGA_WIDTH * 2);
        terminal_column--;
    }
}

void print(const char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len; i++)
    {
        terminal_putchar(str[i]);
    }
}
void terminal_write(const char *str) {
    print(str);
}
void terminal_writeline(const char *str) {
    print(str);
    terminal_putchar('\n');
}

void terminal_clearscreen(void) {
    unsigned char* _video_memory = VGA_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *_video_memory = ' ';
        *(_video_memory+1) = terminal_color;
        _video_memory += 2;
    }
    terminal_row = 0;
    terminal_column = 0;
}

void terminal_linkbreak(void) {
    for(uint8_t i = 0; i < 80; i++) {
        print("-");
    }
}

