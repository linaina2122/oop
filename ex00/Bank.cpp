#include "Bank.hpp"

Bank::Bank(int liquidity){
     std::cout << "Bank constructor Called"<<  std::endl;
    this->Liquidity = liquidity;
}
Bank::~Bank()
{
    std::cout << "Bank destructor Called" << std::endl;
}
const int& Bank::getLiquidity()const {
    return(this->Liquidity);
}

int Bank::deleteAccount(int id)
{
    for(int i = 0; i < this->Clients.size();i++){
        if(this->Clients[i].getId() == id){
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
    for(int i = 0; i < this->Clients.size(); i++){
        if(this->Clients[i].getId() == id)
            return(1);
    }
    return (0);
}

void Bank::createNewAccount( int value) {
    int id = rand(); 
    int commission;
    while(this->isTaken(id))
    {
        std::cout << "Id " << id << " already exists " << std::endl;
        id = rand();
    }
    commission = (value * 5) / 100;
    int finalValue = value - commission;
    if( finalValue <= 0) {
        std::cout << "Insufficient funds to create account." << std::endl;
        return;
    }
    this->Liquidity += commission;
    this->Clients.push_back(Account(id, finalValue));
}

void Bank::addLoan(int id, int value){

    for(int i = 0; i < this->Clients.size(); i++)
    {
        if (this->Clients[i].getId() == id)
        {
            if(this->Liquidity < value)
            {
                std::cout << "sorry, can't afford a loan of " << value  << std::endl;
                return;
            }
            this->Clients[i].addValue(value);
            return ;
        }
    }
    std::cout << "Account not found, please ch  eck your Id's account" << std::endl;
}