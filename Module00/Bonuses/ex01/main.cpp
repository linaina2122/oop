#include "Graph.hpp"

int main(){
    Graph g;
    Vector2 v(10, 5);
    g.setSize(v);
    g.getSize();
    g.addPoint(4, 1);
    g.addPoint(9, 3);
    g.addPoint(1, 0);
    g.addPoint(2, 2);
    g.display();
    return 0;
}