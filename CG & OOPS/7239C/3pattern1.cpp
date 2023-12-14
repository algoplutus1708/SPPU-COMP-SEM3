#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;
int val = 0;

class shapes
{
public:
    int r1 = 100, r2 = 50;
    float l = 200;
    float b = 300;
    float cx = l / 2, cy = (b / 2) + 4, r = (l / 4) * pow(2, 0.7);
    void plot(int a, int b, int c = 0)
    {
        glBegin(GL_POINTS);
        glColor3f(c, 0, 0);
        glVertex2i(a, b);
        glEnd();
    }
    void line(float x1, float y1, float x2, float y2)
    {

        float stp;
        float dx = x2 - x1;
        float dy = y2 - y1;
        stp = max(abs(dx), abs(dy));
        float xinc = dx / stp;
        float yinc = dy / stp;
        float x = x1;
        float y = y1;
        plot(x, y);
        int k;
        for (k = 1; k <= stp; k++)
        {
            x = x + xinc;
            y = y + yinc;

            glBegin(GL_POINTS);

            glColor3f(1.0, 0.0, 0.0);
            glVertex2i(x, y);
            glEnd();
        }
    }
    void circle(int x1, int y1, int r)
    {
        float x, y, p;
        p = 5 / 4 - r;
        x = 0;
        y = r;

        while (x <= y)
        {
            if (p < 0)
            {
                p += 2 * x + 3;
                x += 1;
            }
            else if (p >= 0)
            {
                p += 2 * (x - y) + 5;
                x += 1;
                y -= 1;
            }

            plot(x + x1, y + y1, 1);
            plot(x + x1, -y + y1, 1);
            plot(-x + x1, y + y1, 1);
            plot(-x + x1, -y + y1, 1);
            plot(y + x1, x + y1, 1);
            plot(-y + x1, x + y1, 1);
            plot(y + x1, -x + y1, 1);
            plot(-y + x1, -x + y1, 1);
        }
    }

    void createPattern1()
    {
        glClear(GL_COLOR_BUFFER_BIT);
        line(0, 100, 2 * 25 * sqrt(3), -50);
        line(-2 * 25 * sqrt(3), -50, 2 * 25 * sqrt(3), -50);
        line(0, 100, -2 * 25 * sqrt(3), -50);
        circle(0, 0, 100);
        circle(0, 0, 50);
    }

    
};

shapes sp;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500, 500, -500, 500);
}

void display(void)
{

    sp.createPattern1();

    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pattern");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
}