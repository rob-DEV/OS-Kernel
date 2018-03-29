//
// Created by dev on 28/03/18.
//

#include <gui/widget.h>
namespace OS { namespace GUI {

Widget::Widget(Widget* parent, int32_t x, int32_t y, int32_t w, int32_t h, Common::RGB_Color& color){

    this->parent = parent;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->color = color;

    //
    canFocus = true;
}

Widget::~Widget() { }

void Widget::GetFocus(Widget *widget){
    if(parent != NULL)
        parent->GetFocus(widget);
}

void Widget::ModelToScreen(int32_t &x, int32_t &y){
    if(parent != NULL)
        parent->ModelToScreen(x,y);

    x += this->x;
    y += this->y;
}

void Widget::Draw(GraphicsContext *gc){
    int32_t X = 0;
    int32_t Y = 0;
    ModelToScreen(X,Y);
    gc->FillRectangle(X,Y,w,h, color);
}

bool Widget::ContainsCoordinate(int32_t x, int32_t y)
{
    return this->x <= x && x < this->x + this->w
           && this->y <= y && y < this->y + this->h;
}

void Widget::OnMouseDown(int32_t x, int32_t y){
    if(canFocus)
       GetFocus(this);
}

void Widget::OnMouseUp(int32_t x, int32_t y){

}

void Widget::OnMouseMove(int32_t old_x, int32_t old_y, int32_t new_x, int32_t new_y){

}

void Widget::OnKeyDown(int32_t x, int32_t y){

}

void Widget::OnKeyUp(int32_t x, int32_t y){

}





CompositeWidget::CompositeWidget(Widget *parent, int32_t x, int32_t y, int32_t w, int32_t h, Common::RGB_Color color) :
    Widget(parent,x,y,w,h,color)
{
    focussedChild = NULL;
    numChildren = 0;
}

CompositeWidget::~CompositeWidget() {

}

void CompositeWidget::GetFocus(Widget* widget) {
    this->focussedChild = widget;
    if(parent != NULL)
        parent->GetFocus(this);
}

bool CompositeWidget::AddChild(Widget* child)
{
    if(numChildren >= 100)
        return false;
    children[numChildren++] = child;
    return true;
}

void CompositeWidget::Draw(GraphicsContext* gc) {
    Widget::Draw(gc);
    for(int i = numChildren-1; i >= 0; --i)
        children[i]->Draw(gc);
}

void CompositeWidget::OnMouseDown(int32_t x, int32_t y) {

}

void CompositeWidget::OnMouseUp(int32_t x, int32_t y) {

}

void CompositeWidget::OnMouseMove(int32_t old_x, int32_t old_y, int32_t new_x, int32_t new_y) {

}

void CompositeWidget::OnKeyDown(int32_t x, int32_t y) {

}

void CompositeWidget::OnKeyUp(int32_t x, int32_t y) {

}


} }