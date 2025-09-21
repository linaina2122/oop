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
    std::fstream File("Graph.txt");
    float Y = this->size.getY() - 1;
    while(Y >=0 )
    {
        File << Y;
        float X = 0;
        while(X < this->size.getX())
        {
            if(this->matched(X, Y))
                File << "x";
            else
                File << ".";
            X++;
        }
            File << std::endl;
            Y--;
        }
        File << ' ';
    for(float X = 0 ; X < this->size.getX(); X++)
        File << X;
    File << std::endl;
    this->toPpm(File);
}

void Graph::toPpm(std::fstream &file)
{
    std::string tmp;
    std::ofstream File("Graph.ppm", std::ios::trunc);
    file.seekg(0, std::ios::beg); 
    File << "P3" << std::endl;
    File << this->size.getX() << " " << this->size.getY() << std::endl;
    File << 255 << std::endl;

    while(std::getline(file, tmp))
    {
        
        for(int i = 0; i < this->size.getX(); ++i)
        {
            char c = (i < tmp.size()) ? tmp[i] : '.';
            if(tmp[i] >= 48 && tmp[i] <= 56)
                File << "0 0 0";
            else if( tmp[i] == '.')
                File << "255 255 255";
            else if (tmp[i] == 'x')
                File << "200 200 200";
            File << " ";
        }
        File << std::endl;
    }
}

