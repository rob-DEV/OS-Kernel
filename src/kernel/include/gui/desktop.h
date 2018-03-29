//
// Created by dev on 28/03/18.
//

#ifndef OS_DESKTOP_H
#define OS_DESKTOP_H

#include <common/types.h>
#include <common/graphicscontext.h>
#include <drivers/vga.h>
#include <gui/widget.h>

using namespace OS::Common;

namespace OS { namespace GUI {

    class Desktop : public CompositeWidget{
    private:
        uint32_t MouseX, MouseY;
    public:
        Desktop(int32_t w, int32_t h, RGB_Color color);
        ~Desktop();

        void Draw(GraphicsContext* gc);

        void OnMouseDown(uint8_t button);
        void OnMouseUp(uint8_t button);
        void OnMouseMove(int x, int y);
    };

} }

#endif //OS_DESKTOP_H
