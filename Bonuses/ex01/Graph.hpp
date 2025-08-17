#include <vector>
#include <list>
#include "Vector2.hpp"

class Graph {
    private:
    Vector2 size;
    std::list<Vector2> l;
    public :
    Graph();
    ~Graph();
    void setSize(Vector2 s);
    void setL(std::list<Vector2> L);
    const Vector2 &getSize ()const;
    const std::list<Vector2> &getL ()const;
    int matched(float x , float y);
    int addPoint(float x, float y);
    void display();

};