
#include <iostream>
#include <string>
#include "Account.hpp"
#include <vector>
#include <cstdlib>

class Bank{
    private:
        int Liquidity;
       std::vector<Account *> Clients;
    public:
         Bank(int liquidity);
        ~Bank();
        void setLiquidity(int l);
        const int &getLiquidity()const;
        int createNewAccount(int value);
        int deleteAccount(int id);
        int isTaken(int id);
        void addLoan(int id, int value);   
};