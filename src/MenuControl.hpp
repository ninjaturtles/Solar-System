#include <GL/glew.h>
#include <GL/glut.h>
#include "glaux.h" // for reading bmp files

#include "Camera.hpp"
#include "Light.hpp"
#include "solar/Solar.hpp"
#include "Point.hpp"
#include "pixmap/RGBpixmap.h"

RGBpixmap pix[10];   // make six pixmaps

GLint winWidth = GetSystemMetrics(SM_CXSCREEN);
GLint winHeight = GetSystemMetrics(SM_CYSCREEN);
GLfloat red = 1.0, green = 1.0, blue = 1.0;
GLint moving = 0, xBegin = 0, coordinate = 1, type = 4, selected = 0, solarAnimation = 1, Ptgen = 1, BCgen = 0, BCRotation = 0;
bool isShading = false;
bool isTexture = false;
bool isSolar = false;

//Declare a world containing all objects
Camera myCamera;
Light myLight;
Solar mySolar;

// light properties
GLfloat ambient[] = { 0.1f, 0.1f, 0.3f, 1.0f };
GLfloat diffuse[] = { .6f, .6f, 1.0f, 1.0f };
GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat positionSolar[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat position[] = { 1.8, 1.8, 1.5, 1.0 };
GLfloat lmodel_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
GLfloat local_view[] = { 0.0 };

//Material
GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
GLfloat mat_ambient_color[] = { 1, 1, 1, 1 };
GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat high_shininess[] = { 100.0 };
GLfloat mat_emission[] = { 1, 1, 1, 1 };

//function prototypes
void reset(void);
void close(void);
void move(); // cube
void animate_solar(int); // solar system


void LightMenu(GLint transOption) {
	coordinate = 4;
	type = transOption;

	if (type == 10) {
		myLight.On = true;
	}
	if (type == 11) {
		myLight.On = false;
	}
	glutPostRedisplay();
}

void mainMenu(GLint option) {
	switch(option) {
	case 1:
		reset();
		break;
	case 2:
		close();
		break;
	}
	glutPostRedisplay();
}

void menu() {

	GLint Light_Menu = glutCreateMenu(LightMenu);
	glutAddMenuEntry(" On ", 1);
	glutAddMenuEntry(" Off ", 2);

	// main menu
	glutCreateMenu(mainMenu);
	glutAddMenuEntry(" Reset ", 1);
	glutAddSubMenu(" Light ", Light_Menu);
	glutAddMenuEntry(" Quit ", 2);
}
