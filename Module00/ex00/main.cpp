#include "Bank.hpp"

int main(){

    srand(time(NULL));
    Bank b(120000);
    int ac1 = b.createNewAccount(200);
    int ac2 = b.createNewAccount(200);
    b.deleteAccount(ac1);
    b.addLoan(ac1, 200);
    b.addLoan(ac2, 130002);
    int ac3 =  b.createNewAccount(200000);
    b.addLoan(ac3, 5000);

    return (0);
}