#include <windows.h>
#include <bits/stdc++.h>

#include <GL/glut.h>
#include <cmath>

class Pixel
{
public:
    float x, y;

    Pixel(float x, float y)
    {
        this->x = x;
        this->y = y;
    }
};

void drawLineDDA(float x1, float y1, float x2, float y2)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = std::max(abs(dx), abs(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= steps; i++)
    {
        glVertex2f(x, y);
        x += xIncrement;
        y += yIncrement;
    }
    glEnd();
}

void drawLineBresenham(float x1, float y1, float x2, float y2)
{
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float slope = dy / dx;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    if (slope <= 1)
    {
        float p = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            if (p >= 0)
            {
                y += (y2 > y1 ? 1 : -1);
                p -= 2 * dx;
            }
            x += (x2 > x1 ? 1 : -1);
            p += 2 * dy;
            glVertex2f(x, y);
        }
    }
    else
    {
        float p = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (p >= 0)
            {
                x += (x2 > x1 ? 1 : -1);
                p -= 2 * dy;
            }
            y += (y2 > y1 ? 1 : -1);
            p += 2 * dx;
            glVertex2f(x, y);
        }
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw line using DDA algorithm
    glColor3f(1.0, 0.0, 0.0);
    drawLineDDA(100, 100, 400, 300);

    // Draw line using Bresenham's algorithm
    glColor3f(0.0, 1.0, 0.0);
    drawLineBresenham(100, 200, 400, 400);

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Line Drawing");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
