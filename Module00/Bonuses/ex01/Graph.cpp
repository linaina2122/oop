#define STB_IMAGE_WRITE_IMPLEMENTATION

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
const Vector2 &Graph::getSize() const
{
    return (this->size);
}
const std::list<Vector2> &Graph::getL() const
{
    return (this->l);
}

int Graph::addPoint(float x, float y)
{
    if (this->size.getX() > x && this->size.getY() > y && x >= 0 && y >= 0)
    {
        this->l.push_back(Vector2(x, y));
        std::cout << "point added successfuly " << std::endl;
        return (0);
    }
    std::cout << "Point doesn't exists in the graph" << std::endl;
    return (1);
}
int Graph::matched(float x, float y)
{
    std::list<Vector2>::iterator it = this->l.begin();
    while (it != this->l.end())
    {
        if (x == it->getX() && y == it->getY())
            return 1;
        it++;
    }
    return (0);
}

void  Graph::display()
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
        const int width = 500;
    const int height = 500;

    std::vector<unsigned char> image(width * height * 3, 255);

    drawLine(image, width, height, 100 , 250 , (this->size.getX()) + 250,  250 , 0, 0, 0);
    drawLine(image, width, height, 100, 100, 100, (this->size.getY() + 250) , 0, 0, 0);
    if (stbi_write_png("Graph.png", width, height, 3, &image[0], width * 3))
        std::cout << "PNG written: test_line.png\n";
    else
        std::cout << "Failed to write PNG\n";
}
