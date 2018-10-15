//
// Created by Mitch Holyoak on 10/15/18.
//

#include "Shape.h"

#include <iostream>

Shape::Shape()
{
    //std::cout << "Construct Shape " << std::to_string(uint64_t(this)) << std::endl;
}

Shape::~Shape()
{
    //std::cout << "Destruct Shape " << std::to_string(uint64_t(this)) << std::endl;
}

int Shape::GetHeight() const
{
    return _height;
}

void Shape::SetHeight(int height)
{
    _height = height;
}

int Shape::GetWidth() const
{
    return _width;
}

void Shape::SetWidth(int width)
{
    _width = width;
}

int Shape::GetArea() const
{
    return _width * _height;
}
