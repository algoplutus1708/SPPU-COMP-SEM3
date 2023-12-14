#include <GL/glut.h>
#include <cmath>

class PatternDrawer {
public:
    static void drawLineDDA(float x1, float y1, float x2, float y2) {
        glBegin(GL_LINES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glEnd();
    }

    static void drawCircleBresenham(float cx, float cy, float r) {
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

    static void drawSquareDDA(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
        glBegin(GL_LINES);
        drawLineDDA(x1, y1, x2, y2);
        drawLineDDA(x2, y2, x3, y3);
        drawLineDDA(x3, y3, x4, y4);
        drawLineDDA(x4, y4, x1, y1);
        glEnd();
    }

    static void display() {
        glClear(GL_COLOR_BUFFER_BIT);

        float x1 = -0.5;
        float y1 = -0.5;
        float x2 = -0.5;
        float y2 = 0.5;
        float x3 = 0.5;
        float y3 = 0.5;
        float x4 = 0.5;
        float y4 = -0.5;

        glColor3f(1.0, 1.0, 1.0);
        drawSquareDDA(x1, y1, x2, y2, x3, y3, x4, y4);

        float x11 = 0.0;
        float y11 = -0.5;
        float x21 = -0.5;
        float y21 = 0.0;
        float x31 = 0.0;
        float y31 = 0.5;
        float x41 = 0.5;
        float y41 = 0.0;

        glColor3f(0.0f, 1.0f, 0.0f);
        drawSquareDDA(x11, y11, x21, y21, x31, y31, x41, y41);

        float inCircleRadius = 0.3535;
        glColor3f(1.0f, 1.0f, 1.0f);
        drawCircleBresenham(0, 0, inCircleRadius);

        glFlush();
    }
};

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("PATTERN");
    glutDisplayFunc(PatternDrawer::display);
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