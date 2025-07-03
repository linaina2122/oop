
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
        void createNewAccount();
        int checkIds(int id);
        void addToAccount(Account client);
        void deleteAccount(Account client);
        void addLoan(Account client, int value);
        

        
};