#include"game.h"

game::game()
{
	
           


      	
     




}
void game::initGL()
{
	
	 p=new putthem();
     
}

game::~game()
{

delete p;
//	killskybox();
}

void game::ControlKeyboard(char key,int x, int y)
{
	//playerCam_->cam.ControlKeyboard( key, x,  y);
}
void game::passiveKeyboard(char key,int x, int y)
{
	//playerCam_->cam.passiveKeyboard( key,x,  y);
}
void game::motion(int x, int y)
{
p->activeCam(x,y);
}
void game::passiveMotion(int x, int y)
{
	p->desactiveCam(x,y);
}
void game::special(int key, int x, int y)
{

	switch(key)
	{
		case GLUT_KEY_UP:
		   		p->control(true);
											glutPostRedisplay();
							
			break;
			case GLUT_KEY_DOWN:
																	p->control2(true);
											glutPostRedisplay();
									
				break;
				case GLUT_KEY_RIGHT:
																	p->control3(true);
											glutPostRedisplay();
							
					break;
					case GLUT_KEY_LEFT:
									p->control4(true);
										glutPostRedisplay();

						break;
						
						
						
	}
}
void game::specialUP(int key , int x, int y)
{
	
		switch(key)
	{
		case GLUT_KEY_UP:
		  		p->control(false);
											glutPostRedisplay();
							
			break;
			case GLUT_KEY_DOWN:
														p->control2(false);
											glutPostRedisplay();
									
				break;
				case GLUT_KEY_RIGHT:
														p->control3(false);
											glutPostRedisplay();
							
					break;
					case GLUT_KEY_LEFT:
					p->control4(false);
										glutPostRedisplay();

						break;
					
					}
}
void game:: gestion(char key, int x, int y)
{
	
	switch(key)
	{
		case 27:
			glutDestroyWindow(0);
			exit(0);
			break;
		case 'v':
			p->control5(true,false);
break;
case 'c':

			
	 	 	
p->startGame();
														
		  									

	
break;
case 'm':
p->modeCam();
	break;



	


	

	




}
	
}
void game:: gestionUP(char key, int x, int y)
{
	
	switch(key)
	{
		case 'v':
			p->control5(false,false);
break;



	}




}
void game::Reshape(int width,int height)
{
glClearColor(.8,.8,.8,0.9);	//Change la couleur du fond
glEnable(GL_DEPTH_TEST);	//Active le depth test
glEnable(GL_LIGHTING);	// Active l'éclairage
glEnable(GL_LIGHT0);
glEnable(GL_COLOR_MATERIAL);

glViewport(0,0,width,height);// definition de la taille d'affichage de l'angle de la camera
glMatrixMode(GL_PROJECTION);// on chosit le mode projection de la matrice 
glLoadIdentity();// on initialise la matrice
gluPerspective(80,float (960.0)/float (540.0),0.1f,5000); // on dit qu'on travaille en mode perspective avec une focale et un point de vue
glMatrixMode(GL_MODELVIEW);// on change de mode d'affichage, on reload une nouvelle matrice de transformation de modelisation
}
void game::update()
 {
 p->update();	
 }
void game::show()
{
	

update();
	
p->show();

glFlush();
glutPostRedisplay();// reafraichissement automatique de la scene à chaque image calculées
glutSwapBuffers();// echange de tampons pour ahever laffichage glut glutPostRedisplay();// rafraichissement de la scene en continue

}


