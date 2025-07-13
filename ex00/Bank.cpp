#include "Bank.hpp"

Bank::Bank(int liquidity){
     std::cout << "Bank constructor Called"<<  std::endl;
    this->Liquidity = liquidity;
}
Bank::~Bank()
{
    std::cout << "Bank destructor Called" << std::endl;
    int len = this->Clients.size();
    for(int i = 0 ; i < len; i++){
        delete(this->Clients[i]);
    }
    this->Clients.clear();
}
const int& Bank::getLiquidity()const {
    return(this->Liquidity);
}

int Bank::deleteAccount(int id)
{
     int len = this->Clients.size();
    for(int i = 0; i < len;i++){
        if(this->Clients[i]->getId() == id){
            delete(this->Clients[i]);
            this->Clients.erase(this->Clients.begin() + i);
            std::cout << "Account with ID " << id << " deleted." << std::endl;
            return(1);
        }
    }
      std::cout << "No account  with ID " << id << " was found " << std::endl;
    return(0);
}

int Bank::isTaken(int id)
{
     int len = this->Clients.size();
    for(int i = 0; i < len;i++){
        if(this->Clients[i]->getId() == id)
            return(1);
    }
    return (0);
}

int Bank::createNewAccount( int value) {
    int id = rand() % 1000; 
    int commission;
    while(this->isTaken(id))
    {
        std::cout << "Id " << id << " already exists " << std::endl;
        id = rand() % 1000;
    }
    commission = (value * 5) / 100;
    int finalValue = value - commission;
    if( finalValue <= 0) {
        std::cout << "Insufficient funds to create account." << std::endl;
        return -1;
    }
    this->Liquidity += commission;
    std::cout << "a commission of  " << commission << "is added to bank " << std::endl;
    this->Clients.push_back(new Account(id, finalValue));
    return(id);
}

void Bank::addLoan(int id, int value){

    int len = this->Clients.size();
    for(int i = 0; i < len;i++)
    {
    {
        if (this->Clients[i]->getId() == id)
        {
            if(this->Liquidity < value)
            {
                std::cout << "sorry, can't afford a loan of " << value  << std::endl;
                return;
            }
            this->Clients[i]->addValue(value);
            std::cout << "loan of sum " << value << " is added successfuly to account " << id << std::endl;
            return ;
        }
    }
    }
    std::cout << "Account not found, please check your Id's account" << std::endl;
}