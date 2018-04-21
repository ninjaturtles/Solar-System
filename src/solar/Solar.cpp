#include "Solar.hpp"

Solar::Solar() {
	Sun = new Sphere();
	Venus = new Sphere();
	Mercury = new Sphere();
	Earth = new Sphere();
	Moon = new Sphere();
	Mars = new Sphere();
	Jupiter = new Sphere();
	Saturn = new Sphere();
	Uranus = new Sphere();
	Neptune = new Sphere();

	Sun->radius = 0.7;
	Sun->translate(0, 0, 0);

	Mercury->radius = 0.2;
	Mercury->translate(1.1, 0, 0);

	Venus->radius = 0.25;
	Venus->translate(1.7, 0, 0);

	Earth->radius = 0.19;
	Earth->translate(2.3, 0, 0);

	Moon->radius = 0.05;
	Moon->translate(2.6, 0, 0);

	Mars->radius = 0.15;
	Mars->translate(2.75, 0, 0);

	Jupiter->radius = 0.35;
	Jupiter->translate(3.5, 0, 0);

	Saturn->radius = .32;
	Saturn->translate(4.5, 0, 0);

	Uranus->radius = 0.234;
	Uranus->translate(5.5, 0, 0);

	Neptune->radius = 0.225;
	Neptune->translate(6, 0, 0);
}


void Solar::draw() { /*1: wire, 4: bitmap */

	// material setting for the sun
	GLfloat matAmb1[] = { 0.7, 0.53, 0.3, 1.0 }; //ambient
	GLfloat matDif1[] = { 0.76, 0.57, 0.16, 1.0 }; //diffuse
	GLfloat matSpec1[] = { 1.0, 0.15, 0.0, 1.0 }; //specular
	GLfloat matEm1[] = { 0.75, 0.588, 0.0, 1.0 }; //emission
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif1);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec1);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm1);
	Sun->draw();

	// material setting for the Mercury
	GLfloat matAmb3[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif3[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec3[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm3[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif3);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec3);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm3);
	Mercury->draw();


	// material setting for the Venus
	GLfloat matAmb4[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif4[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec4[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm4[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb4);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif4);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec4);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm4);
	Venus->draw();

	// material setting for the earth
	GLfloat matAmb5[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif5[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec5[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm5[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb5);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif5);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec5);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm5);
	Earth->draw();

	// material setting for the moon
	GLfloat matAmb6[] = { 0.2, 0.2, 0.25, 1.0 };
	GLfloat matDif6[] = { 0.8, 0.8, 0.95, 1.0 };
	GLfloat matSpec6[] = { 0.3, 0.3, 1.0, 1.0 };
	GLfloat matEm6[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb6);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif6);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec6);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm6);
	Moon->draw();

	// material setting for the Mars
	GLfloat matAmb7[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif7[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec7[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm7[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb7);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif7);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec7);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm7);
	Mars->draw();

	// material setting for the Jupiter
	GLfloat matAmb8[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif8[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec8[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm8[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb8);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif8);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec8);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm8);
	Jupiter->draw();

	// material setting for the Saturn
	GLfloat matAmb9[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif9[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec9[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm9[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb9);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif9);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec9);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm9);
	Saturn->draw();

	// material setting for the Uranus
	GLfloat matAmb10[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif10[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec10[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm10[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb10);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif10);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec10);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm10);
	Uranus->draw();

	// material setting for the Neptune
	GLfloat matAmb11[] = { 0.1, 0.1, 0.2, 1.0 };
	GLfloat matDif11[] = { 0.4, 0.74, 0.7, 1.0 };
	GLfloat matSpec11[] = { 1.0, 0.8, 0.7, 1.0 };
	GLfloat matEm11[] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, matAmb11);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDif11);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec11);
	glMaterialfv(GL_FRONT, GL_EMISSION, matEm11);
	Neptune->draw();
}

void Solar::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	Sun->translate(tx, ty, tz);
	Mercury->translate(tx, ty, tz);
	Venus->translate(tx, ty, tz);
	Earth->translate(tx, ty, tz);
	Moon->translate(tx, ty, tz);
	Mars->translate(tx, ty, tz);
	Jupiter->translate(tx, ty, tz);
	Saturn->translate(tx, ty, tz);
	Uranus->translate(tx, ty, tz);
	Neptune->translate(tx, ty, tz);
}

void Solar::rotate_origin(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Sun->rotate_origin(rx, ry, rz, angle);
	Mercury->rotate_origin(rx, ry, rz, angle);
	Venus->rotate_origin(rx, ry, rz, angle);
	Earth->rotate_origin(rx, ry, rz, angle);
	Moon->rotate_origin(rx, ry, rz, angle);
	Mars->rotate_origin(rx, ry, rz, angle);
	Jupiter->rotate_origin(rx, ry, rz, angle);
	Saturn->rotate_origin(rx, ry, rz, angle);
	Uranus->rotate_origin(rx, ry, rz, angle);
	Neptune->rotate_origin(rx, ry, rz, angle);

}

void Solar::reset() {
	Sun = new Sphere();
	Venus = new Sphere();
	Mercury = new Sphere();
	Earth = new Sphere();
	Moon = new Sphere();
	Mars = new Sphere();
	Jupiter = new Sphere();
	Saturn = new Sphere();
	Uranus = new Sphere();
	Neptune = new Sphere();

	Sun->radius = 0.7;
	Sun->translate(0, 0, 0);

	Mercury->radius = 0.2;
	Mercury->translate(1.1, 0, 0);

	Venus->radius = 0.25;
	Venus->translate(1.7, 0, 0);

	Earth->radius = 0.19;
	Earth->translate(2.3, 0, 0);

	Moon->radius = 0.05;
	Moon->translate(2.6, 0, 0);

	Mars->radius = 0.15;
	Mars->translate(2.75, 0, 0);

	Jupiter->radius = 0.35;
	Jupiter->translate(3.5, 0, 0);

	Saturn->radius = .32;
	Saturn->translate(4.5, 0, 0);

	Uranus->radius = 0.234;
	Uranus->translate(5.5, 0, 0);

	Neptune->radius = 0.225;
	Neptune->translate(6, 0, 0);
}


