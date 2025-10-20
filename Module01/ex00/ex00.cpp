

#include "ex00.hpp"

Worker::Worker() {
    std::cout << "Worker constructor called." << std::endl;
}

Worker::~Worker() {
    std::cout << "Worker destructor called ." << std::endl;
}

void Worker::setCoordonee(Position coord) {
    coordonee = coord;
}

Position Worker::getCoordonee() {
    return coordonee;
}

void Worker::setStat(Statistics s) {
    stat = s;
}

Statistics Worker::getStatistics() {
    return stat;
}

void Worker::setShovel(Shovel* s) 
{
    if(this->sh == s) // if the shovel already exists , do nothing 
        return;
    //check if this shovel is not set to null and has a worker and set it to null 
    if(s != NULL && s->getWorker() != NULL)
        s->getWorker()->setShovel(NULL);
        
    this->sh = s;
    if(s != NULL)
        s->setWorker(this); // set shovel to the current worker 
}

Shovel* Worker::getShovel() const 
{
    return (this->sh);
}

std::vector<Tool*> Worker::getTools() const
{
    return(this->tools);
}

// ----------------------------------------------

Shovel::Shovel()
{
    std::cout << "Shovel constructor called" << std::endl;
}

int Shovel::getNumberOfUses() const // to project the object of been changed 
{
    return (this->numberOfUses);
}

Shovel::~Shovel()
{
    std::cout << "Shovel destructor Called" << std::endl;
}

void Shovel::setWorker(Worker *wor)
{
    this->worker = wor;
}

Worker* Shovel::getWorker() const
{
    return (this->worker);
}
void Shovel::setNumberOfUses(int n) 
{
    this->numberOfUses = n;
}
void Shovel::use() 
{
    if(this->worker == NULL)
    {
        std::cout << "this worker can't use the Shovel more" << std::endl;
        return ;
    }
    if(this->numberOfUses  > 0 && this->worker != NULL)
    {
        this->numberOfUses--;
        std::cout << "Shovel is used once.number of uses =  " << this->numberOfUses  << std::endl;
    } 
    if(this->numberOfUses == 0)
    {
        std::cout << "number of uses is 0" << std::endl;
        this->worker->setShovel(NULL);
        this->worker = NULL;
        return ;
    }
}

void Worker::addTools(Tool* tool) {
    if (!tool) {
        std::cout << "Cannot add a null tool." << std::endl;
        return;
    }

    Worker* previousOwner = tool->getWorker();
    if (previousOwner && previousOwner != this) {
        std::cout << "Tool already belongs to another worker. Transferring..." << std::endl;
        previousOwner->deleteTools(tool);
    }

    tool->setWorker(this);
    tools.push_back(tool);

    std::cout << "Tool added to worker successfully." << std::endl;
}

void Worker::deleteTools(Tool* tool) {
    if (!tool) {
        std::cout << "Cannot delete a null tool." << std::endl;
        return;
    }

    for (auto it = tools.begin(); it != tools.end(); ++it) {
        if (*it == tool) {
            tool->setWorker(nullptr);
            tools.erase(it);
            std::cout << "Tool removed from worker successfully." << std::endl;
            return;
        }
    }

    std::cout << "Tool not found for this worker." << std::endl;
}

void Worker::registerToWorkShop(Workshop *workshop)
{
    if (!workshop) {
        std::cout << "Cannot register to a null workshop." << std::endl;
        return;
    }
    auto it = std::find(Workshops.begin(), Workshops.end(), workshop);
    if (it != Workshops.end()) {
        std::cout << "Worker is already registered to this workshop." << std::endl;
        return;
    }

    Workshops.push_back(workshop);
    std::cout << "Worker successfully registered to a new workshop." << std::endl;
}

void Worker::Work()
{
    if (Workshops.empty()) {
        std::cout << "This worker is not registered in any workshop and cannot work." << std::endl;
        return;
    }

    std::cout << "Worker is working in " << Workshops.size() << " workshop(s)." << std::endl;

    if (tools.empty()) {
        std::cout << "Worker has no tools to use." << std::endl;
        return;
    }

    for (Tool* tool : tools) {
        if (tool != nullptr) {
            tool->use();
        }
    }
}
//-----------------------------------------------------------------



Tool::Tool() {
    std::cout << "Tool created." << std::endl;
}

Tool::~Tool() {
    std::cout << "Tool destroyed." << std::endl;
}

void Tool::setNumberOfTools(int n) {
    NumberOfTools = n;
}

const int Tool::getNumberOfTools() const {
    return NumberOfTools;
}

void Tool::setWorker(Worker* w) {
    worker = w;
}

Worker* Tool::getWorker() const {
    return worker;
}

// --------------------------------------------------------


Hammer::Hammer() {
    setNumberOfTools(10);
    std::cout << "Hammer created." << std::endl;
}

Hammer::~Hammer() {
    std::cout << "Hammer destroyed." << std::endl;
}

void Hammer::use() {
    if (getNumberOfTools() > 0) {
        std::cout << "Using the hammer!" << std::endl;
        setNumberOfTools(getNumberOfTools() - 1);
    } else {
        std::cout << "The hammer is worn out and can’t be used anymore." << std::endl;
    }
}


// -------------------------------------------------------------


void Workshop::signUp(Worker* worker) {
    if (!worker) {
        std::cout << "Cannot register a null worker." << std::endl;
        return;
    }

    if (std::find(workerList.begin(), workerList.end(), worker) != workerList.end()) {
        std::cout << "Worker already registered in this workshop." << std::endl;
        return;
    }

    workerList.push_back(worker);
    std::cout << "Worker registered to workshop successfully." << std::endl;
}

void Workshop::leaveWorkshop(Worker* worker) {
    if (!worker) {
        std::cout << "Cannot remove a null worker." << std::endl;
        return;
    }

    auto it = std::find(workerList.begin(), workerList.end(), worker);
    if (it != workerList.end()) {
        workerList.erase(it);
        std::cout << "Worker removed from workshop successfully." << std::endl;
    } else {
        std::cout << "Worker not found in this workshop." << std::endl;
    }
}

void Workshop::executeWorkDay(Worker* specificWorker) {
    if (specificWorker) {
        std::cout << "\nExecuting workday for one specific worker..." << std::endl;
        specificWorker->Work();
        return;
    }
    std::cout << "\n--- Executing workday for all registered workers ---" << std::endl;
    if (workerList.empty()) {
        std::cout << "No workers registered in the workshop today." << std::endl;
        return;
    }
    for (Worker* w : workerList) {
        if (w) w->Work();
    }
}