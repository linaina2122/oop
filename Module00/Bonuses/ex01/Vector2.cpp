#include "Vector2.hpp"

Vector2::Vector2(float X, float Y) : x(X), y(Y)
{
    std::cout << "constructor called" << std::endl;
}
Vector2::Vector2()
{
}
Vector2::~Vector2()
{
    std::cout << "destructor called" << std::endl;
}

const float &Vector2::getX() const 
{
    return(this->x);
}

const float &Vector2::getY() const 
{
    return(this->y);
}
