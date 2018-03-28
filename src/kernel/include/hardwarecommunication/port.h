//
// Created by dev on 27/03/18.
//

#ifndef OS_HW_COMM_PORT_H
#define OS_HW_COMM_PORT_H

#include <common/types.h>

namespace OS { namespace HW_COMM {
    class Port {
    protected:
        Port(uint16_t portnumber);
        ~Port();
        uint32_t portnumber;
    };


    class Port8Bit : public Port {
    public:
        Port8Bit(uint16_t portnumber);
        ~Port8Bit();

        virtual uint8_t Read();
        virtual void Write(uint8_t data);

    protected:
        static inline uint8_t Read8(uint16_t _portnumber)
        {
            uint8_t result;
            __asm__ volatile("inb %1, %0" : "=a" (result) : "Nd" (_portnumber));
            return result;
        }

        static inline void Write8(uint16_t _port, uint8_t _data)
        {
            __asm__ volatile("outb %0, %1" : : "a" (_data), "Nd" (_port));
        }
    };
} }

#endif //OS_HW_COMM_PORT_H
