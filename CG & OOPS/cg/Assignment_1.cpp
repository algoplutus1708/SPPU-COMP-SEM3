//Akhilesh Patidar
//Comp B S4
//7207

#include<GL/glut.h>
#include<iostream>
#include<GL/gl.h>

using namespace std;

int menu_id;
int submenu_id;
int val = 0;

class lines {
public:
     int x1, x2, y1, y2;
     int x, y, d;
     void dda_line() {
          glClear(GL_COLOR_BUFFER_BIT);
          float stp;
          float dx = x2 - x1;
          float dy = y2 - y1;
          if (abs(dx) > abs(dy)) {
               stp = abs(dx);
          }
          else {
               stp = abs(dy);
          }

          float xinc = dx / stp;
          float yinc = dy / stp;
          float x = x1;
          float y = y1;
          glBegin(GL_POINTS);
          glColor3f(1.0, 0, 0);
          glVertex2i(x, y);
          glEnd();
          int k;
          for (k = 1;k <= stp;k++)
          {
               x = x + xinc;
               y = y + yinc;

               glBegin(GL_POINTS);

               glColor3f(1.0, 0.0, 0.0);
               glVertex2i(x, y);
               glEnd();

          }
     }
     void bresenham() {
          glClear(GL_COLOR_BUFFER_BIT);

          int dx = abs(x2 - x1);
          int dy = abs(y2 - y1);
          int x = x1;
          int y = y1;
          int xi = (x1 < x2) ? 1 : -1;
          int yi = (y1 < y2) ? 1 : -1;

          int p = dx - dy;

          glBegin(GL_POINTS);
          glColor3f(0, 1.0, 0);
          glVertex2i(x, y);
          glEnd();

          while (x != x2 || y != y2) {
               int p2 = 2 * p;

               if (p2 > -dy && p <= dx) {
                    p -= dy;
                    x += xi;
               }

               if (p2 < dx && p <= dy) {
                    p += dx;
                    y += yi;
               }

               glBegin(GL_POINTS);
               glColor3f(0, 1.0, 0);
               glVertex2i(x, y);
               glEnd();
          }
     };


};

lines l1;
void menu(int num)
{
     if (num == 4) {
          glClear(GL_COLOR_BUFFER_BIT);
          glLoadIdentity();
     }
     else if (num == 5)
     {
          exit(0);
     }
     else
     {
          val = num;
     }
     glutPostRedisplay();
}

void createmenu(void)
{
     submenu_id = glutCreateMenu(menu);
     glutAddMenuEntry("DDA Line", 1);
     glutAddMenuEntry("Simple Bresenham Line", 2);
     glutAddMenuEntry("Modified Bresenham Line", 3);
     menu_id = glutCreateMenu(menu);
     glutAddMenuEntry("Clear", 4);
     glutAddMenuEntry("Exit", 5);
     glutAddSubMenu("Create", submenu_id);
     glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void keyboard(unsigned char key, int x, int y)
{
     if (key == 27)               // Esc key
          exit(0);
     else if (key == 'D' || key == 'd') {
          val = 1;
     }
     else if (key == 'B' || key == 'b') {
          val = 2;
     }
     else if (key == 'M' || key == 'm') {
          val = 3;
     }

     glutPostRedisplay();
}

void init()
{
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(-500, 500, -500, 500);
}

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT);
     if (val == 1) {
          glColor3d(0, 0, 0);
          l1.dda_line();

     }
     else if (val == 2) {
          glColor3d(0, 0, 0);
          l1.bresenham();
     }
     glFlush();
}

int main(int argc, char* argv[])
{

     cout << "ENTER COORDINATES";
     cin >> l1.x1 >> l1.y1 >> l1.x2 >> l1.y2;
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Lines");
     createmenu();
     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     init();
     glutMainLoop();
}

