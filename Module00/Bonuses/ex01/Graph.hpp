#include <vector>
#include <list>
#include <map>
#include <fstream>
#include "Draw.hpp"
#include "../stb/stb_image_write.h"


#define HEIGHT 500
#define WIDTH 500
#define X0  500 / 5
#define Y0   (500 / 5)

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
