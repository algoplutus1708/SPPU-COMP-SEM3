// #include<windows.h>
// #include <GL/glut.h>
// #include <bits/stdc++.h>
// using namespace std;

// #define w 500
// #define h 500

// void init()
// {
//     glClear(GL_COLOR_BUFFER_BIT);
// 	glClearColor(1.0,1.0,1.0,0.0);
// 	glMatrixMode(GL_PROJECTION);
// 	glLoadIdentity();
// 	gluOrtho2D(-w/2,w/2,-h/2,h/2);
// }

// void setpixel(GLint x, GLint y)
// {
// 	glColor3f(0.0,0.0,1.0);
// 	glPointSize(2.0);
// 	glBegin (GL_POINTS);
// 		glVertex2f(x,y);
// 	glEnd();
// 	glFlush();
// }

// float mati[30][2],mato[30][2];
// int k=0,c;

// class trans
// {
// 	int transl[2][2];
// public:
// 	int mul(float s[2][2])
// 	{
// 		int i,j,k;
// 		float sum;
// 		for(i=0;i<c;i++)
// 		{
// 			for(j=0;j<2;j++)
// 			{
// 				sum=0;
// 				for(k=0;k<2;k++)
// 				sum=sum+mati[i][k]*s[k][j];
// 				mato[i][j]=sum;
// 			}
// 		}
// 		return mato[30][2];
// 	}
// 	void plot(float m[][2])
// 	{
// 		glColor3f(0.0,1.0,0.0);
// 		glBegin(GL_LINE_LOOP);
// 			for(int i=0;i<c;i++)
// 				glVertex2f(m[i][0],m[i][1]);
// 		glEnd();
// 		glFlush();
// 	}
// 	void translation(float tx,float ty)
// 	{
// 		int i;
// 		for(i=0;i<c;i++)
// 		{
// 			mato[i][0]=mati[i][0] + tx;
// 			mato[i][1]=mati[i][1] + ty;
// 		}
// 	}
// 	void scaling()
// 	{
// 		float scale[2][2];
// 		int i;
// 		float sx,sy;
// 		cout<<"\nScaling:\nEnter Sx factor::";
// 		cin>>sx;
// 		cout<<"\nEnter Sy factor::";
// 		cin>>sy;
// 		scale[0][0]=sx;
// 		scale[0][1]=0;
// 		scale[1][0]=0;
// 		scale[1][1]=sy;
// 		mul(scale);
// 		plot(mato);
// 	}
// 	void rotation()
// 	{
// 		int rot;
// 		float angle,rota[2][2];
// 		cout<<"\nRotation:\nEnter angle::";
// 		cin>>angle;
// 		angle=(3.14*angle)/180;
// 		cout<<"1.For Anti-Clockwise rotation\n2.For Clockwise rotation\nEnter your choice::";
// 		cin>>rot;
// 		switch(rot)
// 		{
// 			case 1 :rota[0][0]=cos(angle);
// 					rota[0][1]=-sin(angle);
// 					rota[1][0]=sin(angle);
// 					rota[1][1]=cos(angle);
// 					break;
// 			case 2 :rota[0][0]=cos(angle);
// 					rota[0][1]=sin(angle);
// 					rota[1][0]=-sin(angle);
// 					rota[1][1]=cos(angle);
// 					break;
// 			default:cout<<"\nInvalid Input!!!";
// 					system("pause");
// 					exit(0);
// 		}
// 		mul(rota);
// 	}
// 	void reflection()
// 	{
// 		char axis;
// 		int i;
// 		cout<<"\nEnter reflection axis:";
// 		cin>>axis;
// 		glBegin(GL_LINE_LOOP);
// 			if(axis=='x'||axis=='X')
// 			{
// 				for(i=0;i<c;i++)
// 				{
// 					glVertex2i(round(mati[i][0]),round(mati[i][1] * -1));
// 				}
// 			}
// 			else if(axis=='y'||axis=='Y')
// 			{
// 				for(i=0;i<c;i++)
// 				{
// 					glVertex2i(round(mati[i][0] * -1), round(mati[i][1]));
// 				}
// 			}
// 		glEnd();
// 	}

// 	void shearing()
// 	{
// 		char axis;
// 		int i, shearingX, shearingY;
// 		cout<<"\nEnter shearing axis:";
// 		cin>>axis;
// 		glColor3f(0.0,1.0,0.0);
// 		glBegin(GL_LINE_LOOP);
// 			if(axis=='x'||axis=='x')
// 			{
// 				cout<<"\nEnter shearing factor for x:";
// 				cin>>shearingX;
// 					glVertex2i(mati[0][0], mati[0][1]);
// 					glVertex2i(mati[1][0] + shearingX, mati[1][1]);
// 					glVertex2i(mati[2][0] + shearingX, mati[2][1]);
// 					glVertex2i(mati[3][0], mati[3][1]);
// 			}
// 			else if(axis=='y'||axis=='y')
// 			{
// 				cout<<"\nEnter shearing factor for y:";
// 				cin>>shearingY;
// 				glVertex2i(mati[0][0], mati[0][1]);
// 				glVertex2i(mati[1][0], mati[1][1]);
// 				glVertex2i(mati[2][0], mati[2][1] + shearingY);
// 				glVertex2i(mati[3][0], mati[3][1] + shearingY);
// 			}
// 		//}
// 		glEnd();
// 	}
// }t;

// void menu(int c)
// {
// 	float tx,ty;
// 	if(c==1)
// 	{
// 		cout<<"\nTranslation->\nEnter tx factor::";
// 		cin>>tx;
// 		cout<<"\nEnter ty factor::";
// 		cin>>ty;
// 		t.translation(tx,ty);
// 		t.plot(mato);
// 		cout<<"Translation Done\n";
// 	}
// 	else if(c==2)
// 	{
// 		t.scaling();
// 		cout<<"Scaling Done\n";
// 	}
// 	else if(c==3)
// 	{
// 		t.rotation();
// 		t.plot(mato);
// 		cout<<"Rotation Done\n";
// 	}
// 	else if(c==4)
// 	{
// 		t.reflection();
// 		t.plot(mati);
// 		cout<<"Reflection Done\n";
// 	}
// 	else if(c==5)
// 	{
// 		t.shearing();
// 		t.plot(mato);
// 		cout<<"Shearing Done\n";
// 	}
// 	else if(c==6)
// 	{
// 		glClearColor(0,0,0,1);
// 		glClear(GL_COLOR_BUFFER_BIT);
// 		glFlush();
// 	}
// 	else if(c==7)
// 	{
// 		exit(1);
// 	}
// 	else
// 	{
// 		cout<<"\nInvalid option. Try again.";
// 	}
// }

// void keyboard(unsigned char key,int x,int y)
// {
// 	if(key==27)
// 		exit (0);

// 	if(key==108 || key==76)
// 	{   glColor3f(0.0,0.0,1.0);
// 		glBegin(GL_LINE_LOOP);
//         for(int i=0;i<k;i++)
//         glVertex2f(mati[i][0],mati[i][1]);
//         glEnd();
//         c=k;
//         k=0;
//         glFlush();
// 	}
// }

// void mouse(int button,int state,int x,int y)
// {
// 	int x1,y1,p;
// 	if(button==GLUT_LEFT_BUTTON && state== GLUT_DOWN) {
// 			mati[k][0]=(float)(x-250);
// 			mati[k][1]=(float)(250-y);
// 			glColor3f(1.0,0.0,0.0);
// 			glPointSize(3.0);
// 			glBegin(GL_POINTS);
// 			glVertex2f(mati[k][0],mati[k][1]);
// 			glEnd();
// 			k++;
// 			glFlush();
// 	}
// 	 glutCreateMenu(menu);
//         glutAddMenuEntry("TRANSLATION",1);
//         glutAddMenuEntry("SCALING",2);
//         glutAddMenuEntry("ROTATION",3);
//         glutAddMenuEntry("REFLECTION",4);
//         glutAddMenuEntry("SHEARING",5);
//         glutAddMenuEntry("CLEAR",6);
//         glutAddMenuEntry("EXIT",7);
//     glutAttachMenu(GLUT_RIGHT_BUTTON);
// }

// int main(int argc, char **argv)
// {
// 	glutInit(&argc, argv);
// 	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
// 	glutInitWindowSize(w,h);
// 	glutCreateWindow("2D Transformations");
// 	cout<<"Use mouse pointer to put point on the graphics screen\nUse 'l' or 'L' to make polygon on graphics window.\nUse right mouse button to get 2D transformations menu.";
// 	glutDisplayFunc(init);
// 	glutKeyboardFunc(keyboard);
// 	glutMouseFunc(mouse);
// 	glutMainLoop();

// 	return 0;
// }



#include<windows.h>
#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std ;
int m[20][3] , n = 0 ;
void setpcolor(double r1, double b1 , double g1 ){
    glColor3f(r1,b1,g1);
}

void conect(int x , int y , int px , int py){

    glPointSize(2);
    glBegin(GL_LINE_STRIP);
        glVertex2i(x,y);
        glVertex2i(px,py);
    glEnd();
    glFlush();
}

void translation(int tx,int ty){//cout << tx<<ty;
    int tm[3][3] = {{1,0,tx},{0,1,ty},{0,0,1} } ,ne[3]={} ;
     for(int i=0 ;i<n;i++){
        ne [0]  = tm[0][0]*m[i][0] + tm[0][1]*m[i][1] + tm[0][2]*m[i][2] ;
        ne [1]  = tm[1][0]*m[i][0] + tm[1][1]*m[i][1] + tm[1][2]*m[i][2] ;
        ne [2]  = tm[2][0]*m[i][0] + tm[2][1]*m[i][1] + tm[2][2]*m[i][2] ;
        m[i][0] = ne[0] ; m[i][1] = ne[1] ; m[i][2] = ne[2] ;
    }
     for(int i=0 ;i<n;i++){
        int ni = (i+1)%n;
        setpcolor(1,1,0) ;
        conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
    }


}

void rotation(double rot ){//cout << tx<<ty;
    double pi = 3.14159265 ;
    double rad = (pi/180.00) ;   rad *= rot ;
    double rm[3][3] = {{cos(rad),-sin(rad),1},{sin(rad),cos(rad),1},{0,0,1} } ;
    int ne[3]={} ;
    for(int i=0 ;i<n;i++){
        ne [0]  = rm[0][0]*m[i][0] + rm[0][1]*m[i][1] + rm[0][2]*m[i][2] ;
        ne [1]  = rm[1][0]*m[i][0] + rm[1][1]*m[i][1] + rm[1][2]*m[i][2] ;
        ne [2]  = rm[2][0]*m[i][0] + rm[2][1]*m[i][1] + rm[2][2]*m[i][2] ;
        m[i][0] = ne[0] ; m[i][1] = ne[1] ; m[i][2] = ne[2] ;
    }
     for(int i=0 ;i<n;i++){
        int ni = (i+1)%n;
        setpcolor(1,1,0) ;
        conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
    }
}

void shear(double shx , double shy ){//cout << tx<<ty;
    double sm[3][3] = {{1,shx,0},{shy,1,0},{0,0,1} } ;
    double ne[3]={} ;
    for(int i=0 ;i<n;i++){
        ne [0]  = sm[0][0]*m[i][0] + sm[0][1]*m[i][1] + sm[0][2]*m[i][2] ;
        ne [1]  = sm[1][0]*m[i][0] + sm[1][1]*m[i][1] + sm[1][2]*m[i][2] ;
        ne [2]  = sm[2][0]*m[i][0] + sm[2][1]*m[i][1] + sm[2][2]*m[i][2] ;
        m[i][0] = ne[0] ; m[i][1] = ne[1] ; m[i][2] = ne[2] ;
    }
     for(int i=0 ;i<n;i++){
        int ni = (i+1)%n;
        setpcolor(1,1,0) ;
        conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
    }
}
void scale(int sx , int sy ){//cout << tx<<ty;
    int sm[3][3] = {{sx,0,0},{0,sy,0},{0,0,1} } ;
    int ne[3]={} ;
    for(int i=0 ;i<n;i++){
        ne [0]  = sm[0][0]*m[i][0] + sm[0][1]*m[i][1] + sm[0][2]*m[i][2] ;
        ne [1]  = sm[1][0]*m[i][0] + sm[1][1]*m[i][1] + sm[1][2]*m[i][2] ;
        ne [2]  = sm[2][0]*m[i][0] + sm[2][1]*m[i][1] + sm[2][2]*m[i][2] ;
        m[i][0] = ne[0] ; m[i][1] = ne[1] ; m[i][2] = ne[2] ;
    }
     for(int i=0 ;i<n;i++){
        int ni = (i+1)%n;
        setpcolor(1,1,0) ;
        conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
    }
}
void reflect(char c){//cout << tx<<ty;
    int sm[3][3] = {{1,0,0},{0,1,0},{0,0,1} } ;
    if(c=='x'||c=='X') { sm[1][1]=-1 ; }
    else { sm[0][0] = - 1 ; }
    int ne[3]={} ;
    for(int i=0 ;i<n;i++){
        ne [0]  = sm[0][0]*m[i][0] + sm[0][1]*m[i][1] + sm[0][2]*m[i][2] ;
        ne [1]  = sm[1][0]*m[i][0] + sm[1][1]*m[i][1] + sm[1][2]*m[i][2] ;
        ne [2]  = sm[2][0]*m[i][0] + sm[2][1]*m[i][1] + sm[2][2]*m[i][2] ;
        m[i][0] = ne[0] ; m[i][1] = ne[1] ; m[i][2] = ne[2] ;
    }
     for(int i=0 ;i<n;i++){
        int ni = (i+1)%n;
        setpcolor(1,1,0) ;
        conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
    }
}


void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.0,0.0);
    glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);

	gluOrtho2D(-250,250,-250,250) ;
	glFlush() ;
}
void display(){
    glFlush() ;
}

int flg = 1 ;
void menu(int c){
    flg++ ;
        for(int i=0 ;i<n;i++){
            int ni = (i+1)%n;
            setpcolor(1,1,1) ;
            conect(m[i][0],m[i][1],m[ni][0],m[ni][1]) ;
        }
        glFlush() ;//glFlush() ;

    if(c==1){
        int tx = 0 , ty = 0 ;
        cout <<"Enter x-translation factor :  " ; cin >> tx ;
        cout <<"Enter y-translation factor :  " ; cin >> ty ;
        translation(tx,ty) ;
    }
    else if(c==2) {
        double rot ;
        int flg = 1 ;
        cout <<"Enter 1 for clockwise else enter 0 for anti-clock wise :  " ; cin >> flg ;
        cout <<"Enter by how much degree the object is to be rotated :  " ; cin >> rot ;
        if(flg){
            rot = -rot ;
        }
        rotation(rot) ;
    }
    else if(c==3) {
            int sx = 1 , sy = 1 ;
        cout <<"Enter the horizontal scaling factor :  " ; cin >> sx ;
        cout <<"Enter the vertical scaling factor :  " ; cin >> sy ;
        scale(sx,sy) ;
    }
    else if(c==4) {
        char c ;
        cout <<"Enter the axis of reflection :  " ; cin >> c ;
        reflect(c) ;
    }
    else if(c==5) {
        double sx = 0 , sy = 0 ;
        cout <<"Enter the horizontal shearing factor :  " ; cin >> sx ;
        cout <<"Enter the vertical shearing factor :  " ; cin >> sy ;
        shear(sx,sy) ;
    }

}

void mouse(int but , int state , int cx , int cy ){
    cx  -= 250 ; cy  -= 250 ; cy = - cy ;
    if( but == GLUT_LEFT_BUTTON && state == GLUT_DOWN && flg==1 ){
        m[n][0] = cx ; m[n][1] = cy ; m[n][2] = 1 ;
        n++ ;
        glColor3f(1,0.0,0);
            glPointSize(3.0);
            glBegin (GL_POINTS);
            glVertex2f(cx,cy);
        glEnd();
         glFlush() ;
    }

}


int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitWindowSize(500,500);
	glutInitWindowPosition(1000,150);
	glutCreateWindow(" Polygon ");
    cout << "Left Click to select a vertex , Right click to open the menu \n\n";
	init();

	glutDisplayFunc(display);

    glutMouseFunc(mouse);

     glutCreateMenu(menu);
        glutAddMenuEntry("TRANSLATION",1);
        glutAddMenuEntry("ROTAITION",2);
        glutAddMenuEntry("REFLECTION",4);
        glutAddMenuEntry("SCALING",3);
        glutAddMenuEntry("SHEARING",5);
     glutAttachMenu(GLUT_RIGHT_BUTTON);


	glutMainLoop();
	return 0;

}
