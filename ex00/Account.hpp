#include <iostream>
#include <string>

class Account {
    private :
        int Id;
        int Value;
    public :
         Account(int id);
        ~Account();
        void setId(int id);
        void setValue(int value);
         const int &getId ()const ;
         const int &getValue ()const ;
};

