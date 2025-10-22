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


void drawChart(std::vector<unsigned char>& img, int width, int height,
                std::vector<std::pair<int, int>>& points,
               unsigned char r, unsigned char g, unsigned char b,
             int lineThickness)
{
    if (points.size() < 2)
        return;

    for (size_t i = 0; i < points.size(); ++i)
    {
        int x = points[i].first * 20 + X0;
        int y = HEIGHT - (Y0 + points[i].second * 20);
        if (i > 0)
        {
            int xPrev = points[i - 1].first * 20 + X0;
            int yPrev = HEIGHT - (Y0 + points[i - 1].second * 20);

            drawLine(img, width, height, xPrev, yPrev, x, y, r, g, b, 1);
        }
    }
}

