#include "Bank.hpp"

Bank::Bank(int liquidity){
     std::cout << "Bank constructor Called"<<  std::endl; 
    this->Liquidity = liquidity;
}
Bank::~Bank(){
    std::cout << "Bank destructor Called" << std::endl;
}
const int& Bank::getLiquidity()const {
    return(this->Liquidity);
}
int Bank::checkIds(int id){
    for(int i = 0; i < this->Clients.size(); i++){
        if(this->Clients[i].getId() == id)
            return(1);
        i++;
    }
    return(0);
}
void Bank::createNewAccount(){
    int Id = rand();
    if(this->checkIds(Id)){
        std::cout << "Account Id already exists" << std::endl;
        this->Clients.push_back(Id + 7);
    }
    else{
        this->Clients.push_back(Account(Id));
    }
}