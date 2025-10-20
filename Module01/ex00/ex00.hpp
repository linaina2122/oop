
#include  <iostream>
#include <vector>
#include <algorithm>

class Shovel;
class Tool;
class Workshop;
struct Position {
    int x;
    int y;
    int z;
};

struct Statistics {
    int level;
    int exp;
};

class Worker {
    private:
        Position coordonee;
        Statistics stat;
        Shovel *sh;
        std::vector<Tool*> tools; 
        std::vector<Workshop *>Workshops; 
    public :
        Worker();
        ~Worker();
        void setCoordonee(Position coord);
        Position getCoordonee();
        void setStat(Statistics s);
        Statistics getStatistics();
        void setShovel(Shovel *s);
        Shovel* getShovel() const;
        void addTools(Tool *tool);
        void deleteTools(Tool *tool);
        std::vector<Tool*> getTools() const;
        void registerToWorkShop(Workshop *workshop);
        void Work();

};


class Shovel : public Tool{
    private:
        int numberOfUses;
        Worker *worker;
    public:
        Shovel(); 
        ~Shovel();
        void use();
        void setNumberOfUses(int n);
        int getNumberOfUses() const ;
        void setWorker(Worker *wor);
        Worker* getWorker() const ;
};

class Tool {
  private :
        int NumberOfTools;
        Worker *worker;
    public:
        virtual void use() = 0;
        Tool();
        ~Tool();
        void setNumberOfTools(int n);
        const int  getNumberOfTools() const ;
        void setWorker(Worker *w);
         Worker *getWorker() const;
};

class Hammer : public Tool{
    public:
        Hammer();
        ~Hammer();
        void use () override;
};

class Workshop {
    private :
        std::vector<Worker*> workerList;
    public :
        void signUp(Worker *worker);
        void leaveWorkshop(Worker *worker);
        void executeWorkDay(Worker *worker);
};
