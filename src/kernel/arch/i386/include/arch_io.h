//
// Created by dev on 22/03/18.
//

#ifndef OS_ARCH_IO_H
#define OS_ARCH_IO_H

unsigned char inportb (unsigned short _port);

void outportb (unsigned short _port, unsigned char _data);

#endif //OS_ARCH_IO_H
