//
// Created by dev on 27/03/18.
//

#ifndef OS_VGA_H
#define OS_VGA_H

#include <system.h>
#include "../hardwarecommunication/port.h"

namespace OS { namespace Drivers {

    class VideoGraphicsArray{
    protected:
        HW_COMM::Port8Bit miscPort;
        HW_COMM::Port8Bit crtcIndexPort;
        HW_COMM::Port8Bit crtcDataPort;
        HW_COMM::Port8Bit sequencerIndexPort;
        HW_COMM::Port8Bit sequencerDataPort;
        HW_COMM::Port8Bit graphicsControllerIndexPort;
        HW_COMM::Port8Bit graphicsControllerDataPort;
        HW_COMM::Port8Bit attributeControllerIndexPort;
        HW_COMM::Port8Bit attributeControllerReadPort;
        HW_COMM::Port8Bit attributeControllerWritePort;
        HW_COMM::Port8Bit attributeControllerResetPort;

        void WriteRegisters(uint8_t* registers);
        uint8_t* GetFrameBufferSegment();

        virtual uint8_t GetColorIndex(uint8_t r, uint8_t g, uint8_t b);

    public:
        VideoGraphicsArray();


        virtual bool SupportMode(uint32_t width, uint32_t height, uint32_t colorDepth);
        virtual bool SetMode(uint32_t width, uint32_t height, uint32_t colorDepth);
        virtual void PutPixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b);
        virtual void PutPixel(uint32_t x, uint32_t y, uint8_t colorIndex);
    };

} }


#endif //OS_VGA_H
