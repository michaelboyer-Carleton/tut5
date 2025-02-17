#include "TextArea.h"


TextArea::TextArea(int x, int y, int width, int height, string id, string label, RGB fill, RGB border) {

    this->dimensions = Rectangle();
    this->dimensions.x = x;
    this->dimensions.y = y;
    this->dimensions.width = width;
    this->dimensions.height = height;

    this->id = id;
    this->fill = fill;
    this->border = border;

}

TextArea::TextArea(Rectangle rect, string id, string label, RGB fill, RGB border) {

    this->dimensions = rect;
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;

}

void TextArea::setFill(RGB newFill) {
    this->fill = newFill;
}

void TextArea::setBorder(RGB newBorder) {
    this->border = newBorder;
}

void TextArea::draw(Display *display, Window& win, GC& gc, int& parentX, int& parentY) const {

    XSetForeground(display, gc, this->fill.getColour());
    // XFillRectangle(display, win, gc, parentX + this->x, parentY + this->y, this->width, this->height);

    XSetForeground(display, gc, this->border.getColour());

    XDrawString(
        display, win, gc, 
        parentX + this->getX(),
        parentY + this->getY(), 
        this->text.data(), 
        sizeof(this->text.data())
    );

    XFlush(display);

}

bool TextArea::overlaps(const TextArea& ta) const {

    return this->dimensions.overlaps(ta.getDimensions());

}

Rectangle TextArea::getDimensions() const {
    return this->dimensions;
}

int TextArea::getX() const {
    return this->dimensions.x;
}

int TextArea::getY() const {
    return this->dimensions.y;
}

int TextArea::getWidth() const {
    return this->dimensions.width;
}

int TextArea::getHeight() const {
    return this->dimensions.height;
}

string TextArea::getId() const {
    return this->id;
}

RGB TextArea::getFill() const {
    return this->fill;
}

RGB TextArea::getBorder() const {
    return this->border;
}

void TextArea::print() const {

    cout << "Button:\t" << this->id << endl;
    cout << "Pos:\t" << this->getX() << ", " << this->getY() << endl;
    cout << "Size:\t" << this->getWidth() << ", " << this->getHeight() << endl;
    cout << "text:\t" << this->text << endl;

}