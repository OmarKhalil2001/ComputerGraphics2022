#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>


#include <stdlib.h>
#include <math.h>
#include <windows.h>

void display();
void reshape(int w,int h);
void timer(int);
void init(){
    glClearColor(0.0,0.67,1.0,1.0);
}

int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,0);
    glutInitWindowSize(1200,800);

    glutCreateWindow("20101110 - 20102650");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0);
    init();

    glutMainLoop();
}
float step=0;
double theta = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glLineWidth(1.0);

    // GREEN GROUND
    glColor3f(0.1, 0.4, 0.2);
    glRecti(100,-150,-100,-90);

    //SMALL MOUBTAIN
    glColor3f(0.33, 0.25, 0.14);
    glBegin(GL_POLYGON);
    glVertex2f(-55, -100);
    glVertex2f(-20, 50);
    glVertex2f(15, -100);
    glEnd();

    //SMALL MOUBTAIN PEAK
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-35.2, -15);
    glVertex2f(-20, 50);
    glVertex2f(-4.7, -15);
    glEnd();


    //BIG MOUBTAIN
    glColor3f(0.4, 0.4, 0.4);
    glBegin(GL_POLYGON);
    glVertex2f(-80, -120);
    glVertex2f(-45, 80);
    glVertex2f(-10, -120);
    glEnd();

    //BIG MOUBTAIN PEAK
    glColor3f(1, 1, 1);
    glBegin(GL_POLYGON);
    glVertex2f(-57.3, 10);
    glVertex2f(-45, 80);
    glVertex2f(-32.7, 10);
    glEnd();
    glFlush();

    //Sun
    glColor3f(.9, .96, .14);
    glBegin(GL_POLYGON);
    double r = 25;
    glVertex2f(100, 150);
    for(double i = 180; i <= 270; i++){
        double angle = i * 3.14/ 180;
        glVertex2f(r * cos(angle) + 100, 2.2 * r * sin(angle)+150);
    }
    glEnd();

    //Tent1
    glColor3f(0.33, 0.25, 0.14);
    glBegin(GL_POLYGON);
    glVertex2f(40, -110);
    glVertex2f(50, -40);
    glVertex2f(60, -110);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(44, -110);
    glVertex2f(50, -50);
    glVertex2f(56, -110);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(45, -37);
    glVertex2f(55, -47);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(45, -47);
    glVertex2f(55, -37);
    glEnd();

    //Tent2
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex2f(63, -110);
    glVertex2f(73, -40);
    glVertex2f(83, -110);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(67, -110);
    glVertex2f(73, -50);
    glVertex2f(79, -110);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(68, -37);
    glVertex2f(78, -47);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(68, -47);
    glVertex2f(78, -37);
    glEnd();

    //Sun Rays Animation


    glColor3f(.9, .96, .14);

    glLineWidth(3.5);

    glBegin(GL_LINE_STRIP);
    glVertex2f(75, 135);
    glVertex2f(75 - step, 135 - step);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(77, 125);
    glVertex2f(77 - step, 125 - step * 1.25);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(74, 145);
    glVertex2f(74 - step * 1.1, 145 - step * 0.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(79, 117);
    glVertex2f(79 - step * 1.0, 117 - step*1.5);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(82, 108);
    glVertex2f(82 - step * 1.0, 108 - step*1.7);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(86, 101.5);
    glVertex2f(86 - step * 1.0, 101.5 - step*1.9);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(90, 96);
    glVertex2f(90 - step * 1.0, 96 - step*2.1);
    glEnd();

    //Rotating Sun Ray
    glColor3f(1, 1, 1);
    glLineWidth(60);
    glBegin(GL_LINE_STRIP);
    double x = 90, y = 130;
    glVertex2d(99, 148);
    glVertex2d((x-99) * cos(theta) -  (y-148) * sin(theta) + 99, (y-148 ) * cos(theta) + (x-99) * sin(theta) + 148);
    glEnd();

    glFlush();
}

void reshape(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100,100,-150,150, 10, -10);
    glMatrixMode(GL_MODELVIEW);
}
double dis = 0.015;
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
	step+=0.15;
    theta += dis;
    if(step > 8) step = 0;
    if(theta > 0.4 || theta <= -0.9) dis *= -1;

}
