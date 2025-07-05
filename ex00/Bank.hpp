
#include <iostream>
#include <string>
#include "Account.hpp"
#include <vector>
#include <cstdlib>

class Bank{
    private:
        int Liquidity;
        int Id;
       std::vector<Account> Clients;
    public:
         Bank(int liquidity);
        ~Bank();
        void setLiquidity(int l);
        const int &getLiquidity()const;
        void createNewAccount(int value);
        void addToAccount(Account client);
        int deleteAccount(Account client);
        int checkId(int id);
        void addLoan(Account client, int value);
        

        
};