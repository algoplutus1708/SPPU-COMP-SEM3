//Akhilesh Patidar
//Comp B S4
//7207

#include<GL/glut.h>
#include<bits/stdc++.h>
#include<GL/gl.h>

using namespace std;

int menu_id;
int submenu_id;
int val = 0;

class circles {
public:
     double x1, y1, r;

     void dda_circle() {
          int n = log2(r) + 1;
          double e = pow(2, -n);

          double xi = 0, yi = r;
          double x = xi, y = yi;
          double x2, y2;
          do {
               x2 = x + e * y;
               y2 = y - e * x2;
               glBegin(GL_POINTS);
               glColor3f(1.0, 0, 0);
               glVertex2f(x2 + x1, y2 + y1);
               glEnd();
               x = x2;
               y = y2;

          } while (abs(y - yi) < e || abs(xi - x) > e);

     }
     void plot(int a, int b, int c = 0) {
          glBegin(GL_POINTS);
          glColor3f(c, 1, 0);
          glVertex2i(a + x1, b + y1);
          glEnd();
     }
     void midpoint()
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

               plot(x, y, 1);
               plot(x, -y, 1);
               plot(-x, y, 1);
               plot(-x, -y, 1);
               plot(y, x, 1);
               plot(-y, x, 1);
               plot(y, -x, 1);
               plot(-y, -x, 1);
          }

     }


     void bresenham()
     {
          float x, y, p, delta, delta2;

          x = 0;
          y = r;
          p = 2 * (1 - r);

          while (x <= y)
          {
               if (p < 0)
               {
                    delta = 2 * p + 2 * y - 1;
                    if (delta <= 0)
                    {
                         x += 1;
                         p = p + 2 * x + 1;
                    }
                    else
                    {
                         p = p + 2 * x - 2 * y + 2;
                         x += 1;
                         y -= 1;
                    }
               }
               else if (p > 0)
               {
                    delta2 = 2 * p - 2 * x - 1;
                    if (delta2 <= 0)
                    {
                         x += 1;
                         y -= 1;
                         p = p + 2 * x - 2 * y + 2;
                    }
                    else
                         y -= 1;
               }
               else
               {
                    x += 1;
                    y -= 1;
                    p = p + 2 * x - 2 * y + 2;
               }

               plot(x, y);
               plot(x, -y);
               plot(-x, y);
               plot(-x, -y);
               plot(y, x);
               plot(-y, x);
               plot(y, -x);
               plot(-y, -x);
          }

     }

};

circles c;
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
     glutAddMenuEntry("DDA Circle", 1);
     glutAddMenuEntry("Midpoint Circle", 2);
     glutAddMenuEntry("Bresenham's Circle", 3);
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
          c.dda_circle();
     }
     else if (val == 2) {
          glColor3d(0, 0, 0);
          c.bresenham();
     }
     else if (val == 3) {
          glColor3d(0, 0, 0);
          c.midpoint();
     }
     glFlush();
}

int main(int argc, char* argv[])
{

     cout << "ENTER THE ORIGIN COORDINATES";
     cin >> c.x1 >> c.y1;
     cout << "ENTER THE RADIUS:";
     cin >> c.r;
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Circles");
     createmenu();
     glutDisplayFunc(display);
     glutKeyboardFunc(keyboard);
     init();
     glutMainLoop();
}




