#include <vector>
#include <list>
#include <iostream>

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
