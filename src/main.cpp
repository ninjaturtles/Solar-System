

#include "MenuControl.hpp"

void init(void) {
	//myLight.translate(1.5, 1.5, 1.5);
	glClearColor(0.0, 0.0, 0.0, 1.0);

	// Smooth out lines
	glEnable(GL_LINE_SMOOTH);
	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel(GL_SMOOTH);

	// load and and set texture
	pix[0].readBMPFile("bmp/texture_sun.bmp"); // make pixmap from image
	pix[0].setTexture(0);	// create texture
	pix[1].readBMPFile("bmp/texture_venus.bmp");
	pix[1].setTexture(1);
	pix[2].readBMPFile("bmp/texture_mercury.bmp");
	pix[2].setTexture(2);
	pix[3].readBMPFile("bmp/texture_earth.bmp");
	pix[3].setTexture(3);
	pix[4].readBMPFile("bmp/texture_moon.bmp");
	pix[4].setTexture(4);
	pix[5].readBMPFile("bmp/texture_mars.bmp");
	pix[5].setTexture(5);
	pix[6].readBMPFile("bmp/texture_jupiter.bmp");
	pix[6].setTexture(6);
	pix[7].readBMPFile("bmp/texture_saturn.bmp");
	pix[7].setTexture(7);
	pix[8].readBMPFile("bmp/texture_uranus.bmp");
	pix[8].setTexture(8);
	pix[9].readBMPFile("bmp/texture_neptune.bmp");
	pix[9].setTexture(9);

	//set texture for Solar system
	mySolar.Sun->textureID = 0;
	mySolar.Venus->textureID = 1;
	mySolar.Mercury->textureID = 2;
	mySolar.Earth->textureID = 3;
	mySolar.Moon->textureID = 4;
	mySolar.Mars->textureID = 5;
	mySolar.Jupiter->textureID = 6;
	mySolar.Saturn->textureID = 7;
	mySolar.Uranus->textureID = 8;
	mySolar.Neptune->textureID = 9;
}


void reset(void) {
	glutIdleFunc(NULL);
	glUseProgram(0);
	selected = 2;
	Ptgen = 1;
	BCgen = 0;
	BCRotation = 0;
	solarAnimation = 0;
	isSolar = false;
	isShading = false;
	isTexture = false;
	glDisable(GL_CULL_FACE);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_NORMALIZE);
	glDisable(GL_COLOR_MATERIAL);
	glDisable( GL_LIGHTING );
	glDisable(GL_LIGHT0);
	mySolar.reset();
	glFlush();
	glutPostRedisplay();
}

void close(void) {
	exit(1);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myCamera.setProjectionMatrix();
	mySolar.draw();

	glFlush();
	glutSwapBuffers();
}

void winReshapeFcn(GLint newWidth, GLint newHeight) {
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	winWidth = newWidth;
	winHeight = newHeight;
}

void keyboardAction(int key, int x, int y) {
	switch(key)
	{
	case GLUT_KEY_UP:
	moving = 1;
	type = 1;
	break;
	case GLUT_KEY_DOWN:
	//do something here
		moving = 1;
		type = 2;
	break;
	case GLUT_KEY_LEFT:
	//do something here
		moving = 1;
	break;
	case GLUT_KEY_RIGHT:
	//do something here
		moving = 1;
	break;
	}
	glutPostRedisplay();
}

void keyboardMotion(GLint key, GLint x, GLint y) {
	GLfloat rx, ry, rz, theta;

	if (moving == 1) {
		if (type == 1) {
			theta = 1;
			//myCamera.rotate(1.0, 0.0, 0.0, theta*0.5);
			myCamera.translate(theta*0.5, 0.0, 0.0);
		} else if (type == 2) {
			theta = -1;
			//myCamera.rotate(0.0, 1.0, 0.0, theta*0.5);
			myCamera.translate(theta*0.5, 0.0, 0.0);
		} else if (type == 3) {
			theta = (xBegin - x < 0) ? 1 : -1;
			myCamera.rotate(0.0, 0.0, 1.0, theta*0.5);
		} else if (type == 4) {
			theta = (xBegin - x < 0) ? 1 : -1;
			myCamera.translate(theta*0.5, 0.0, 0.0);
		} else if (type == 5) {
			theta = (xBegin - x < 0) ? 1 : -1;
			myCamera.translate(0.0, theta*0.5, 0.0);
		} else if (type == 5) {
			theta = (xBegin - x < 0) ? 1 : -1;
			myCamera.translate(0.0, 0.0, theta*0.5);
		}

	}
	glutPostRedisplay();
}


void animate_solar(int keepGoing) {
      mySolar.Sun->rotate_mc(0, -1, 0, 0.5);

      mySolar.Mercury->rotate_mc(mySolar.Mercury->getMC().mat[0][0], mySolar.Mercury->getMC().mat[1][0], mySolar.Mercury->getMC().mat[2][0], 1);
      mySolar.Mercury->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Venus->rotate_mc(mySolar.Venus->getMC().mat[0][0], mySolar.Venus->getMC().mat[1][0], mySolar.Venus->getMC().mat[2][0], 1);
      mySolar.Venus->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Earth->rotate_mc(mySolar.Earth->getMC().mat[0][0], mySolar.Earth->getMC().mat[1][0], mySolar.Earth->getMC().mat[2][0], 1);
      mySolar.Earth->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Moon->rotate_mc(mySolar.Moon->getMC().mat[0][0], mySolar.Moon->getMC().mat[1][0], mySolar.Moon->getMC().mat[2][0], 1);
      mySolar.Moon->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);
      mySolar.Moon->rotate_relative(mySolar.Earth->getMC().mat[0][3], mySolar.Earth->getMC().mat[1][3], mySolar.Earth->getMC().mat[2][3],  0, -1, 0, 0.5);

      mySolar.Mars->rotate_mc(mySolar.Mars->getMC().mat[0][0], mySolar.Mars->getMC().mat[1][0], mySolar.Mars->getMC().mat[2][0], 3);
      mySolar.Mars->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Jupiter->rotate_mc(mySolar.Jupiter->getMC().mat[0][0], mySolar.Jupiter->getMC().mat[1][0], mySolar.Jupiter->getMC().mat[2][0], 1);
      mySolar.Jupiter->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Saturn->rotate_mc(mySolar.Saturn->getMC().mat[0][0], mySolar.Saturn->getMC().mat[1][0], mySolar.Saturn->getMC().mat[2][0], 1);
      mySolar.Saturn->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Uranus->rotate_mc(mySolar.Uranus->getMC().mat[0][0], mySolar.Uranus->getMC().mat[1][0], mySolar.Uranus->getMC().mat[2][0], 1);
      mySolar.Uranus->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

      mySolar.Neptune->rotate_mc(mySolar.Neptune->getMC().mat[0][0], mySolar.Neptune->getMC().mat[1][0], mySolar.Neptune->getMC().mat[2][0], 1);
      mySolar.Neptune->rotate_relative(mySolar.Sun->getMC().mat[0][3], mySolar.Sun->getMC().mat[1][3],  mySolar.Sun->getMC().mat[2][3], 0, -1, 0, 1.5);

     if (keepGoing && solarAnimation == 1) {
    	  glutTimerFunc(40, animate_solar, 1);  // callback every 40 ms
      }
      glutPostRedisplay();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(winWidth, winHeight);
	glutCreateWindow("Solar System Simulation");

	init();
	menu();

	selected = 1;
	solarAnimation = 1;

	glEnable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	animate_solar(1);

	glutDisplayFunc(display);
	glutSpecialUpFunc(keyboardMotion);
	glutSpecialFunc(keyboardAction);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
