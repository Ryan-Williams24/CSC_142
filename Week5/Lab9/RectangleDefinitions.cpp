#include "Rectangle.h"

Rectangle::Rectangle() : length(0.0), width(0.0) {}

Rectangle::Rectangle(double l, double w) : length(l), width(w) {}

void Rectangle::setLength(double l) { length = l; }

void Rectangle::setWidth(double w) { width = w; }

double Rectangle::getLength() const { return length; }

double Rectangle::getWidth() const { return width; }

double Rectangle::getArea() const { return length * width; }