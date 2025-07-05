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
int Bank::deleteAccount(Account client) {
    int id = client.getId();
    for(int i = 0; i < this->Clients.size();i++){
        if(this->Clients[i].getId() == id){
            this->Liquidity -= (this->Clients[i].getValue() * 5) / 100;
            this->Clients.erase(this->Clients.begin() + i);
            std::cout << "Account with ID " << id << " deleted." << std::endl;
            return(1);
        }
    }
      std::cout << "No account  with ID " << id << " was found " << std::endl;
    return(0);
}
void Bank::createNewAccount(int value) {
    int Id = this->Clients.size() + 1;
    for(int i = 0; i < this->Clients.size(); i++){
        if(this->Clients[i].getId() == Id){
        }
    }
    int finalValue = value - (value * 5) / 100;
    if( finalValue <= 0) {
        std::cout << "Insufficient funds to create account." << std::endl;
        return;
    }
    this->Liquidity += finalValue;
    this->Clients.push_back(Account(Id, finalValue));
}