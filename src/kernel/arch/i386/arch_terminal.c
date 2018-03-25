//
// Created by dev on 19/03/18.
//

#include "include/arch_string.h"
#include "include/arch_io.h"
#include "include/arch_terminal.h"

const uint16_t VGA_WIDTH = 80;
const uint16_t VGA_HEIGHT = 25;
unsigned char*  VGA_MEMORY = (unsigned char*)0xb8000;


static size_t terminal_cur_x;
static size_t terminal_cur_y;
static uint8_t terminal_color;
unsigned char*  terminal_buffer;


uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) {
    return fg | bg << 4;
}
void print(const char *str) {
    int len = strlen(str);
    int i;
    for(i = 0; i < len; i++)
    {
        putch(str[i]);
    }
}
void move_csr(void) {
    unsigned temp;

    /* The equation for finding the index in a linear
    *  chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    temp = terminal_cur_y * 80 + terminal_cur_x;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking'. To
    *  learn more, you should look up some VGA specific
    *  programming documents. A great start to graphics:
    *  http://www.brackeen.com/home/vga */
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

/* These define our textpointer, our background and foreground
*  colors (attributes), and x and y cursor coordinates */
unsigned short *textmemptr;
int attrib = 0x0F;
int csr_x = 0, csr_y = 0;

void scroll(void)
{
    unsigned blank, temp;

    /* A blank is defined as a space... we need to give it
    *  backcolor too */
    blank = 0x20 | (attrib << 8);

    /* Row 25 is the end, this means we need to scroll up */
    if(csr_y >= 25)
    {
        /* Move the current text chunk that makes up the screen
        *  back in the buffer by a line */
        temp = csr_y - 25 + 1;
        memcpy (textmemptr, textmemptr + temp * 80, (25 - temp) * 80 * 2);

        /* Finally, we set the chunk of memory that occupies
        *  the last line of text to our 'blank' character */
        memsetw (textmemptr + (25 - temp) * 80, blank, 80);
        csr_y = 25 - 1;
    }
}

void init_terminal(void) {
    terminal_cur_x = 0;
    terminal_cur_y = 0;
    terminal_color = vga_entry_color(VGA_COLOR_WHITE, VGA_COLOR_BLACK);
    cls();
}
void set_video_color(enum vga_color fg, enum vga_color bg) {

    terminal_color = vga_entry_color(fg, bg);
    cls();
}
int putch(char c) {
    if (c == '\n' || c == '\r')
    {
        terminal_cur_x = 0;
        terminal_cur_y++;

    }
    else
    {
        unsigned int position = terminal_cur_y * VGA_WIDTH + terminal_cur_x;
        unsigned char*  memory = VGA_MEMORY + position*2;
        *memory = c;
        *(memory+1) = terminal_color;
        terminal_cur_x++;
        if (terminal_cur_x == VGA_WIDTH)
        {
            terminal_cur_x = 0;
            terminal_cur_y++;
        }
    }

    if (terminal_cur_y == VGA_HEIGHT) {
        memmove(VGA_MEMORY, VGA_MEMORY + (VGA_WIDTH * 2), (VGA_WIDTH * (VGA_HEIGHT - 1)) * 2);
        memset(VGA_MEMORY + ((VGA_WIDTH * (VGA_HEIGHT - 1)) * 2), 0, VGA_WIDTH * 2);
        terminal_cur_y--;
    }
    scroll();
    move_csr();
    return 0;
}
void puts(const char *str) {
    print(str);
}
void linebreak(void) {
    for(uint8_t i = 0; i < 80; i++) {
        print("-");
    }
}
void cls(void) {
    unsigned char* _video_memory = VGA_MEMORY;
    for (int i = 0; i < VGA_WIDTH * VGA_HEIGHT; i++) {
        *_video_memory = ' ';
        *(_video_memory+1) = terminal_color;
        _video_memory += 2;
    }
    terminal_cur_x = 0;
    terminal_cur_y = 0;
    move_csr();
}


