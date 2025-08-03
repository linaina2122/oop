#include "Graph.hpp"

Graph::Graph() 
{
    std::cout << "Graph constructor called" << std::endl;
}

Graph::~Graph()
{
    std::cout << "Graph destructor called" << std::endl;
}

 void Graph::setSize(Vector2 s)
 {
    this->size = s;
 }
    void Graph::setL(std::list<Vector2> L)
    {
        this->l = L;
    }
    const Vector2 &Graph::getSize ()const
    {
        return(this->size);
    }
    const std::list<Vector2> &Graph::getL ()const
    {
        return(this->l);
    }

    int Graph::addPoint(float x, float y)
    {
        if(this->size.getX() > x && this->size.getY() > y && x >= 0 && y >= 0)
        {
            this->l.push_back(Vector2(x, y));
            std::cout << "point added successfuly " << std::endl;
            return(0);
        }
        std::cout << "Point doesn't exists in the graph" << std::endl;
        return(1);
        
    }
int Graph::matched(float x , float y)
{
    std::list<Vector2>::iterator it = this->l.begin();
    while(it != this->l.end())
    {
        if(x == it->getX()  && y == it->getY())
            return 1;
        it++;
    }
    return(0);
}

void Graph::display()
{
    float Y = this->size.getY() - 1;
    while(Y >=0 )
    {
        std::cout << Y;
        float X = 0;
        while(X < this->size.getX())
        {
            if(this->matched(X, Y))
                std::cout << "x";
            else
                std::cout << ".";
            X++;
        }
            std::cout << std::endl;
            Y--;
        }
        std::cout << ' ';
    for(float X = 0 ; X < this->size.getX(); X++)
        std::cout << X;
    std::cout << std::endl;
}