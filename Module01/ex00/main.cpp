#include "ex00.hpp"


int main()
{
    Worker worker1;
    Worker worker2;
    Shovel sh;

    sh.setNumberOfUses(3);
    worker1.setShovel(&sh);
    worker1.getShovel()->use(); 
    worker2.setShovel(&sh);  
    if (worker1.getShovel() != NULL)
        worker1.getShovel()->use(); 
    worker2.getShovel()->use();
}
