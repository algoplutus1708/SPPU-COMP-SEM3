#include <windows.h>
#include <bits/stdc++.h>
#include <GL/glut.h>

class Shape
{
public:
    virtual void draw() const = 0;
    virtual void move(int key) = 0;
};

class Ball : public Shape
{
private:
    float x, y;
    float radius;

public:
    Ball(float initialX, float initialY, float r) : x(initialX), y(initialY), radius(r) {}

    void draw() const override
    {
        glColor3f(0.0, 0.0, 1.0); // Blue color
        glBegin(GL_TRIANGLE_FAN);
        for (int i = 0; i < 360; i++)
        {
            float theta = i * 3.1415926 / 180;
            glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
        }
        glEnd();
    }

    void move(int key) override
    {
        switch (key)
        {
        case GLUT_KEY_UP:
            y += 5.0;
            break;
        case GLUT_KEY_DOWN:
            y -= 5.0;
            break;
        case GLUT_KEY_LEFT:
            x -= 5.0;
            break;
        case GLUT_KEY_RIGHT:
            x += 5.0;
            break;
        default:
            break;
        }
    }
};

Ball ball(200.0, 200.0, 20.0); // Initial position and radius

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    ball.draw();
    glFlush();
}

void specialKeys(int key, int, int)
{
    ball.move(key);
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Ball Control");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    gluOrtho2D(0, 400, 0, 400);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return 0;
}
