#include "Graph.hpp"

void drawLine(std::vector<unsigned char> &img, int width, int height,
              int x0, int y0, int x1, int y1,
              unsigned char r, unsigned char g, unsigned char b,
              int t)
{
    int dx = abs(x1 - x0);
    int direcX = x0;
    if (x0 < x1)
        direcX = 1;
    else
        direcX = -1;
    int dy = -abs(y1 - y0);
    int direcY = y1;
    if (y0 < y1)
        direcY = 1;
    else
        direcY = -1;
    int err = dx + dy;
    int e2;

    while (true)
    {
        for (int ty = -t / 2; ty <= t / 2; ++ty)
        {
            for (int tx = -t / 2; tx <= t / 2; ++tx)
            {
                int px = x0 + tx;
                int py = y0 + ty;
                if (px >= 0 && px < width && py >= 0 && py < height)
                {
                    int idx = (py * width + px) * 3;
                    img[idx + 0] = r;
                    img[idx + 1] = g;
                    img[idx + 2] = b;
                }
            }
        }
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err; // to make sure that err doesn't contain float points
        if (e2 >= dy) // we move one step to x
        {
            err += dy;
            x0 += direcX;
        }
        if ((e2 <= dx)) // we move one step to y
        {
            err += dx;
            y0 += direcY;
        }
    }
}

void drawPoint(std::vector<unsigned char> &img, int width, int height, int x, int y,
               unsigned char r, unsigned char g, unsigned char b, int size)
{
    int Dx = -size; //to start from the center
    int Dy = -size;
    while (Dy <= size)
    {
        ++Dy;
        while (Dx <= size)
        {
            Dx++;
            int X = Dx + x; // put a pixel to the right or left
            int Y = Dy + y; // put a pixel up or down
            if (X >= 0 && X < width && Y >= 0 && Y < height)
            {
                int idx = (Y * width + X) * 3;
                img[idx + 0] = r;
                img[idx + 1] = g;
                img[idx + 2] = b;
            }
        }
    }
}
