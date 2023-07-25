#include "camera.h"

void camera::lockCamera()
{
	if(camPitch>90)
		camPitch=90;
	if(camPitch<-90)
		camPitch=-90;
	if(camYaw<0.0)
		camYaw+=360.0;
	if(camYaw>360.0)
		camYaw-=360;
}

void camera::moveCamera(float dir)
{
	float rad=(camYaw+dir)*M_PI/180.0;
	loc.x+=sin(rad)*movevel*0.5f;
	loc.z-=cos(rad)*movevel*0.5f;
}

void camera::moveCameraUp(float dir)
{
	float rad=(camPitch+dir)*M_PI/180.0;
	loc.y-=sin(rad)*movevel;
		
}

camera::camera()
{
	camPitch=0;
	camYaw=0;
	movevel=0.3;
	mousevel=0.3;
	mi=ismoved=false;
up=false;
	down=false;
	right=false;
	left=false;


}
camera::camera(vector3d l)
{
	loc.change(l);
	camPitch=0;
	camYaw=0;
	movevel=0.3;
	mousevel=0.3;
	mi=ismoved=false;
	up=false;
		down=false;
	right=false;
	left=false;
}

camera::camera(vector3d l,float yaw,float pitch)
{
	loc.change(l);
	camPitch=pitch;
	camYaw=yaw;
	movevel=0.3;
	mousevel=0.3;
	mi=ismoved=false;
		up=false;
			down=false;
	right=false;
	left=false;
}

camera::camera(vector3d l,float yaw,float pitch,float mv,float mov)
{
	loc.change(l);
	camPitch=pitch;
	camYaw=yaw;
	movevel=mv;
	mousevel=mov;
	mi=false;
	up=false;
	down=false;
	right=false;
	left=false;
	p=false;
}


	/*
	if(mi)
	{
		int MidX=320;
		int MidY=240;
		SDL_ShowCursor(SDL_DISABLE);
		int tmpx,tmpy;
		SDL_GetMouseState(&tmpx,&tmpy);
		camYaw+=mousevel*(MidX-tmpx);
		camPitch+=mousevel*(MidY-tmpy);
		lockCamera();
		SDL_WarpMouse(MidX,MidY);
		Uint8* state=SDL_GetKeyState(NULL);
		ismoved=false;
		if(state[SDLK_w])
		{
			ismoved=true;
			if(camPitch!=90 && camPitch!=-90)
				moveCamera(0.0);
			//moveCameraUp(0.0);
		}else if(state[SDLK_s])
		{
			ismoved=true;
			if(camPitch!=90 && camPitch!=-90)
				moveCamera(180.0);
			//moveCameraUp(180.0);
		}		
		if(state[SDLK_a])
		{
			ismoved=true;
			moveCamera(90.0);
		}
		else if(state[SDLK_d])
		{
			ismoved=true;
			moveCamera(270);	
		}
	}
	glRotatef(-camPitch,1.0,0.0,0.0);
	glRotatef(-camYaw,0.0,1.0,0.0);
	*/
	void camera::passiveMotion(int x, int y)
	{
	
			
	
		
		ismoved=false;
		int MidX=320;
		int MidY=240;
		//glutSetCursor(GLUT_CURSOR_NONE);
	//	int tmpx,tmpy;
		//SDL_GetMouseState(&x,&y);
		camYaw=mousevel*(x);
		camPitch=mousevel*(y);
		lockCamera();
		 glutWarpPointer(x,y);

	
	}
	void camera::motion(int x, int y)
	{


		
		ismoved=false;
		int MidX=320;
		int MidY=240;
		//glutSetCursor(GLUT_CURSOR_NONE);
	//	int tmpx,tmpy;
		//SDL_GetMouseState(&x,&y);
		camYaw=mousevel*(x);
		camPitch=mousevel*(y);
		lockCamera();
		 glutWarpPointer(x,y);

	
	}
	void camera::controlSpecialKeyboard(int key,int x, int y)
	{

	}
	void camera::ControlKeyboard(char key,int x, int y)
{
	switch(key)
	{
case 27:

	exit(0);
	break;
		case 'p':
		//mi=false;
	//	glutSetCursor(GLUT_CURSOR_INFO);
		break;	
		case 'm':
		//	mi=true;
			//glutSetCursor(GLUT_CURSOR_NONE);
			break;
		
		case 'w':
	up=true;
			glutPostRedisplay();
			break;
			case 's':
				down=true;
				glutPostRedisplay();
			break;
			case 'a':
			right=true;
				glutPostRedisplay();
			break;
			case 'd':
					left=true;
				glutPostRedisplay();
			break;
				
	}

	
}

		void camera::passiveKeyboard(char key,int x, int y)
{
	switch(key)
	{
	
	
		case 'w':
			up=false;
			glutPostRedisplay();
			break;
			case 's':
				down=false;
				glutPostRedisplay();
			break;
			case 'a':
				right=false;
				glutPostRedisplay();
			break;
			case 'd':
				left=false;
				glutPostRedisplay();
			break;
				
	}

	
}

void camera::Control()
 {
 
 
 	if(up)
{
		ismoved=true;
	
	
			if(camPitch!=90 && camPitch!=-90)
				moveCamera(0.0);
				
			moveCameraUp(0.0);
		
}
else if(down)
{
		ismoved=true;

			if(camPitch!=90 && camPitch!=-90)
				moveCamera(180.0);
			moveCameraUp(180.0);
}
if(right)
{
		ismoved=true;
		
			moveCamera(270.0);
}
if(left)
{
		ismoved=true;	
	
			moveCamera(90);
}

 }
	


void camera::UpdateCamera()
{
	
	glRotatef(camPitch,1.0,0.0,0.0);
	glRotatef(camYaw,0.0,1.0,0.0);
	glTranslatef(-loc.x,-loc.y,-loc.z);

}

//change the spherical coordinate system to cartesian
vector3d camera::getVector()
{
	//Google->spherical to cartesian
 	return (vector3d(-cos(camPitch*M_PI/180.0)*sin(camYaw*M_PI/180.0),sin(camPitch*M_PI/180.0),-cos(camPitch*M_PI/180.0)*cos(camYaw*M_PI/180.0)));
}
vector3d camera::getLocation()
{
	return loc;
}

float camera::getPitch()
{
	return camPitch;
}

float camera::getYaw()
{
	return camYaw;
}
float camera::getMovevel()
{
	return movevel;
}
float camera::getMousevel()
{
	return mousevel;
}

bool camera::isMouseIn()
{
	return mi;
}
		
void camera::setLocation(vector3d vec)
{
	loc.change(vec);
}
void camera::setLocation2(vector3d vec)
{
	loc+=vec;
}
void camera::lookAt(float pitch,float yaw)
{
	camPitch=pitch;
	camYaw=yaw;
}

void camera::mouseIn(bool b)
{
	mi=b;
}

void camera::setSpeed(float mv,float mov)
{
	movevel=mv;
	mousevel=mov;
}

bool camera::isMoved()
{
	return ismoved;
}
