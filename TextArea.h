#ifndef TEXTAREA_H
#define TEXTAREA_H

#include <string>
#include <iostream>
#include <X11/Xlib.h>

#include "RGB.h"


using namespace std;

class TextArea {

    public:

        TextArea(int x, int y, int width, int height, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(Rectangle rect, string id, string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());

        void draw(Display *display, Window& win, GC& gc, int& parentX, int& parentY) const;
        bool overlaps(const TextArea& ta) const;

        void setFill(RGB newFill);
        void setBorder(RGB newBorder);

        string getId() const;
        Rectangle getDimensions() const;
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        RGB getFill() const;
        RGB getBorder() const;

        void print() const;

    private:


        Rectangle dimensions;

        string text;

        // id
        string id;

        RGB fill;
        RGB border;

};


#endif