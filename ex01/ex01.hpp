#include <vector>
#include <list>


class Vector2 {
    private :
        float x;
        float y;
    public:
        Vector2();
        ~Vector2();
        void setX(float X);
        void setY(float Y);
        const float &getX ()const;
        const float &getY ()const;
};

class Graph {
    private:
    Vector2 size;
    std::list<Vector2> l;
    public :
    Graph();
    ~Graph();



};