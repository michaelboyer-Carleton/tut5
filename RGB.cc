#include "RGB.h"

using namespace std;

RGB::RGB(int red, int green, int blue) {
    r = red;
    g = green;
    b = blue;
}

RGB::RGB(CuColour colour) {
    RGB::setColour(colour);
}

RGB::RGB() {
    r = 0;
    g = 0;
    b = 0;
}

int RGB::getR() const {
    return r;
}
int RGB::getG() const {
    return g;
}
int RGB::getB() const {
    return b;
}

CuColour RGB::getColour() const {

    CuColour colour = (r << 16) + (g << 8) + b;
    return colour;
}

void RGB::setR(int red) {
    r = red;
}

void RGB::setG(int green) {
    g = green;
}

void RGB::setB(int blue) {
    b = blue;
}

void RGB::setColour(CuColour colour) {

    r = colour >> 16;
    g = (colour & 0x00FF00) >> 8;
    b = colour & 0x0000FF;

}

RGB RGB::WHITE() {
    return RGB(255, 255, 255);
}

RGB RGB::BLACK() {
    return RGB(0, 0, 0);
}

RGB RGB::RED() {
    return RGB(255, 0, 0);
}

RGB RGB::GREEN() {
    return RGB(0, 255, 0);
}

RGB RGB::BLUE() {
    return RGB(0, 0, 255);
}