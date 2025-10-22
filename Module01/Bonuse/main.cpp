#include "ex00.hpp"

int main() {
    // --- Create workers ---
    Worker* worker1 = new Worker();
    Worker* worker2 = new Worker();

    // --- Set worker positions and stats ---
    Position pos1 = {0, 1, 2};
    Statistic stat1 = {5, 100};
    worker1->setCoordonee(pos1);
    worker1->setStat(stat1);

    Position pos2 = {3, 4, 5};
    Statistic stat2 = {2, 50};
    worker2->setCoordonee(pos2);
    worker2->setStat(stat2);

    // --- Create tools ---
    Shovel* shovel1 = new Shovel();
    shovel1->setNumberOfUses(3); // Shovel can be used 3 times

    Hammer* hammer1 = new Hammer();
    hammer1->setNumberOfTools(5); // Hammer can be used 5 times

    // --- Assign tools to workers ---
    worker1->setShovel(shovel1);  // Assign shovel to worker1
    worker1->addTools(hammer1);   // Assign hammer to worker1

    // Transfer hammer to worker2 to test tool transfer
    worker2->addTools(hammer1);

    // --- Create workshops ---
    Workshop* workshop1 = new Workshop();
    Workshop* workshop2 = new Workshop();

    // --- Register workers to workshops ---
    worker1->registerToWorkShop(workshop1);
    worker1->registerToWorkShop(workshop2);
    worker2->registerToWorkShop(workshop1);

    // --- Sign up workers in workshops ---
    workshop1->signUp(worker1);
    workshop1->signUp(worker2);
    workshop2->signUp(worker1);

    // --- Execute workdays ---
    std::cout << "\n--- Workshop 1 Workday (all workers) ---" << std::endl;
    workshop1->executeWorkDay(NULL); // all workers in workshop1

    std::cout << "\n--- Workshop 2 Workday (specific worker) ---" << std::endl;
    workshop2->executeWorkDay(worker1); // only worker1

    // --- Use shovel manually ---
    std::cout << "\n--- Worker1 using shovel ---" << std::endl;
    shovel1->use(); // use 1
    shovel1->use(); // use 2
    shovel1->use(); // use 3 (should reach 0 uses)

    // --- Clean up ---
    delete worker1;
    delete worker2;
    delete shovel1;
    delete hammer1;
    delete workshop1;
    delete workshop2;

    return 0;
}

