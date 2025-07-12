#include "Bank.hpp"

Account::Account(int id, int value){
    this->Id = id;
    this->Value = value;
    std::cout << "new account created : " << this->Id << std::endl;
}
Account::~Account(){
    std::cout << "Account destrcutor called" << std::endl;
}
void Account::setId(int id){
    this->Id = id;
}
const int& Account::getId()const{
    return(this->Id);
}
const int& Account::getValue() const {
    return (this->Value);
}

void Account::addValue(int value) {
    this->Value += value;
}