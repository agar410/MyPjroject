#include<GL\gl.h>
#include<GL\glut.h>
#include<windows.h>
//#pragma comment(lib, "glut32.lib")

#include <iostream>
using namespace std;
GLfloat cap_mat_ambient[]   = {0.0f, 0.0f, 1.0f, 1.0f};  //定義材質的環境光顏色，騙藍色
GLfloat cap_mat_diffuse[]   = {0.0f, 0.0f, 0.5f, 1.0f};  //定義材質的漫反射光顏色，偏藍色

GLfloat red_mat_ambient[]   = {0.9f, 0.0f, 0.0f, 1.0f};
GLfloat red_mat_specular[] = {1.0f, 0.0f, 0.0f, 1.0f};   //定義材質的鏡面反射光顏色，紅色
GLfloat red_mat_diffuse[]   = {0.0f, 0.0f, 0.5f, 1.0f};

GLfloat green_mat_ambient[]   = {0.0, 0.0, 0.0, 1.0f};
GLfloat green_mat_diffuse[] = {0.1, 0.35, 0.1, 1.0f};   //定義材質的鏡面反射光顏色，紅色
GLfloat green_mat_specular[]   = {0.633f, 0.727811f, 0.633f, 1.0f};
GLfloat green_shininess[] = { 0.6 };

GLfloat no_mat[] = { 1.0, 1.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 1.0, 0.5, 1.0, 1.0 };
GLfloat mat_ambient_color[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_specular[] = { 0.0, 0.6, 0.5, 1.0 };
GLfloat no_shininess[] = { 0.1 };
GLfloat low_shininess[] = { 5.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 0.3, 0.2, 0.2, 0.0 };
static int angle = 0, neck = 0, lshoulder = -5, lelbow = -10, rshoulder = 5, relbow = 10,
lhips = 5, rhips = -5, lfoot = 10, rfoot = -10, flagneck = 0, flaglshoulder = 0,
flaglelbow = 0, flagrshoulder = 0, flagrelbow = 0, flaglhips = 0,
flagrhips = 0, flaglfoot = 0, flagrfoot = 0,RLS_X=1,RLS_Y=0,RLS_Z=0;

void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 5.0, 10.0, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(0, 0, 0, 0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void draw_body(){

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(0.5, 1, 0.4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, cap_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	glutSolidCube(4);
	glPopMatrix();

}
void draw_cap(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, cap_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, cap_mat_ambient);

	glTranslatef(0, 5.0, 0);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 1, 0);
	glutSolidTeapot(0.75);

	glPopMatrix();
}
void draw_leye(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, cap_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, cap_mat_ambient);

	glTranslatef(-0.2, 4, 1);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(-0.2, 0.5, 0.5);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}
void draw_reye(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, cap_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, cap_mat_ambient);

	glTranslatef(0.2, 4, 1);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0.2, 0.5, 0.5);
	glutWireSphere(0.2, 100, 300);

	glPopMatrix();
}
void draw_mouth(){}
void draw_L_shoulder(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, green_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, green_mat_ambient);
	glTranslatef(1.5, 3, 0);
	glRotatef(lshoulder, 1, 0, 0);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lelbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -2, 0);
	glutSolidCube(3);

    glTranslatef(0, -2, 0);
	glutSolidCone(1.5,3,10,10);

	glPopMatrix();
}
void draw_R_shoulder(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, green_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, green_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, green_mat_ambient);
	glTranslatef(-1.5, 3, 0);
	glRotatef(rshoulder, RLS_X, RLS_Y, RLS_Z);

	glTranslatef(0, -0.5, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(relbow, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -2, 0);
	glutSolidCube(3);

    glTranslatef(0, -2, 0);
	glutSolidCone(1.5,3,10,10);

	glPopMatrix();
}
void draw_Mouth(){
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0,3.5,1);
	//glTranslatef(0, 3.5, 0.5);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 0.5, 0.5);
	glScalef(0.6, 0.4, 0.4);
	glMaterialfv(GL_FRONT, GL_AMBIENT, red_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, red_mat_ambient);
	glutSolidCube(0.6);
	glPopMatrix();
}
void draw_R_foot(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, red_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, red_mat_ambient);

	glTranslatef(-0.6, -0.6, 0);
	glRotatef(lfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}
void draw_L_foot(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, red_mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, red_mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, red_mat_ambient);

	glTranslatef(0.6, -0.6, 0);
	glRotatef(rfoot, 1, 0, 0);
	glTranslatef(0, -1, 0);
	glScalef(0.4, 1, 0.5);
	glutSolidCube(2);

	glScalef(1 / 0.4, 1 / 1, 1 / 0.5);
	glTranslatef(0, -1.4, 0);
	glRotatef(lhips, 1, 0, 0);
	glutWireSphere(0.4, 200, 500);

	glScalef(0.4, 1, 0.5);
	glTranslatef(0, -1.4, 0);
	glutSolidCube(2);

	glPopMatrix();
}
void draw_head(){
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glTranslatef(0, 3.5, 0);
	glRotatef(neck, 0, 0, 1);
	glTranslatef(0, 1, 0);
	glutWireSphere(1.3, 200, 500);

	glPopMatrix();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();

	glRotatef(angle, 0, 1, 0);

	glTranslatef(0, 4, 0);
	draw_body();
    draw_leye();
	draw_reye();
	draw_Mouth();
	draw_head();
	draw_cap();
	draw_L_shoulder();
	draw_R_shoulder();
	//draw_mouth();
	draw_R_foot();
	draw_L_foot();
	/*draw_body();
	draw_leye();
	draw_reye();
	draw_mouth();
	draw_head();

	draw_leftshoulder();
	draw_rightshoulder();

	draw_leftfoot();
	draw_rightfoot();*/

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(74.0f, (GLfloat)w / (GLfloat)h, 1.0f, 1000.0f);
	//glOrtho(-8,8,-8,8,-10,10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 4.0, 10, 0.0, 4, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w':
		if (flaglshoulder)
		{
			lshoulder += 5;
			if (lshoulder >= 60)flaglshoulder = 0;
		}
		else
		{
			lshoulder -= 5;
			if (lshoulder <= -60)flaglshoulder = 1;
		}
		if (flagrshoulder)
		{
			rshoulder -= 5;
			if (rshoulder <= -60)flagrshoulder = 0;
		}
		else
		{
			rshoulder += 5;
			if (rshoulder >= 60)flagrshoulder = 1;
		}

		if (flaglfoot)
		{
			lfoot += 5;
			if (lfoot >= 60)flaglfoot = 0;
		}
		else
		{
			lfoot -= 5;
			if (lfoot <= -60)flaglfoot = 1;
		}
		if (flagrfoot)
		{
			rfoot -= 5;
			if (rfoot <= -60)flagrfoot = 0;
		}
		else
		{
			rfoot += 5;
			if (rfoot >= 60)flagrfoot = 1;
		}

		 if(flaglelbow)
		{
		lelbow+=3;
		if(lelbow>=60)flaglelbow=0;
		}
		else
		{
		lelbow-=3;
		if(lelbow<=-60)flaglelbow=1;
		}
		if(flagrelbow)
		{
		relbow+=3;
		if(relbow>=60)flagrelbow=0;
		}
		else
		{
		relbow-=3;
		if(relbow<=-60)flagrelbow=1;
		}
		if(flagrhips)
		{
		rhips+=3;
		if(rhips>=60)flagrhips=0;
		}
		else
		{
		rhips-=3;
		if(rhips<=-60)flagrhips=1;
		}
		if(flaglhips)
		{
		lhips+=3;
		if(lhips>=60)flaglhips=0;
		}
		else
		{
		lhips-=3;
		if(lhips<=-60)flaglhips=1;
		}

		glutPostRedisplay();
		break;
    case 'n':
		if (flagneck)
		{
			neck = neck + 5;
			if (neck >= 30)flagneck = 0;
		}
		else {
			neck = neck - 5;
			if (neck <= -30)flagneck = 1;
		}
		glutPostRedisplay();
		break;
    case '6':
		if (flaglelbow)
		{
			lelbow += 5;
			if (lelbow >= 60)flaglelbow = 0;
		}
		else
		{
			lelbow -= 5;
			if (lelbow <= -60)flaglelbow = 1;
		}
		glutPostRedisplay();
		break;
    case '7':
		if (flagrelbow)
		{
		    RLS_Z=1;
		    RLS_X=0;
			rshoulder += 5;
			if (rshoulder >= 0)flagrelbow = 0;
		}
		else
		{
            RLS_Z=1;
		    RLS_X=0;
			rshoulder -= 5;
			if (rshoulder <= -120){
                if (flagrelbow)
                {
                    relbow += 5;
                    if (relbow >= 60)flagrelbow = 0;
                }
            else
                {
                    relbow -= 5;
                if (relbow <= -60)flagrelbow = 1;
                }

                    //flagrelbow = 1;
			}
		}
		glutPostRedisplay();
		break;
    case 'o':
        RLS_X=1;
        RLS_Y=0;
        RLS_Z=0;
        lelbow=0;
        relbow=0;
        rfoot=0;lfoot=0;
        lshoulder=0;rshoulder=0;
        lhips=0;rhips=0;
        neck=0;
		glutPostRedisplay();
		break;
    }
}


int main(int argc, char** argv)
{

    cout<<"按 o 為立正"<<endl;
    cout<<"按 w 為走路"<<endl;
    cout<<"按 6 為抬起左手肘"<<endl;
    cout<<"按 7 為旋轉手臂同時抬起手肘"<<endl;
    cout<<"按 n 為轉動脖子"<<endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RED);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
