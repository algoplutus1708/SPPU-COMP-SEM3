#include <GL/glut.h>
#include <cmath>

class Shape {
public:
    virtual void draw() const = 0;
};

class Line : public Shape {
private:
    float x1, y1, x2, y2;

public:
    Line(float x1, float y1, float x2, float y2) : x1(x1), y1(y1), x2(x2), y2(y2) {}

    void draw() const override {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }
};

class Circle : public Shape {
private:
    float cx, cy, r;

public:
    Circle(float cx, float cy, float r) : cx(cx), cy(cy), r(r) {}

    void draw() const override {
        glBegin(GL_LINE_LOOP);
        int numSegments = 100;
        for (int i = 0; i < numSegments; i++) {
            float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
            float x = r * cosf(theta);
            float y = r * sinf(theta);
            glVertex2f(cx + x, cy + y);
        }
        glEnd();
    }
};

class Triangle : public Shape {
private:
    float x1, y1, x2, y2, x3, y3;

public:
    Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}

    void draw() const override {
        Line line1(x1, y1, x2, y2);
        Line line2(x2, y2, x3, y3);
        Line line3(x3, y3, x1, y1);

        line1.draw();
        line2.draw();
        line3.draw();
    }
};

void drawShapes() {
    glColor3f(0.0f, 0.5f, 0.0f);
    Circle outerCircle(0.0, -0.015, 0.52);
    outerCircle.draw();

    Triangle triangle(0, 0.5, -0.35, -0.4, 0.35, -0.4);
    glColor3f(1.0f, 1.0f, 1.0f);
    triangle.draw();

    glColor3f(0.0f, 0.5f, 0.0f);
    Circle innerCircle(0, -0.15, 0.225);
    innerCircle.draw();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawShapes();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("PATTERN");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}





















































/*
g++ filename.cpp -lGL -lGLU -lglut
frame buffer-- memory buffer that stores pixel data, color information, 
depth information, and other attributes for rendering without 
directly displaying the results on the screen
glutPostRedisplay() --
to inform GLUT that the contents of the window should be redrawn.
gl_begin --
glBegin is an OpenGL function used to specify the beginning of a sequence of vertices 
glvertex2i --
glVertex2i is an OpenGL function used to specify a 2D integer coordinate for the draw
glViewport --
. It specifies the rectangular region of the window where the final image will be displayed.
glMatrixMode(GL_PROJECTION) --
The projection matrix is crucial for defining how 3D scenes are projected onto a 2D screen, influencing the perspective and geometry of the rendered scene.
void Init() --
The Init function initializes the OpenGL environment.
glFlush --
glFlush is an OpenGL function that forces execution of OpenGL commands in the command buffer.
glClearColor(0,0,0,0) -- function call sets the clear color for the color buffer in OpenGL
 glClear(GL_COLOR_BUFFER_BIT)-- clear the color buffer of the currently selected framebuffer.
glLoadIdentity()
is an OpenGL function that resets the current matrix to the identity matrix.
glOrtho() function in OpenGL is used to define a 2D orthographic projection matrix 
The glutInit(&argc, argv); function is part of the GLUT (OpenGL Utility Toolkit) library and is used to initialize GLUT and process command line arguments.
ARGC AND ARGV
argc: Stands for "argument count." It represents the number of command-line arguments passed to the program when it is executed. It is an integer.
argv: Stands for "argument vector." It is an array of strings where each element is a command-line argument passed to the program. The first element argv[0] usually contains the name of the program itself.
*/