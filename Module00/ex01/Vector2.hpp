#include <vector>
#include <list>
#include <iostream>

class Vector2 {
    private :
        float x;
        float y;
    public:
        Vector2();   
        Vector2(float X, float Y);
        ~Vector2();
        const float &getX ()const;
        const float &getY ()const;
};
