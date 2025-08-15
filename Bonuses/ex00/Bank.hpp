#include <iostream>
#include <string>
#include "Account.hpp"
#include <vector>
#include <cstdlib>
#include <map>

class Bank{
    private:
        int Liquidity;
        std::map<int, Account *> Clients;
    public:
         Bank(int liquidity);
        ~Bank();
        void setLiquidity(int l);
        int checkId(int id);
        const int &getLiquidity()const;
        int createNewAccount(int value);
        int deleteAccount(int id);
        Account* operator[](int id);
        void addLoan(int id, int value);   

};