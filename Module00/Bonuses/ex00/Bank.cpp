#include "Bank.hpp"

Bank::Bank(int liquidity){
     std::cout << "Bank constructor Called"<<  std::endl;
    this->Liquidity = liquidity;
}

Bank::~Bank()
{
    std::cout << "Bank destructor Called" << std::endl;

    for(std::map<int, Account *>::iterator it = this->Clients.begin(); it != this->Clients.end(); it++)
        delete(it->second);
    this->Clients.clear();
}

Account* Bank::operator[](int id)
{
    std::map<int, Account *>::iterator it = this->Clients.find(id);
    if(it == this->Clients.end())
        throw std::runtime_error("id not found");
    return it->second;    
}
int Bank::deleteAccount(int id)
{
    std::map<int, Account *>::iterator it = this->Clients.find(id);
    if (it != this->Clients.end())
    {
        delete(it->second);
        this->Clients.erase(id);
        return(0);
    }
      else
        throw std::runtime_error("Id not found");
}

const int& Bank::getLiquidity()const {
    return(this->Liquidity);
}

 int Bank::checkId(int id)
{
    std::map<int, Account *>::iterator it = this->Clients.find(id);
    if (it != this->Clients.end())
    {
        id = rand() % 1000;
        return checkId(id);
    }
    return(id);
}

int Bank::createNewAccount(int value) {
    int id = checkId(rand() % 1000);
    int commission;
    commission = (value * 5) / 100;
    int finalValue = value - commission;
       if (finalValue <= 0)
        throw std::runtime_error("Insufficient funds to create account after commission.");
    this->Liquidity += commission;
    std::cout << "a commission of  " << commission << " is added to bank " << std::endl;
        this->Clients.insert(std::make_pair(id, new Account(id, finalValue)));
    return(id);
}

void Bank::addLoan(int id, int value){

     if(this->Liquidity < value)
        throw std::runtime_error("cannot afford this sum of loan.");
    
            Account *client = (*this)[id]; 
            int exValue = client->getValue();
            int newValue = exValue + value;
           this->deleteAccount(id);
           this->Clients.insert(std::make_pair(id, new Account(id, newValue)));
}