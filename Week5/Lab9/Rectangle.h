#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle();
    Rectangle(double l, double w);
    void setLength(double l);
    void setWidth(double w);
    double getLength() const;
    double getWidth() const;
    double getArea() const;
};

#endif