#ifndef DEF_GAME_H
#define DEF_GAME_H
#include <GL/freeglut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<iostream>
#include"putthemtogether.h"
#include <iostream>
#include <sstream>
#include <math.h>

class game
{

	putthem *p;
	public:
		
game();
~game();
void update();
void show();
void initGL();
void Reshape(int width, int height);
void special(int key, int x, int y);
void specialUP(int key , int x, int y);
void gestion(char key, int x, int y);
void gestionUP(char key, int x, int y);
void ControlKeyboard(char key,int x, int y);
void passiveKeyboard(char key,int x, int y);
void motion(int x, int y);
void passiveMotion(int x, int y);

};
#endif
