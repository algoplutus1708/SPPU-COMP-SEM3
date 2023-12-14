#include <windows.h>
#include <bits/stdc++.h>

#include <GL/glut.h>
#include <cmath>
#include <iostream>

int iterations; // Declare the global variable

// Function to draw a line segment
void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

// Function to recursively generate snowflake
void generateSnowflake(float x1, float y1, float x2, float y2, int iterations)
{
    if (iterations == 0)
    {
        drawLine(x1, y1, x2, y2);
    }
    else
    {
        float deltaX = x2 - x1;
        float deltaY = y2 - y1;
        float x3 = x1 + deltaX / 3;
        float y3 = y1 + deltaY / 3;
        float x4 = x1 + 2 * deltaX / 3;
        float y4 = y1 + 2 * deltaY / 3;

        float x5 = x3 + (x4 - x3) * cos(M_PI / 3) - (y4 - y3) * sin(M_PI / 3);
        float y5 = y3 + (x4 - x3) * sin(M_PI / 3) + (y4 - y3) * cos(M_PI / 3);

        generateSnowflake(x1, y1, x3, y3, iterations - 1);
        generateSnowflake(x3, y3, x5, y5, iterations - 1);
        generateSnowflake(x5, y5, x4, y4, iterations - 1);
        generateSnowflake(x4, y4, x2, y2, iterations - 1);
    }
}

// Function to display the snowflake
void displaySnowflake()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();

    // Generate the snowflake
    generateSnowflake(-0.5, -0.433, 0.5, -0.433, iterations); // Adjust the initial coordinates and size of the snowflake

    glFlush();
}

int main(int argc, char **argv)
{
    // Initialize GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Snowflake Fractal");

    // Set up the display function
    glutDisplayFunc(displaySnowflake);

    // Set up the OpenGL parameters
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);

    // Get user input for the number of iterations
    std::cout << "Enter the number of iterations: ";
    std::cin >> iterations;

    // Start the main loop
    glutMainLoop();
    return 0;
}
