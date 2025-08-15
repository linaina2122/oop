#include "Bank.hpp"

Account::Account(int id, int value) : Id(id), Value(value)
{
    std::cout << "new account created : " << this->Id << std::endl;
}

Account::~Account()
{
    std::cout << "Account destrcutor called" << std::endl;
}

const int& Account::getId()const
{
    return(this->Id);
}

const int& Account::getValue() const
{
    return (this->Value);
}