#include <iostream>
#include <string>

class Account {
    private :
        int Id;
        int Value;
    public :
         Account(int id, int value);
        ~Account();
        void setId(int id);
         const int &getId ()const ;
         const int &getValue ()const ;
};

