
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

struct Statistic {
    int level;
    int exp;
};

class Worker {
    private:
        Position coordonee;
        Statistic stat;
        Shovel *sh;
        std::vector<Tool*> tools; 
        std::vector<Workshop *>Workshops; 
    public :
        Worker();
        ~Worker();
        void setCoordonee(Position coord);
        Position getCoordonee();
        void setStat(Statistic s);
        Statistic getStat();
        void setShovel(Shovel *s);
        Shovel* getShovel() const;
        void addTools(Tool *tool);
        void deleteTools(Tool *tool);
        std::vector<Tool*> getTools() const;
        void registerToWorkShop(Workshop *workshop);
        void Work();
        Tool* GetTool(Tool *t);
};

class Tool {
  private :
        int NumberOfTools;
        Worker *worker;
    public:
        virtual void use() = 0;
        Tool();
        virtual ~Tool();
        void setNumberOfTools(int n);
        int  getNumberOfTools() const ;
        void setWorker(Worker *w);
         Worker *getWorker() const;
};

class Shovel: public Tool{
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


class Hammer : public Tool{
    public:
        Hammer();
        ~Hammer();
        void use ();
};

class Workshop {
    private :
        std::vector<Worker*> workerList;
    public :
        void signUp(Worker *worker);
        void leaveWorkshop(Worker *worker);
        void executeWorkDay(Worker *worker);
};

std::template <std::typename T>{

};