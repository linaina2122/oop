#include "Vector2.hpp"

Vector2::Vector2()
{
    std::cout << "constructor called" << std::endl;
}

Vector2::~Vector2()
{
    std::cout << "destructor called" << std::endl;
}

void Vector2::setX(float X)
{
    this->x = X;
}

void Vector2::setY(float Y)
{
    this->y = Y;
}

const float &Vector2::getX() const 
{
    return(this->x);
}

const float &Vector2::getY() const 
{
    return(this->y);
} 

