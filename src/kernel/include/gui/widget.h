//
// Created by dev on 28/03/18.
//

#ifndef OS_WIDGET_H
#define OS_WIDGET_H

#include <common/types.h>
#include <common/graphicscontext.h>
#include <drivers/vga.h>


namespace OS { namespace GUI {
    class Widget {
    protected:
        Widget* parent;
        int32_t x;
        int32_t y;
        int32_t w;
        int32_t h;

        Common::RGB_Color color;

        bool canFocus;

    public:
        Widget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, Common::RGB_Color& color);
        ~Widget();
        virtual void GetFocus(Widget* widget);
        virtual void ModelToScreen(int32_t &x, int32_t &y);
        virtual bool ContainsCoordinate(int32_t x, int32_t y);

        virtual void Draw(GraphicsContext* gc);
        virtual void OnMouseDown(int32_t x, int32_t y);
        virtual void OnMouseUp(int32_t x, int32_t y);
        virtual void OnMouseMove(int32_t old_x, int32_t old_y, int32_t new_x, int32_t new_y);

        virtual void OnKeyDown(int32_t x, int32_t y);
        virtual void OnKeyUp(int32_t x, int32_t y);
    };

    class CompositeWidget : public Widget {
    private:
        Widget* children[100];
        uint32_t numChildren;
        Widget* focussedChild;

        Common::RGB_Color color;

        bool canFocus;

    public:
        CompositeWidget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, Common::RGB_Color color);
        ~CompositeWidget();

        virtual void GetFocus(Widget* widget);
        virtual bool AddChild(Widget* child);

        virtual void Draw(GraphicsContext* gc);
        virtual void OnMouseDown(int32_t x, int32_t y);
        virtual void OnMouseUp(int32_t x, int32_t y);
        virtual void OnMouseMove(int32_t old_x, int32_t old_y, int32_t new_x, int32_t new_y);

        virtual void OnKeyDown(int32_t x, int32_t y);
        virtual void OnKeyUp(int32_t x, int32_t y);
};

} }

#endif //OS_WIDGET_H
