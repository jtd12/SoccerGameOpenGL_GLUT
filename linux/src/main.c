#include"game.h"
void shows();
void shows2();
void Reshapes(int width, int height);
void special(int key, int x, int y);
void specialUP(int key , int x, int y);
void gestionkey(unsigned char key, int x, int y);
void gestionUP(unsigned char key, int x, int y);
void motion(int x, int y);
void motionUP(int x, int y);
char x='a';
int windowName;
game g;
game g2;
game g3;
game g4;
int main(int argc, char *argv[])
{


glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowPosition(200,100);
glutInitWindowSize(960,540);	//Optionnel
windowName = glutCreateWindow("soccer game OpenGL !");
//glutFullScreen();	//Optionnel
glutReshapeFunc(Reshapes);
g.initGL();
glutDisplayFunc(shows);

glutSpecialFunc(special);
glutSpecialUpFunc(specialUP);
glutKeyboardFunc(gestionkey);
glutKeyboardUpFunc(gestionUP);
glutMotionFunc(motion);
glutPassiveMotionFunc(motionUP);






glutPostRedisplay();
glutMainLoop();




return 0;
}

void shows()
{

	g.show();
}

void Reshapes(int width, int height)
{

	g.Reshape(width,height);
}
void special(int key, int x, int y)
{
	g.special(key,x,y);
}
void specialUP(int key , int x, int y)
{
	g.specialUP(key,x,y);
}
void gestionkey(unsigned char key, int x, int y)
{
	g.ControlKeyboard(key,x,y);
	g.gestion(key,x,y);
}
void gestionUP(unsigned char key, int x, int y)
{
	g.passiveKeyboard(key,x,y);
	g.gestionUP(key,x,y);
}
void motion( int x, int y)
{
	g.motion(x,y);
	
}
void motionUP(int x, int y)
{
	g.passiveMotion(x,y);
}
