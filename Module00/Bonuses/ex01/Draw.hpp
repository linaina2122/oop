#include <vector>
#include <list>
#include <map>
#include "Vector2.hpp"
#include <fstream>

void drawLine(std::vector<unsigned char>& img, int width, int height,
              int x0, int y0, int x1, int y1,
              unsigned char r, unsigned char g, unsigned char b, int thickness);
void drawPoint(std::vector<unsigned char>& img, int width, int height,
               int x, int y,
               unsigned char r, unsigned char g, unsigned char b,
               int size);