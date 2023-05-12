#include<iostream>
#include<GL/glut.h>
using namespace std;
int xc,yc,r;
void input()
{
cout<<"\nEnter Center Points and Radius : ";
cin>>xc>>yc>>r;
}
void init()
{
glClearColor(1,1,1,1);//Background color and foreground color of screen
gluOrtho2D(-320,320,-240,240);//set screen dimensions
}
void plot (float x, float y)
{
glColor3f(0,0,0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();
}
void symmetry(int xc,int yc,int x,int y)
{
plot(xc+x,yc+y);
plot(xc-x,yc+y);
plot(xc+x,yc-y);
plot(xc-x,yc-y);
plot(xc+y,yc+x);
plot(xc-y,yc+x);
plot(xc+y,yc-x);
plot(xc-y,yc-x);
}
void bca()
{
glPointSize(3);
glColor3f(1,0,1);
int p,x,y;
x=0;
y=r;
p=3-2*r;
plot(xc+x,yc+y);
while(x<=y)
{
x++;
if(p>=0)
{
y--;
p=p+4*(x-y)+10;
}
else
{
p=p+4*x+6;
}
plot(xc+x,yc+y);
symmetry(xc,yc,x,y);
}
glFlush();
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);//clear the screen
bca();
}
int main(int argc,char **argv)
{
input();
glutInit(&argc,argv);
glutInitWindowSize(640,480);
glutInitWindowPosition(100,100);
glutCreateWindow("Sample Program");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
