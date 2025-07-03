#include "Bank.hpp"

Account::Account(int id){
    this->Id = id;
    std::cout << "new account created : " << this->Id << std::endl;
}
Account::~Account( ){
    std::cout << "";
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
