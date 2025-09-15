#include "Bank.hpp"


int main() {
    srand(time(NULL));

    try {
        Bank b(120000);

        int ac1 = b.createNewAccount(200);
        int ac2 = b.createNewAccount(200);

        b.deleteAccount(ac1);

        b.addLoan(ac1, 200);     
        b.addLoan(ac2, 130002);  

        int ac3 = b.createNewAccount(200000);
        b.addLoan(ac3, 5000);

    } catch (const std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}