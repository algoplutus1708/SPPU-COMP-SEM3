#include <windows.h>
#include <bits/stdc++.h>
#include <iostream>
#include <GL/glut.h>

class BouncingBall
{
private:
    float x, y;
    float radius;
    float speedY;

public:
    BouncingBall(float initialX, float initialY, float r, float initialSpeedY)
        : x(initialX), y(initialY), radius(r), speedY(initialSpeedY) {}

    void draw() const
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

    void update()
    {
        y += speedY;

        // Bounce when reaching the window boundaries
        if (y + radius > 400 || y - radius < 0)
        {
            speedY = -speedY;
        }
    }
};

BouncingBall ball(50.0, 50.0, 20.0, 0.05); // Initial position, radius, and speed

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    ball.draw();
    ball.update();
    glutPostRedisplay();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Bouncing Ball");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    gluOrtho2D(0, 400, 0, 400);
    glClearColor(1, 1, 1, 1);
    glutMainLoop();
    return 0;
}
