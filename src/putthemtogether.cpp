#include"putthemtogether.h"

putthem::putthem()
{
	

      	mapsp.push_back(vector3d(0.1,0.2,0.1));
       unsigned int map=obj.load("data/stadium/stade.obj",&mapcp);
        unsigned int map2=obj.load("data/stadium/stade2.obj",&mapcp);
         unsigned int map3=obj.load("data/stadium/stade3.obj",&mapcp);
  unsigned int ball_=obj.load("data/balle.obj",&mapcp);
      levels.push_back(new level("name",map,mapcp,mapsp));
        levels.push_back(new level("name",map2,mapcp,mapsp));
          levels.push_back(new level("name",map3,mapcp,mapsp));
   ball=new balle("balle",ball_,collisionsphere(vector3d(0,10,0),0.5),2.1f);
    playerCam_=new playerCam("player1",collisionsphere(vector3d(0,10,0),7.5),0.02,0.3,0.8);
 
  obj.loadAnimation(anim, "data/player/player",36);
 joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(0,5,30),2.3)));
 joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(0,5,32),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(0,5,35),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(0,5,37),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,39),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,21),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,25),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,27),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,28),2.3)));
  joueur.push_back(new player(anim,rand.random(0.01,0.1),collisionsphere(vector3d(10,5,29),2.3)));
  anim.clear();
   obj.loadAnimation(anim2, "data/playerAI/playerAI",25);
    joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(5,5,0),2.3)));
 joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,20),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,25),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,23),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,22),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,24),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,26),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,28),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,21),2.3)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.01,0.05),collisionsphere(vector3d(20,5,29),2.3)));
  anim2.clear();
   obj.loadAnimation(anim3, "data/goalA/goalA",36);
  goal_.push_back(new goal(anim3,0.1,collisionsphere(vector3d(-45,5,0),2.3)));
   
  anim3.clear();
 obj.loadAnimation(anim4, "data/goalA/goalA",36);
  goal_.push_back(new goal(anim4,0.1,collisionsphere(vector3d(45,5,0),2.3)));
   
  anim4.clear();

  
    unsigned int mapsupport=obj.load("data/supporter/supporter.obj",NULL);
    unsigned int mapsupport2=obj.load("data/supporter/supporter2.obj",NULL);
    unsigned int mapsupport3=obj.load("data/supporter/supporter3.obj",NULL);
    unsigned int mapsupport4=obj.load("data/supporter/supporter4.obj",NULL);
    unsigned int mapsupport5=obj.load("data/supporter/supporter5.obj",NULL);
    
  support.push_back(new supporter("name",mapsupport));
    support.push_back(new supporter("name",mapsupport2));
      support.push_back(new supporter("name",mapsupport3));
    support.push_back(new supporter("name",mapsupport4));
    support.push_back(new supporter("name",mapsupport5));
        unsigned int mapsky=obj.load("data/sky/sky.obj",NULL);
    soleil=new sky("name",mapsky);
    
    mode=0;
    startgame=0;
 	menu=1;
 	hudTex=0;
 	hudTex1=0;
 	hudTex2=0;
 	star=0.0f;
 	partie=0;
 	   francePoint=0;
    allemagnePoint=0;
    goalTime=0.0f;
    but=false;
}
putthem::~putthem()
{
	

	delete ball;
	delete soleil;
	delete playerCam_;
	for(int i=0;i<levels.size();i++)
	delete levels[i];

	for(int i=0;i<joueur.size();i++)
	 delete joueur[i];
		for(int i=0;i<joueurAI.size();i++)
	 delete joueurAI[i];
		for(int i=0;i<goal_.size();i++)
	 delete goal_[i];				
for(int i=0;i<support.size();i++)
				delete support[i];


}
void putthem::control(bool c)
{
		for(int i=0;i<joueur.size();i++)
									
						joueur[i]->getcontrol(c);
}
void putthem::control2(bool c)
{
		for(int i=0;i<joueur.size();i++)
									
						joueur[i]->getcontrol2(c);
}
void putthem::control3(bool c)
{
		for(int i=0;i<joueur.size();i++)
									
						joueur[i]->getcontrol3(c);
}
void putthem::control4(bool c)
{
		for(int i=0;i<joueur.size();i++)
									
						joueur[i]->getcontrol4(c);
}
void putthem::control5(bool c,bool d)
{
	
												  	for(int i=0;i<joueur.size();i++)
												  	 if(joueur[i]->gethastheball()==c && limitBall()==d)
				 
															joueur[i]->setespace(c);
}
void putthem::activeCam(int x, int y)
{
	playerCam_->cam.motion(x,y);
}
void putthem::desactiveCam(int x, int y)
{
	playerCam_->cam.passiveMotion(x,y);
}
void putthem::modeCam()
{
			mode++;
																if(mode>3)
																{
																	mode=0;
																}
}
void putthem::startGame()
{
	menu++;
													if(menu>=2)
													{
														menu=2;
													}
													if(menu==2)
													{
													
													startgame++;
															if(startgame>=5)
															{
																startgame=0;
															}
														}
}
void putthem::hud()
{
		glEnable(GL_TEXTURE_2D);
if(hudTex==0)
	hudTex=obj.loadTexture("data/hud.bmp",true,1200,637);
	glPushMatrix();
	glScaled(1,1,0);

	glBindTexture(GL_TEXTURE_2D,hudTex);
	glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
 
glTexCoord2i(0,1);glVertex3i(-1,-1,-1);
glTexCoord2i(1,1);glVertex3i(+1,-1,-1);
glTexCoord2i(1,0);glVertex3i(+1,+1,-1); 
glTexCoord2i(0,0);glVertex3i(-1,+1,-1);
 

	glEnd();
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	
}
void putthem::hudJoueur()
{
	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
if(hudTex2==0)
	hudTex2=obj.loadTexture("data/allemagne.bmp",true,120,120);
	glPushMatrix();
	glTranslated(-0.7,0.8,0);
	glScaled(0.05,0.05,0);

	glBindTexture(GL_TEXTURE_2D,hudTex2);
	glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
 
glTexCoord2i(0,1);glVertex3i(-1,-1,-1);
glTexCoord2i(1,1);glVertex3i(+1,-1,-1);
glTexCoord2i(1,0);glVertex3i(+1,+1,-1); 
glTexCoord2i(0,0);glVertex3i(-1,+1,-1);

glEnd();

	glPopMatrix();
glDisable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_2D);
		glPushMatrix();
		if(hudTex1==0)
	hudTex1=obj.loadTexture("data/france.bmp",true,120,120);
	glPushMatrix();
	glTranslated(-0.1,0.8,0);
	glScaled(0.05,0.05,0);

	glBindTexture(GL_TEXTURE_2D,hudTex1);
	glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
 
glTexCoord2i(0,1);glVertex3i(-1,-1,-1);
glTexCoord2i(1,1);glVertex3i(+1,-1,-1);
glTexCoord2i(1,0);glVertex3i(+1,+1,-1); 
glTexCoord2i(0,0);glVertex3i(-1,+1,-1);

glEnd();

	glPopMatrix();
glDisable(GL_TEXTURE_2D);

}

void putthem::drawHud()
{
	
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0,0,1,0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	drawText(0.0,0.1,"Hello!"); 
	hud();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	
}
void putthem::drawHudJoueur()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.5,2,5,5);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	enable2D(960,540);
	hudJoueur();
	
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

void putthem:: drawText(float x, float y, std::string text) {
    glRasterPos2f(x, y);
    glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void putthem::update()
{
   
     	//playerCam_->update(levels[0]->getCollisionPlanes());
     

 


    updateGame();
	


	cameras_setup();
   
   							


	//ball->getLocationY(ball->getspeed());
		
				
			

}

void putthem::updateGame()
{
	if(menu==2)
	{/*
	 joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(0,10,0),2.5)));
 joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-10,10,10),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-10,10,5),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-20,10,-20),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-20,10,-10),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-30,10,10),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-30,10,-10),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-40,10,0),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.2),collisionsphere(vector3d(-40,10,-5),2.5)));
  joueur.push_back(new player(anim,rand.random(0.05,0.5),collisionsphere(vector3d(-40,10,-10),2.5)));
  anim.clear();
   obj.loadAnimation(anim2, "data/playerAI/playerAI",25);
    joueurAI.push_back(new playerAI(anim2,0.1,collisionsphere(vector3d(5,10,0),2.5)));
 joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(-0,10,10),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(10,10,5),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(20,10,-20),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(20,10,-10),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(30,10,10),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(30,10,-10),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(40,10,0),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(40,10,-5),2.5)));
  joueurAI.push_back(new playerAI(anim2,rand.random(0.05,0.2),collisionsphere(vector3d(40,10,-10),2.5)));
  anim2.clear();
  */
 
  if(startgame<3 && star<5.0f)
  {
  	 
   star+=0.01f;
  joueur[0]->movement(vector3d(0,10,0));
   joueur[1]->movement(vector3d(-10,10,10));
    joueur[2]->movement(vector3d(-10,10,5));
     joueur[3]->movement(vector3d(-20,10,-20));
      joueur[4]->movement(vector3d(-20,10,-10));
       joueur[5]->movement(vector3d(-30,10,10));
        joueur[6]->movement(vector3d(-30,10,-10));
         joueur[7]->movement(vector3d(-40,10,0));
         joueur[8]->movement(vector3d(-40,10,-5));
          joueur[9]->movement(vector3d(-40,10,-10));
           joueurAI[0]->movement(vector3d(5,10,0));
            joueurAI[1]->movement(vector3d(10,10,10));
             joueurAI[2]->movement(vector3d(10,10,5));
                joueurAI[3]->movement(vector3d(20,10,-20));
                   joueurAI[4]->movement(vector3d(20,10,-10));
                      joueurAI[5]->movement(vector3d(30,10,10));
                         joueurAI[6]->movement(vector3d(30,10,-10));
   						joueurAI[7]->movement(vector3d(40,10,0));
     						 joueurAI[8]->movement(vector3d(40,10,-5));
        					 joueurAI[9]->movement(vector3d(40,10,-10));
        				
        				}
           
    
	if(startgame>3 && star>5.0f)
{
	star+=0.01f;
	for(int i=0;i<goal_.size();i++)
	{
	
	if(goal_[i]->movement(ball->getLocation()))
											 {
											 	
											 }
										}
											
	collision();
    passerBall();
    tirerGoal();
   passerBallAI();
    movementBall();
	movement();
	movementAI();
		suivre();
		suivreAI();
separatePlayer();
		separatePlayerAI();
	
}
if(collisionGoal())
{
	but=true;
}
if(but)
{

goalTime+=0.1f;
}
if(goalTime>=15)
{
	but=false;
	goalTime=0.0f;
}
	if(limitBall()|| collisionGoal())
	{
			
	ball->setLocation(vector3d(0,15,0));
	ball->setSpeedBallJoueur(0);
	ball->setSpeedBallJoueurAI(0);
	ball->setSpeedBallJoueurAI2(0);
  joueur[0]->setLocation(vector3d(0,10,0));
 joueur[1]->setLocation(vector3d(-10,10,2));
  joueur[2]->setLocation(vector3d(-15,10,5));
  joueur[3]->setLocation(vector3d(-20,10,-10));
  joueur[4]->setLocation(vector3d(-20,10,-10));
  joueur[5]->setLocation(vector3d(-30,10,5));
  joueur[6]->setLocation(vector3d(-30,10,-10));
  joueur[7]->setLocation(vector3d(-40,10,0));
  joueur[8]->setLocation(vector3d(-40,10,-5));
  joueur[9]->setLocation(vector3d(-40,10,-10));
  
    joueurAI[0]->setLocation(vector3d(0,10,0));
 joueurAI[1]->setLocation(vector3d(10,10,10));
  joueurAI[2]->setLocation(vector3d(10,10,5));
  joueurAI[3]->setLocation(vector3d(20,10,-20));
  joueurAI[4]->setLocation(vector3d(20,10,-10));
  joueurAI[5]->setLocation(vector3d(30,10,10));
  joueurAI[6]->setLocation(vector3d(30,10,-10));
  joueurAI[7]->setLocation(vector3d(40,10,0));
  joueurAI[8]->setLocation(vector3d(40,10,-5));
  joueurAI[9]->setLocation(vector3d(40,10,-10));

	}
limitJoueur();

}
if( star>45 && star<46)
{
	partie+=1;
}
if( star>46)
{

	startgame=0;
	ball->setLocation(vector3d(0,15,0));
	star=0;
}
if(partie>=200 && star>45)
{
	partie=0;
	menu=1;
	star=0;
	startgame=0;
	ball->setLocation(vector3d(0,15,0));
	francePoint=0;
	allemagnePoint=0;
}

}

std::string putthem::int2str(int x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
std::string putthem::float2str(float x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
std::string putthem::vector2str(vector3d x) {
    // converts int to string
    std::stringstream ss;
    ss << x;
    return ss.str( );
}
void putthem::enable2D(int width, int height) {
	
		  //SDL_Color color = {255, 0, 0, 0}; // Red
	glPushMatrix();
  drawText(-1,0.9,"time:"+float2str(star)); 
	glPopMatrix();
	glPushMatrix();
  drawText(-1,0.5,"position ball"+vector2str(ball->getLocation())); 
	glPopMatrix();
	glPushMatrix();
  drawText(-1,0.2,"score:""france "+int2str(francePoint)+" - ""allemagne "+int2str(allemagnePoint)); 
	glPopMatrix();
	
	glPushMatrix();

	if(but)
	 {
  drawText(-0.5,0.1,"goal!!!!!!"); 

}
	glPopMatrix();


}
bool putthem::collisionGoal()
{


	if(ball->getLocation().x>-50 && ball->getLocation().x<-46 && ball->getLocation().z>-5 && ball->getLocation().z<5)
	{
	
		francePoint+=1;
		
		return true;
	}
		else if(ball->getLocation().x>46 && ball->getLocation().x<50 && ball->getLocation().z>-5 && ball->getLocation().z<5)
	{
	 
		allemagnePoint+=1;
		return true;
	}
else
{
		return false;
	}
}
void putthem::tirerGoal()
{
		ball->setLocationincremente(vector3d(ball->getSpeedBallgoal()*ball->getangle().x,0,ball->getSpeedBallgoal()*ball->getangle().z));
		for(int j=0;j<goal_.size();j++)
			{
				 if(goal_[j]->gethastheball()==true )
				 {
				 
						ball->setangle(vector3d(cos(goal_[j]->getRotation()*M_PI/180),0,sin(goal_[j]->getRotation()*M_PI/180)));
					
				}
}

				for(int j=0;j<goal_.size();j++)
			{
			
				if(ball->getLocation().x>-50 && ball->getLocation().x<-30 && goal_[j]->gethastheball() || ball->getLocation().x>30 && ball->getLocation().x<50 && goal_[j]->gethastheball() )
				{
					goal_[j]->setTirer(true);
					
				}

				else
				{
						
					goal_[j]->setTirer(false);
				}
			
		}
				
			
			
			
		
			
				
				
				for(int j=0;j<goal_.size();j++)
				if( 	goal_[j]->getTirer()  && ball->getSpeedBallgoal()<ball->maxSpeed_())
				{
						if(ball->getSpeedBallgoal()<0)
				{
					ball->setSpeedBallAccgoal(ball->dece());
				}
				else
				{
					ball->setSpeedBallAccgoal(ball->acce());
				}
				}
				
				
				
			
			for(int j=0;j<goal_.size();j++)
				if(goal_[j]->getTirer()==false)
			{
				if(ball->getSpeedBallgoal()-ball->dece()>0)
				{
					ball->setSpeedBallDecgoal(ball->dece());
				}
				else if(ball->getSpeedBallgoal()+ball->dece()<0)
				{
					ball->setSpeedBallDecgoal(ball->dece());
				}
				else
				{
					ball->setSpeedBallgoal(0);
				}
			
		
	}
}
void putthem::passerBall()
{
rand_= rand.random(0,1500);

float x=	ball->getSpeedBallJoueur()*ball->getangle().x;
float z=	ball->getSpeedBallJoueur()*ball->getangle().z;


	ball->setLocationincremente(vector3d(x,0,z));
	

	float distancex=joueurAI[2]->getLocation().x-ball->getLocation().x;
		float distancez=joueurAI[2]->getLocation().z-ball->getLocation().z;

float hypotenuse = sqrt((distancex * distancex) + (distancez * distancez));




		for(int j=0;j<joueur.size();j++)
			{
				 if(joueur[j]->gethastheball()==true)
				 {
				 
						ball->setangle(vector3d(cos(joueur[j]->getRotation()*M_PI/180),0,sin(joueur[j]->getRotation()*M_PI/180)));
					
				}
			}


				for(int j=0;j<joueur.size();j++)
			{
					if(joueur[j]->getespace() && joueur[j]->gethastheball())
					{
						joueur[j]->setTirer(true);
							
				}
			}
				for(int j=0;j<joueur.size();j++)
			{
				if(joueur[j]->getespace()&& joueur[j]->gethastheball()==false)
					{
					joueur[j]->setTirer(false);
					}
			}
		
				
				for(int j=0;j<joueur.size();j++)
				if(	joueur[j]->getTirer()  &&  ball->getSpeedBallJoueur()<ball->maxSpeed_())
				{
						if(ball->getSpeedBallJoueur()<0)
				{
					ball->setSpeedBallAccJoueur(ball->dece());
				}
				else
				{
					ball->setSpeedBallAccJoueur(ball->acce());
				}
				}
				
				
				
			
			for(int j=0;j<joueur.size();j++)
				if(joueur[j]->getTirer()==false)
			{
				if(ball->getSpeedBallJoueur()-ball->dece()>0)
				{
					ball->setSpeedBallDecJoueur(ball->dece());
				}
				else if(ball->getSpeedBallJoueur()+ball->dece()<0)
				{
					ball->setSpeedBallDecJoueur(ball->dece());
				}
				else
				{
					ball->setSpeedBallJoueur(0);
				}
			
		
		}
		
		
		
		
	
	
			
	 

											
	
	
}


bool putthem::limitBall()
{
	if(ball->getLocation().x>48)
	{
	return true;
	
}
else if(ball->getLocation().x<-48)
{
		return true;
}
else if(ball->getLocation().z>35)
{
			return true;
}
  else if(ball->getLocation().z<-35)
{
		return true;
}
else
{

return false;

}
}

void putthem::limitJoueur()
{
	
 if(joueur[0]->getLocation().x>49)
{
	joueur[0]->setLocation(vector3d(49,10,joueur[0]->getLocation().z));
}
 if(joueur[1]->getLocation().x>49)
{
	joueur[1]->setLocation(vector3d(49,10,joueur[1]->getLocation().z));
}
 if(joueur[2]->getLocation().x>49)
{
	joueur[2]->setLocation(vector3d(49,10,joueur[2]->getLocation().z));
}
 if(joueur[3]->getLocation().x>49)
{
	joueur[3]->setLocation(vector3d(49,10,joueur[3]->getLocation().z));
}
 if(joueur[4]->getLocation().x>49)
{
	joueur[4]->setLocation(vector3d(49,10,joueur[4]->getLocation().z));
}
 if(joueur[5]->getLocation().x>49)
{
	joueur[5]->setLocation(vector3d(49,10,joueur[5]->getLocation().z));
}
 if(joueur[6]->getLocation().x>49)
{
	joueur[6]->setLocation(vector3d(49,10,joueur[6]->getLocation().z));
}
 if(joueur[7]->getLocation().x>49)
{
	joueur[7]->setLocation(vector3d(49,10,joueur[7]->getLocation().z));
}
 if(joueur[8]->getLocation().x>49)
{
	joueur[8]->setLocation(vector3d(49,10,joueur[8]->getLocation().z));
}
 if(joueur[9]->getLocation().x>49)
{
	joueur[9]->setLocation(vector3d(49,10,joueur[9]->getLocation().z));
}
 if(joueur[0]->getLocation().x<-49)
{
	joueur[0]->setLocation(vector3d(-49,10,joueur[0]->getLocation().z));
}
 if(joueur[1]->getLocation().x<-49)
{
	joueur[1]->setLocation(vector3d(-49,10,joueur[1]->getLocation().z));
}
 if(joueur[2]->getLocation().x<-49)
{
	joueur[2]->setLocation(vector3d(-49,10,joueur[2]->getLocation().z));
}
 if(joueur[3]->getLocation().x<-49)
{
	joueur[3]->setLocation(vector3d(-49,10,joueur[3]->getLocation().z));
}
 if(joueur[4]->getLocation().x<-49)
{
	joueur[4]->setLocation(vector3d(-49,10,joueur[4]->getLocation().z));
}
 if(joueur[5]->getLocation().x<-49)
{
	joueur[5]->setLocation(vector3d(-49,10,joueur[5]->getLocation().z));
}
 if(joueur[6]->getLocation().x<-49)
{
	joueur[6]->setLocation(vector3d(-49,10,joueur[6]->getLocation().z));
}
 if(joueur[7]->getLocation().x<-49)
{
	joueur[7]->setLocation(vector3d(-49,10,joueur[7]->getLocation().z));
}
 if(joueur[8]->getLocation().x<-49)
{
	joueur[8]->setLocation(vector3d(-49,10,joueur[8]->getLocation().z));
}
 if(joueur[9]->getLocation().x<-49)
{
	joueur[9]->setLocation(vector3d(-49,10,joueur[9]->getLocation().z));
}




	
 if(joueurAI[0]->getLocation().x>49)
{
	joueurAI[0]->setLocation(vector3d(49,10,joueurAI[0]->getLocation().z));
}
 if(joueurAI[1]->getLocation().x>49)
{
	joueurAI[1]->setLocation(vector3d(49,10,joueurAI[1]->getLocation().z));
}
 if(joueurAI[2]->getLocation().x>49)
{
	joueurAI[2]->setLocation(vector3d(49,10,joueurAI[2]->getLocation().z));
}
 if(joueurAI[3]->getLocation().x>49)
{
	joueurAI[3]->setLocation(vector3d(49,10,joueurAI[3]->getLocation().z));
}
 if(joueurAI[4]->getLocation().x>49)
{
	joueurAI[4]->setLocation(vector3d(49,10,joueurAI[4]->getLocation().z));
}
 if(joueurAI[5]->getLocation().x>49)
{
	joueurAI[5]->setLocation(vector3d(49,10,joueurAI[5]->getLocation().z));
}
 if(joueurAI[6]->getLocation().x>49)
{
	joueurAI[6]->setLocation(vector3d(49,10,joueurAI[6]->getLocation().z));
}
 if(joueurAI[7]->getLocation().x>49)
{
	joueurAI[7]->setLocation(vector3d(49,10,joueurAI[7]->getLocation().z));
}
 if(joueurAI[8]->getLocation().x>49)
{
	joueurAI[8]->setLocation(vector3d(49,10,joueurAI[8]->getLocation().z));
}
 if(joueurAI[9]->getLocation().x>49)
{
	joueurAI[9]->setLocation(vector3d(49,10,joueurAI[9]->getLocation().z));
}
 if(joueurAI[0]->getLocation().x<-49)
{
	joueurAI[0]->setLocation(vector3d(-49,10,joueurAI[0]->getLocation().z));
}
 if(joueurAI[1]->getLocation().x<-49)
{
	joueurAI[1]->setLocation(vector3d(-49,10,joueurAI[1]->getLocation().z));
}
 if(joueurAI[2]->getLocation().x<-49)
{
	joueurAI[2]->setLocation(vector3d(-49,10,joueurAI[2]->getLocation().z));
}
 if(joueurAI[3]->getLocation().x<-49)
{
	joueurAI[3]->setLocation(vector3d(-49,10,joueurAI[3]->getLocation().z));
}
 if(joueurAI[4]->getLocation().x<-49)
{
	joueurAI[4]->setLocation(vector3d(-49,10,joueurAI[4]->getLocation().z));
}
 if(joueurAI[5]->getLocation().x<-49)
{
	joueurAI[5]->setLocation(vector3d(-49,10,joueurAI[5]->getLocation().z));
}
 if(joueurAI[6]->getLocation().x<-49)
{
	joueurAI[6]->setLocation(vector3d(-49,10,joueurAI[6]->getLocation().z));
}
 if(joueurAI[7]->getLocation().x<-49)
{
	joueurAI[7]->setLocation(vector3d(-49,10,joueurAI[7]->getLocation().z));
}
 if(joueurAI[8]->getLocation().x<-49)
{
	joueurAI[8]->setLocation(vector3d(-49,10,joueurAI[8]->getLocation().z));
}
 if(joueurAI[9]->getLocation().x<-49)
{
	joueurAI[9]->setLocation(vector3d(-49,10,joueurAI[9]->getLocation().z));
}




if(joueur[0]->getLocation().z>38)
{
	joueur[0]->setLocation(vector3d(joueur[0]->getLocation().x,10,38));
}
 if(joueur[1]->getLocation().z>38)
{
	joueur[1]->setLocation(vector3d(joueur[1]->getLocation().x,10,38));
}
 if(joueur[2]->getLocation().z>38)
{
	joueur[2]->setLocation(vector3d(joueur[2]->getLocation().x,10,38));
}
 if(joueur[3]->getLocation().z>38)
{
	joueur[3]->setLocation(vector3d(joueur[3]->getLocation().x,10,38));
}
 if(joueur[4]->getLocation().z>38)
{
	joueur[4]->setLocation(vector3d(joueur[4]->getLocation().x,10,38));
}
 if(joueur[5]->getLocation().z>38)
{
	joueur[5]->setLocation(vector3d(joueur[5]->getLocation().x,10,38));
}
 if(joueur[6]->getLocation().z>38)
{
	joueur[6]->setLocation(vector3d(joueur[6]->getLocation().x,10,38));
}
 if(joueur[7]->getLocation().z>38)
{
	joueur[7]->setLocation(vector3d(joueur[7]->getLocation().x,10,38));
}
 if(joueur[8]->getLocation().z>38)
{
	joueur[8]->setLocation(vector3d(joueur[8]->getLocation().x,10,38));
}
 if(joueur[9]->getLocation().z>38)
{
	joueur[9]->setLocation(vector3d(joueur[9]->getLocation().x,10,38));
}
 if(joueur[0]->getLocation().z<-38)
{
	joueur[0]->setLocation(vector3d(joueur[0]->getLocation().x,10,0));
}
 if(joueur[1]->getLocation().z<-38)
{
	joueur[1]->setLocation(vector3d(joueur[1]->getLocation().x,10,-38));
}
 if(joueur[2]->getLocation().z<-38)
{
	joueur[2]->setLocation(vector3d(joueur[2]->getLocation().x,10,-38));
}
 if(joueur[3]->getLocation().z<-38)
{
	joueur[3]->setLocation(vector3d(joueur[3]->getLocation().x,10,-38));
}
 if(joueur[4]->getLocation().z<-38)
{
	joueur[4]->setLocation(vector3d(joueur[4]->getLocation().x,10,-38));
}
 if(joueur[5]->getLocation().z<-38)
{
	joueur[5]->setLocation(vector3d(joueur[5]->getLocation().x,10,-38));
}
 if(joueur[6]->getLocation().z<-38)
{
	joueur[6]->setLocation(vector3d(joueur[6]->getLocation().x,10,-38));
}
 if(joueur[7]->getLocation().z<-38)
{
	joueur[7]->setLocation(vector3d(joueur[7]->getLocation().x,10,-38));
}
 if(joueur[8]->getLocation().z<-38)
{
	joueur[8]->setLocation(vector3d(joueur[8]->getLocation().x,10,-38));
}
 if(joueur[9]->getLocation().z<-38)
{
	joueur[9]->setLocation(vector3d(joueur[9]->getLocation().x,10,-38));
}

 



if(joueurAI[0]->getLocation().z>38)
{
	joueurAI[0]->setLocation(vector3d(joueurAI[0]->getLocation().x,10,38));
}
 if(joueurAI[1]->getLocation().z>38)
{
	joueurAI[1]->setLocation(vector3d(joueurAI[1]->getLocation().x,10,38));
}
 if(joueurAI[2]->getLocation().z>38)
{
	joueurAI[2]->setLocation(vector3d(joueurAI[2]->getLocation().x,10,38));
}
 if(joueurAI[3]->getLocation().z>38)
{
	joueurAI[3]->setLocation(vector3d(joueurAI[3]->getLocation().x,10,38));
}
 if(joueurAI[4]->getLocation().z>38)
{
	joueurAI[4]->setLocation(vector3d(joueurAI[4]->getLocation().x,10,38));
}
 if(joueurAI[5]->getLocation().z>38)
{
	joueurAI[5]->setLocation(vector3d(joueurAI[5]->getLocation().x,10,38));
}
 if(joueurAI[6]->getLocation().z>38)
{
	joueurAI[6]->setLocation(vector3d(joueurAI[6]->getLocation().x,10,38));
}
 if(joueurAI[7]->getLocation().z>38)
{
	joueurAI[7]->setLocation(vector3d(joueurAI[7]->getLocation().x,10,38));
}
 if(joueurAI[8]->getLocation().z>38)
{
	joueurAI[8]->setLocation(vector3d(joueurAI[8]->getLocation().x,10,38));
}
 if(joueurAI[9]->getLocation().z>38)
{
	joueurAI[9]->setLocation(vector3d(joueurAI[9]->getLocation().x,10,38));
}
 if(joueurAI[0]->getLocation().z<-38)
{
	joueurAI[0]->setLocation(vector3d(joueurAI[0]->getLocation().x,10,0));
}
 if(joueurAI[1]->getLocation().z<-38)
{
	joueurAI[1]->setLocation(vector3d(joueurAI[1]->getLocation().x,10,-38));
}
 if(joueurAI[2]->getLocation().z<-38)
{
	joueurAI[2]->setLocation(vector3d(joueurAI[2]->getLocation().x,10,-38));
}
 if(joueurAI[3]->getLocation().z<-38)
{
	joueurAI[3]->setLocation(vector3d(joueurAI[3]->getLocation().x,10,-38));
}
 if(joueurAI[4]->getLocation().z<-38)
{
	joueurAI[4]->setLocation(vector3d(joueurAI[4]->getLocation().x,10,-38));
}
 if(joueurAI[5]->getLocation().z<-38)
{
	joueurAI[5]->setLocation(vector3d(joueurAI[5]->getLocation().x,10,-38));
}
 if(joueurAI[6]->getLocation().z<-38)
{
	joueurAI[6]->setLocation(vector3d(joueurAI[6]->getLocation().x,10,-38));
}
 if(joueurAI[7]->getLocation().z<-38)
{
	joueurAI[7]->setLocation(vector3d(joueurAI[7]->getLocation().x,10,-38));
}
 if(joueurAI[8]->getLocation().z<-38)
{
	joueurAI[8]->setLocation(vector3d(joueurAI[8]->getLocation().x,10,-38));
}
 if(joueurAI[9]->getLocation().z<-38)
{
	joueurAI[9]->setLocation(vector3d(joueurAI[9]->getLocation().x,10,-38));
}


}

void putthem::movementBall()
{
	
		for(int j=0;j<joueur.size();j++)
		
										{
											if( joueur[j]->setcontrol()==true  || joueur[j]->setcontrol2()==true  || joueur[j]->setcontrol3()==true 
											|| joueur[j]->setcontrol4()==true)
											{
											
											if( joueur[j]->gethastheball()==true )
										
											{
												ball->setRotation(0.9f);
											
											}
											}
											else
											{
													ball->setRotation(0.0f);
											}
										}
											for(int j=0;j<joueurAI.size();j++)
		
										{
										
											
											
											if( joueurAI[j]->gethastheball()==true )
										
											{
												ball->setRotation(0.9f);
											
											}
											
											else
											{
													ball->setRotation(0.0f);
											}
										}
										
									if( ball->getLocation().x>-20.5f && ball->getLocation().x<20 && ball->getLocation().z>-20.5f && ball->getLocation().z<20  )
												{
													ball->centrer_(true);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
													
													if( ball->getLocation().x>20.0f && ball->getLocation().x<50 && ball->getLocation().z>-20.5f && ball->getLocation().z<20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(true);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
														if( ball->getLocation().x>-20.5f && ball->getLocation().x<50 && ball->getLocation().z>20.5f && ball->getLocation().z<40  )
												{
													ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(true);
													ball->centrerCoteGauche_(false);
													
												}
											
													
														if( ball->getLocation().x>-20.5f && ball->getLocation().x<50 && ball->getLocation().z>-40.5f && ball->getLocation().z<-20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(true);
													
												}
											
											
											
											
											
											
												if( ball->getLocation().x>-50.5f && ball->getLocation().x<0 && ball->getLocation().z>-20.5f && ball->getLocation().z<20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(true);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
													
													if( ball->getLocation().x>-50.0f && ball->getLocation().x<0 && ball->getLocation().z>20.5f && ball->getLocation().z<40  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(true);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
														if( ball->getLocation().x>-50.5f && ball->getLocation().x<0 && ball->getLocation().z>-40.5f && ball->getLocation().z<-20  )
												{
													ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(true);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
											
												
											
											
									
												
											
											
											
												
											
										
}

void putthem::movement()
{
	
									
										for(int j=0;j<joueurAI.size();j++)
										{
										
										for(int i=0;i<10;i++)
											{
											
													
												if(   joueur[i]->gethastheball()==false && joueur[i]->getNext()==false
												)
												{
													joueur[i]->setattaquer(true);
												}
												else
												{
													joueur[i]->setattaquer(false);
												}
											
											
										}
									}
									
										
//centrerarriere
										for(int i=0;i<4;i++)
											{
										if( ball->centrerArriere_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
											if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-10+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerArriere_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-40+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=6;i<10;i++)
											{
										if( ball->centrerArriere_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
								
									//centrercotearrieredroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteArriereDroite_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-15+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerCoteArriereDroite_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-40+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=6;i<10;i++)
											{
										if( ball->centrerCoteArriereDroite_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotearrieregauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteArriereGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-15+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerCoteArriereGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=6;i<10;i++)
											{
										if( ball->centrerCoteArriereGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centreravant
									
											for(int i=0;i<4;i++)
											{
										if( ball->centrer_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(10+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrer_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(20+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
										for(int i=9;i<10;i++)
											{
										if( ball->centrer_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-20+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerAvant_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(25+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerAvant_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(30+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerAvant_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteDroit_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(15+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteDroit_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(40+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteDroit_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-30+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(15+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(30+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteGauche_() && joueur[i]->getattaquer()&& joueur[i]->gethastheball()==false)
										{
												if( joueur[i]->setcontrol() || joueur[i]->setcontrol2()||joueur[i]->setcontrol3()||joueur[i]->setcontrol4() )
											 if(joueur[i]->movement(vector3d(-20+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
									
							
		
									
									
									
}


void putthem::movementAI()
{
	
		
							
								for(int j=0;j<joueurAI.size();j++)
	{
										
										for(int i=0;i<10;i++)
											{
											
													
												if(joueurAI[j]->gethastheball()==false  &&  joueurAI[j]->getNext()==false)
												{
													joueurAI[j]->setattaquer(true);
												
												}
											
												else
												{
													joueurAI[j]->setattaquer(false);
												
												}
											
											
										}
									}
											
										
//centrer
										for(int i=0;i<4;i++)
											{
										if( ball->centrer_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(-10+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrer_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(20+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrer_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(10+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerAvant_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(30+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerAvant_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(35+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrerAvant_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(45+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerArriere_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(5+i,0,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerArriere_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(-10+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerArriere_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(30+i,0,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteDroit_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(-15+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteDroit_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(-10+i,0,-15+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteDroit_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(10+i,0,-15+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteGauche_() && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(5+i,0,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteGauche_()  && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(-10+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteGauche_()  && joueurAI[i]->getattaquer()&& joueurAI[i]->gethastheball()==false)
										{
											
											 if(joueurAI[i]->movement(vector3d(30+i,0,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
									
												
							
										
//centrer
									
											
							
		
	
}

void putthem::collision()
{
		for(int i=0;i<joueur.size();i++)
     	 		if(  joueur[i]->getTirer()==false && collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
				
				joueur[i]->sethastheball(true);
			}
			else
			{
					joueur[i]->sethastheball(false);
			}
				for(int i=0;i<joueur.size();i++)
				{
				
			if(joueur[i]->gethastheball())
		
			{
				ball->getCollisionSphere()->center=vector3d(joueur[i]->getCollisionSphere()->center.x+ball->getFixe().x,joueur[i]->getCollisionSphere()->center.y+ball->getFixe().y-0.9f,joueur[i]->getCollisionSphere()->center.z+ball->getFixe().z);
			
			}
		}	
	
			
		
									   			for(int i=0;i<joueur.size();i++)
									   			if(joueur[i]->setcontrol())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   			ball->setFixe(vector3d(0.45f,0,0));
										   			
										   		}
										   		
										   				for(int i=0;i<joueur.size();i++)
										   					if(joueur[i]->setcontrol2())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   					ball->setFixe(vector3d(-0.45f,0,0));
										   				}
										   				
										   										for(int i=0;i<joueur.size();i++)
										   											if(joueur[i]->setcontrol3())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   					ball->setFixe(vector3d(0.0f,0,0.45f));
										   			}
										   							for(int i=0;i<joueur.size();i++)
										   							if(joueur[i]->setcontrol4())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
																	ball->setFixe(vector3d(0.0f,0,-0.45f));
														}
														
														
														
															for(int i=0;i<joueur.size();i++)
									   			if(joueur[i]->setcontrol()&& joueur[i]->setcontrol3())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   				ball->setFixe(vector3d(0.45f,0,0.45f));
										   		}
										   		
										   					
															for(int i=0;i<joueur.size();i++)
									   			if(joueur[i]->setcontrol()&& joueur[i]->setcontrol4())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   				ball->setFixe(vector3d(0.45f,0,-0.45f));
										   		}
										   		
										   				
															for(int i=0;i<joueur.size();i++)
									   			if(joueur[i]->setcontrol2()&& joueur[i]->setcontrol3())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   					ball->setFixe(vector3d(-0.45f,0,0.45f));
										   		}
										   		
										   					
															for(int i=0;i<joueur.size();i++)
									   			if(joueur[i]->setcontrol2()&& joueur[i]->setcontrol4())
     	 		if(collision::raysphere(joueur[i]->getCollisionSphere()->center.x,joueur[i]->getCollisionSphere()->center.y,joueur[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueur[i]->getCollisionSphere()->r))
			{
										   				ball->setFixe(vector3d(-0.45f,0,-0.45f));
										   		}
										   		
										   		
										   			for(int i=0;i<joueurAI.size();i++)
     	 		if(  joueurAI[i]->getTirer()==false && joueurAI[i]->getTirer2()==false && joueurAI[i]->getTirer3()==false  && 
				  joueurAI[i]->getTirer4()==false  && joueurAI[i]->getTirer5()==false  && collision::raysphere(joueurAI[i]->getCollisionSphere()->center.x,joueurAI[i]->getCollisionSphere()->center.y,joueurAI[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,joueurAI[i]->getCollisionSphere()->r))
			{
				
				joueurAI[i]->sethastheball(true);
			}
			else
			{
					joueurAI[i]->sethastheball(false);
			}
			
					for(int i=0;i<joueurAI.size();i++)
				{
			if(joueurAI[i]->gethastheball())
			{
				ball->getCollisionSphere()->center=vector3d(joueurAI[i]->getCollisionSphere()->center.x+ball->getFixe().x,joueurAI[i]->getCollisionSphere()->center.y+ball->getFixe().y-0.9f,joueurAI[i]->getCollisionSphere()->center.z+ball->getFixe().z);
				ball->setFixe(vector3d(-0.45f,0,0.0f));
				//ball->setspeed3(0);
		
					if( joueurAI[i]->movement(vector3d(-40,0,0)))
											{
											}
			}
		
			
		}	
		
				
												
										   		
										   		
		
				for(int i=0;i<goal_.size();i++)
     	 		if(  goal_[i]->getTirer()==false && collision::raysphere(goal_[i]->getCollisionSphere()->center.x,goal_[i]->getCollisionSphere()->center.y,goal_[i]->getCollisionSphere()->center.z,direction.x,direction.y,direction.z,
				ball->getCollisionSphere()->center.x,ball->getCollisionSphere()->center.y,ball->getCollisionSphere()->center.z,goal_[i]->getCollisionSphere()->r))
			{
				
				goal_[i]->sethastheball(true);
			}
			else
			{
					goal_[i]->sethastheball(false);
			}	
												
					
			
										   		
										
										   		
			
										   		
		

}
void putthem::passerBallAI()
{

		ball->setLocationincremente(vector3d(ball->getSpeedBallJoueurAI2()*ball->getangle().x,0,ball->getSpeedBallJoueurAI2()*ball->getangle().z));
		for(int j=0;j<joueurAI.size();j++)
			{
				 if(joueurAI[j]->gethastheball()==true )
				 {
				 
						ball->setangle(vector3d(cos(joueurAI[j]->getRotation()*M_PI/180),0,sin(joueurAI[j]->getRotation()*M_PI/180)));
					
				}
}

				for(int j=0;j<joueurAI.size();j++)
			{
				for(int i=0;i<joueur.size();i++)
			{
				if(ball->getLocation().x>-50 && ball->getLocation().x<-30 && joueurAI[j]->gethastheball() )
				{
					joueurAI[j]->setTirer2(true);
					
				}

				else
				{
						
					joueurAI[j]->setTirer2(false);
				}
			}
		}
				
			
			
			
		
			
				
				
				for(int j=0;j<joueurAI.size();j++)
				if( 	joueurAI[j]->getTirer2()  && ball->getSpeedBallJoueurAI2()<ball->maxSpeed_())
				{
						if(ball->getSpeedBallJoueurAI2()<0)
				{
					ball->setSpeedBallAccJoueurAI2(ball->dece());
				}
				else
				{
					ball->setSpeedBallAccJoueurAI2(ball->acce());
				}
				}
				
				
				
			
			for(int j=0;j<joueurAI.size();j++)
				if(joueurAI[j]->getTirer2()==false)
			{
				if(ball->getSpeedBallJoueurAI2()-ball->dece()>0)
				{
					ball->setSpeedBallDecJoueurAI2(ball->dece());
				}
				else if(ball->getSpeedBallJoueurAI2()+ball->dece()<0)
				{
					ball->setSpeedBallDecJoueurAI2(ball->dece());
				}
				else
				{
					ball->setSpeedBallJoueurAI2(0);
				}
			
		
	}
			
			
				
				
				
			
		
}
	
			
			
			
void putthem::separatePlayer()
{
		
		  vector3d Distance = vector3d(joueur[0]->getLocation()-ball->getLocation());
		  vector3d Distance2 = vector3d(joueur[1]->getLocation()-ball->getLocation());
		  vector3d Distance3 = vector3d(joueur[2]->getLocation()-ball->getLocation());
		  vector3d Distance4 = vector3d(joueur[3]->getLocation()-ball->getLocation());
		  vector3d Distance5 = vector3d(joueur[4]->getLocation()-ball->getLocation());
		  vector3d Distance6 = vector3d(joueur[5]->getLocation()-ball->getLocation());
		  vector3d Distance7 = vector3d(joueur[6]->getLocation()-ball->getLocation());
		  vector3d Distance8 = vector3d(joueur[7]->getLocation()-ball->getLocation());
		  vector3d Distance9 = vector3d(joueur[8]->getLocation()-ball->getLocation());
		  vector3d Distance10 = vector3d(joueur[9]->getLocation()-ball->getLocation());
/* float zDistance = joueur[0]->getLocation().z-ball->getLocation().z;
 float xDistance2 = joueur[1]->getLocationX()-ball->getLocation().x;
 float zDistance2 = joueur[1]->getLocation().z-ball->getLocation().z;
  float xDistance3 = joueur[2]->getLocationX()-ball->getLocation().x;
 float zDistance3 = joueur[2]->getLocation().z-ball->getLocation().z;
  float xDistance4 = joueur[3]->getLocationX()-ball->getLocation().x;
 float zDistance4 = joueur[3]->getLocation().z-ball->getLocation().z;
  float xDistance5 = joueur[4]->getLocationX()-ball->getLocation().x;
 float zDistance5 = joueur[4]->getLocation().z-ball->getLocation().z;
  float xDistance6 = joueur[5]->getLocationX()-ball->getLocation().x;
 float zDistance6 = joueur[5]->getLocation().z-ball->getLocation().z;
 float xDistance7 = joueur[6]->getLocationX()-ball->getLocation().x;
 float zDistance7 = joueur[6]->getLocation().z-ball->getLocation().z;
 float xDistance8 = joueur[7]->getLocationX()-ball->getLocation().x;
 float zDistance8 = joueur[7]->getLocation().z-ball->getLocation().z;
 float xDistance9 = joueur[8]->getLocationX()-ball->getLocation().x;
 float zDistance9 = joueur[8]->getLocation().z-ball->getLocation().z;
 float xDistance10 = joueur[9]->getLocationX()-ball->getLocation().x;
 float zDistance10 = joueur[9]->getLocation().z-ball->getLocation().z;
 
 */
float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));

for(int i=0;i<joueur.size();i++)
{

											if(joueur[i]->gethastheball()==true && joueur[0]->gethastheball()==false && hypotenuse<10)
											{
												joueur[0]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[1]->gethastheball()==false&& hypotenuse2<10)
											{
												joueur[1]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[2]->gethastheball()==false&& hypotenuse3<10)
											{
												joueur[2]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[3]->gethastheball()==false&& hypotenuse4<10)
											{
												joueur[3]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[4]->gethastheball()==false&& hypotenuse5<10)
											{
												joueur[4]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[5]->gethastheball()==false&& hypotenuse6<10)
											{
												joueur[5]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[6]->gethastheball()==false&& hypotenuse7<10)
											{
												joueur[6]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[7]->gethastheball()==false&& hypotenuse8<10)
											{
												joueur[7]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[8]->gethastheball()==false&& hypotenuse9<10)
											{
												joueur[8]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueur[i]->gethastheball()==true && joueur[9]->gethastheball()==false && hypotenuse10<10)
											{
												joueur[9]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
										}
										
										


}

void putthem::separatePlayerAI()
{
		vector3d Distance = vector3d(joueurAI[0]->getLocation()-ball->getLocation());
		  vector3d Distance2 = vector3d(joueurAI[1]->getLocation()-ball->getLocation());
		  vector3d Distance3 = vector3d(joueurAI[2]->getLocation()-ball->getLocation());
		  vector3d Distance4 = vector3d(joueurAI[3]->getLocation()-ball->getLocation());
		  vector3d Distance5 = vector3d(joueurAI[4]->getLocation()-ball->getLocation());
		  vector3d Distance6 = vector3d(joueurAI[5]->getLocation()-ball->getLocation());
		  vector3d Distance7 = vector3d(joueurAI[6]->getLocation()-ball->getLocation());
		  vector3d Distance8 = vector3d(joueurAI[7]->getLocation()-ball->getLocation());
		  vector3d Distance9 = vector3d(joueurAI[8]->getLocation()-ball->getLocation());
		  vector3d Distance10 = vector3d(joueurAI[9]->getLocation()-ball->getLocation());
/* float zDistance = joueurAI[0]->getLocation().z-ball->getLocation().z;
 float xDistance2 = joueurAI[1]->getLocationX()-ball->getLocation().x;
 float zDistance2 = joueurAI[1]->getLocation().z-ball->getLocation().z;
  float xDistance3 = joueurAI[2]->getLocationX()-ball->getLocation().x;
 float zDistance3 = joueurAI[2]->getLocation().z-ball->getLocation().z;
  float xDistance4 = joueurAI[3]->getLocationX()-ball->getLocation().x;
 float zDistance4 = joueurAI[3]->getLocation().z-ball->getLocation().z;
  float xDistance5 = joueurAI[4]->getLocationX()-ball->getLocation().x;
 float zDistance5 = joueurAI[4]->getLocation().z-ball->getLocation().z;
  float xDistance6 = joueurAI[5]->getLocationX()-ball->getLocation().x;
 float zDistance6 = joueurAI[5]->getLocation().z-ball->getLocation().z;
 float xDistance7 = joueurAI[6]->getLocationX()-ball->getLocation().x;
 float zDistance7 = joueurAI[6]->getLocation().z-ball->getLocation().z;
 float xDistance8 = joueurAI[7]->getLocationX()-ball->getLocation().x;
 float zDistance8 = joueurAI[7]->getLocation().z-ball->getLocation().z;
 float xDistance9 = joueurAI[8]->getLocationX()-ball->getLocation().x;
 float zDistance9 = joueurAI[8]->getLocation().z-ball->getLocation().z;
 float xDistance10 = joueurAI[9]->getLocationX()-ball->getLocation().x;
 float zDistance10 = joueurAI[9]->getLocation().z-ball->getLocation().z;
 
 */
float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));
	

for(int i=0;i<joueurAI.size();i++)
{

											if(joueurAI[i]->gethastheball()==true && joueurAI[0]->gethastheball()==false && hypotenuse<10)
											{
												joueurAI[0]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[1]->gethastheball()==false&& hypotenuse2<10)
											{
												joueurAI[1]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[2]->gethastheball()==false&& hypotenuse3<10)
											{
												joueurAI[2]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[3]->gethastheball()==false&& hypotenuse4<10)
											{
												joueurAI[3]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[4]->gethastheball()==false&& hypotenuse5<10)
											{
												joueurAI[4]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[5]->gethastheball()==false&& hypotenuse6<10)
											{
												joueurAI[5]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[6]->gethastheball()==false&& hypotenuse7<10)
											{
												joueurAI[6]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[7]->gethastheball()==false&& hypotenuse8<10)
											{
												joueurAI[7]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[8]->gethastheball()==false&& hypotenuse9<10)
											{
												joueurAI[8]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
													if(joueurAI[i]->gethastheball()==true && joueurAI[9]->gethastheball()==false && hypotenuse10<10)
											{
												joueurAI[9]->setLocationincremente(vector3d(-0.5,0,0.5));
											}
										}
										
										


}

void putthem::suivre()
{
		
	

 	vector3d Distance = vector3d(joueur[0]->getLocation()-ball->getLocation());
		  vector3d Distance2 = vector3d(joueur[1]->getLocation()-ball->getLocation());
		  vector3d Distance3 = vector3d(joueur[2]->getLocation()-ball->getLocation());
		  vector3d Distance4 = vector3d(joueur[3]->getLocation()-ball->getLocation());
		  vector3d Distance5 = vector3d(joueur[4]->getLocation()-ball->getLocation());
		  vector3d Distance6 = vector3d(joueur[5]->getLocation()-ball->getLocation());
		  vector3d Distance7 = vector3d(joueur[6]->getLocation()-ball->getLocation());
		  vector3d Distance8 = vector3d(joueur[7]->getLocation()-ball->getLocation());
		  vector3d Distance9 = vector3d(joueur[8]->getLocation()-ball->getLocation());
		  vector3d Distance10 = vector3d(joueur[9]->getLocation()-ball->getLocation());
/* float zDistance = joueurAI[0]->getLocation().z-ball->getLocation().z;
 float xDistance2 = joueurAI[1]->getLocationX()-ball->getLocation().x;
 float zDistance2 = joueurAI[1]->getLocation().z-ball->getLocation().z;
  float xDistance3 = joueurAI[2]->getLocationX()-ball->getLocation().x;
 float zDistance3 = joueurAI[2]->getLocation().z-ball->getLocation().z;
  float xDistance4 = joueurAI[3]->getLocationX()-ball->getLocation().x;
 float zDistance4 = joueurAI[3]->getLocation().z-ball->getLocation().z;
  float xDistance5 = joueurAI[4]->getLocationX()-ball->getLocation().x;
 float zDistance5 = joueurAI[4]->getLocation().z-ball->getLocation().z;
  float xDistance6 = joueurAI[5]->getLocationX()-ball->getLocation().x;
 float zDistance6 = joueurAI[5]->getLocation().z-ball->getLocation().z;
 float xDistance7 = joueurAI[6]->getLocationX()-ball->getLocation().x;
 float zDistance7 = joueurAI[6]->getLocation().z-ball->getLocation().z;
 float xDistance8 = joueurAI[7]->getLocationX()-ball->getLocation().x;
 float zDistance8 = joueurAI[7]->getLocation().z-ball->getLocation().z;
 float xDistance9 = joueurAI[8]->getLocationX()-ball->getLocation().x;
 float zDistance9 = joueurAI[8]->getLocation().z-ball->getLocation().z;
 float xDistance10 = joueurAI[9]->getLocationX()-ball->getLocation().x;
 float zDistance10 = joueurAI[9]->getLocation().z-ball->getLocation().z;
 
 */
float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));


			

if(hypotenuse<hypotenuse2 && hypotenuse<hypotenuse3 && hypotenuse<hypotenuse4 && hypotenuse<hypotenuse5 && hypotenuse<hypotenuse6 && hypotenuse<hypotenuse7 && hypotenuse<hypotenuse8 && hypotenuse<hypotenuse9 
&& hypotenuse<hypotenuse10 )
{
joueur[0]->setNext(true);
}
else
{
	joueur[0]->setNext(false);
}
if(joueur[0]->getNext())
{



											joueur[0]->avancer();
											joueur[0]->reculer();
											joueur[0]->droite();
											joueur[0]->gauche();
											joueur[0]->avantdroite();
											joueur[0]->avantgauche();
											joueur[0]->arrieredroite();
											joueur[0]->arrieregauche();
										
}


if(hypotenuse2<hypotenuse && hypotenuse2<hypotenuse3 && hypotenuse2<hypotenuse4 && hypotenuse2<hypotenuse5 && hypotenuse2<hypotenuse6 && hypotenuse2<hypotenuse7 && hypotenuse2<hypotenuse8 && hypotenuse2<hypotenuse9 
&& hypotenuse2<hypotenuse10)
{
			
joueur[1]->setNext(true);
}
else
{
	joueur[1]->setNext(false);
}
			if(joueur[1]->getNext() )
			{
										joueur[1]->avancer();
											joueur[1]->reculer();
											joueur[1]->droite();
											joueur[1]->gauche();
												joueur[1]->avantdroite();
											joueur[1]->avantgauche();
											joueur[1]->arrieredroite();
											joueur[1]->arrieregauche();
										
}
if(hypotenuse3<hypotenuse && hypotenuse3<hypotenuse2 && hypotenuse3<hypotenuse4 && hypotenuse3<hypotenuse5 && hypotenuse3<hypotenuse6 && hypotenuse3<hypotenuse7 && hypotenuse3<hypotenuse8 && hypotenuse3<hypotenuse9 
&& hypotenuse3<hypotenuse10)
{

joueur[2]->setNext(true);
}
else
{
	joueur[2]->setNext(false);
}
if(joueur[2]->getNext() )
{


											joueur[2]->avancer();
											joueur[2]->reculer();
											joueur[2]->droite();
											joueur[2]->gauche();
											joueur[2]->avantdroite();
											joueur[2]->avantgauche();
											joueur[2]->arrieredroite();
											joueur[2]->arrieregauche();
}

if(hypotenuse4<hypotenuse && hypotenuse4<hypotenuse2 && hypotenuse4<hypotenuse3 && hypotenuse4<hypotenuse5 && hypotenuse4<hypotenuse6 && hypotenuse4<hypotenuse7 && hypotenuse4<hypotenuse8 && hypotenuse4<hypotenuse9 
&& hypotenuse4<hypotenuse10 )
{
joueur[3]->setNext(true);
}
else
{
	joueur[3]->setNext(false);
}
if(joueur[3]->getNext() )
{


											joueur[3]->avancer();
											joueur[3]->reculer();
											joueur[3]->droite();
											joueur[3]->gauche();
											joueur[3]->avantdroite();
											joueur[3]->avantgauche();
											joueur[3]->arrieredroite();
											joueur[3]->arrieregauche();
}


if(hypotenuse5<hypotenuse && hypotenuse5<hypotenuse2 && hypotenuse5<hypotenuse3 && hypotenuse5<hypotenuse4 && hypotenuse5<hypotenuse6 && hypotenuse5<hypotenuse7 && hypotenuse5<hypotenuse8 && hypotenuse5<hypotenuse9
&& hypotenuse5<hypotenuse10  )
{
joueur[4]->setNext(true);
}
else
{
	joueur[4]->setNext(false);
}
if(joueur[4]->getNext() )
{

				
											joueur[4]->avancer();
											joueur[4]->reculer();
											joueur[4]->droite();
											joueur[4]->gauche();
												joueur[4]->avantdroite();
											joueur[4]->avantgauche();
											joueur[4]->arrieredroite();
											joueur[4]->arrieregauche();
}


if(hypotenuse6<hypotenuse && hypotenuse6<hypotenuse2 && hypotenuse6<hypotenuse3 && hypotenuse6<hypotenuse4 && hypotenuse6<hypotenuse5 && hypotenuse6<hypotenuse7 && hypotenuse6<hypotenuse8 && hypotenuse6<hypotenuse9 
&& hypotenuse6<hypotenuse10  )
{
joueur[5]->setNext(true);
}
else
{
	joueur[5]->setNext(false);
}
if(joueur[5]->getNext() )
{


											joueur[5]->avancer();
											joueur[5]->reculer();
											joueur[5]->droite();
											joueur[5]->gauche();
												joueur[5]->avantdroite();
											joueur[5]->avantgauche();
											joueur[5]->arrieredroite();
											joueur[5]->arrieregauche();
										
}


if(hypotenuse7<hypotenuse && hypotenuse7<hypotenuse2 && hypotenuse7<hypotenuse3 && hypotenuse7<hypotenuse4 && hypotenuse7<hypotenuse5 && hypotenuse7<hypotenuse6 && hypotenuse7<hypotenuse8 && hypotenuse7<hypotenuse9 
&& hypotenuse7<hypotenuse10  )
{
joueur[6]->setNext(true);
}
else
{
	joueur[6]->setNext(false);
}
if(joueur[6]->getNext() )
{

								joueur[6]->avancer();
											joueur[6]->reculer();
											joueur[6]->droite();
											joueur[6]->gauche();
										joueur[6]->avantdroite();
											joueur[6]->avantgauche();
											joueur[6]->arrieredroite();
											joueur[6]->arrieregauche();
}




if(hypotenuse8<hypotenuse && hypotenuse8<hypotenuse2 && hypotenuse8<hypotenuse3 && hypotenuse8<hypotenuse4 && hypotenuse8<hypotenuse5 && hypotenuse8<hypotenuse6 && hypotenuse8<hypotenuse7 && hypotenuse8<hypotenuse9 
&& hypotenuse8<hypotenuse10  )
{

joueur[7]->setNext(true);
}
else
{
	joueur[7]->setNext(false);
}
if(joueur[7]->getNext() )
{


											joueur[7]->avancer();
											joueur[7]->reculer();
											joueur[7]->droite();
											joueur[7]->gauche();
											joueur[7]->avantdroite();
											joueur[7]->avantgauche();
											joueur[7]->arrieredroite();
											joueur[7]->arrieregauche();
							
}


if(hypotenuse9<hypotenuse && hypotenuse9<hypotenuse2 && hypotenuse9<hypotenuse3 && hypotenuse9<hypotenuse4 && hypotenuse9<hypotenuse5 && hypotenuse9<hypotenuse6 && hypotenuse9<hypotenuse7 && hypotenuse9<hypotenuse8 
&& hypotenuse9<hypotenuse10  )
{
joueur[8]->setNext(true);
}
else
{
	joueur[8]->setNext(false);
}
if(joueur[8]->getNext() )
{


											joueur[8]->avancer();
											joueur[8]->reculer();
											joueur[8]->droite();
											joueur[8]->gauche();
											joueur[8]->avantdroite();
											joueur[8]->avantgauche();
											joueur[8]->arrieredroite();
											joueur[8]->arrieregauche();
										
}


if(hypotenuse10<hypotenuse && hypotenuse10<hypotenuse2 && hypotenuse10<hypotenuse3 && hypotenuse10<hypotenuse4 && hypotenuse10<hypotenuse5 && hypotenuse10<hypotenuse6 && hypotenuse10<hypotenuse7 && hypotenuse10<hypotenuse8 
&&  hypotenuse10<hypotenuse9)
{
joueur[9]->setNext(true);
}
else
{
	joueur[9]->setNext(false);
}
if(joueur[9]->getNext())
{




											joueur[9]->avancer();
											joueur[9]->reculer();
											joueur[9]->droite();
											joueur[9]->gauche();
											joueur[9]->avantdroite();
											joueur[9]->avantgauche();
											joueur[9]->arrieredroite();
											joueur[9]->arrieregauche();
										
}


											
	for(int j=0;j<joueur.size();j++)
			{



	
			
											if(joueur[j]->gethastheball()==true)
					
											{
											
			
											joueur[j]->avancer();
											joueur[j]->reculer();
											joueur[j]->droite();
											joueur[j]->gauche();
											joueur[j]->avantdroite();
											joueur[j]->avantgauche();
											joueur[j]->arrieredroite();
											joueur[j]->arrieregauche();
								}
					
								
									
								
							
					}
}

void putthem::suivreAI()
{
	
	
	vector3d Distance = vector3d(joueurAI[0]->getLocation()-ball->getLocation());
		  vector3d Distance2 = vector3d(joueurAI[1]->getLocation()-ball->getLocation());
		  vector3d Distance3 = vector3d(joueurAI[2]->getLocation()-ball->getLocation());
		  vector3d Distance4 = vector3d(joueurAI[3]->getLocation()-ball->getLocation());
		  vector3d Distance5 = vector3d(joueurAI[4]->getLocation()-ball->getLocation());
		  vector3d Distance6 = vector3d(joueurAI[5]->getLocation()-ball->getLocation());
		  vector3d Distance7 = vector3d(joueurAI[6]->getLocation()-ball->getLocation());
		  vector3d Distance8 = vector3d(joueurAI[7]->getLocation()-ball->getLocation());
		  vector3d Distance9 = vector3d(joueurAI[8]->getLocation()-ball->getLocation());
		  vector3d Distance10 = vector3d(joueurAI[9]->getLocation()-ball->getLocation());
/* float zDistance = joueurAI[0]->getLocation().z-ball->getLocation().z;
 float xDistance2 = joueurAI[1]->getLocationX()-ball->getLocation().x;
 float zDistance2 = joueurAI[1]->getLocation().z-ball->getLocation().z;
  float xDistance3 = joueurAI[2]->getLocationX()-ball->getLocation().x;
 float zDistance3 = joueurAI[2]->getLocation().z-ball->getLocation().z;
  float xDistance4 = joueurAI[3]->getLocationX()-ball->getLocation().x;
 float zDistance4 = joueurAI[3]->getLocation().z-ball->getLocation().z;
  float xDistance5 = joueurAI[4]->getLocationX()-ball->getLocation().x;
 float zDistance5 = joueurAI[4]->getLocation().z-ball->getLocation().z;
  float xDistance6 = joueurAI[5]->getLocationX()-ball->getLocation().x;
 float zDistance6 = joueurAI[5]->getLocation().z-ball->getLocation().z;
 float xDistance7 = joueurAI[6]->getLocationX()-ball->getLocation().x;
 float zDistance7 = joueurAI[6]->getLocation().z-ball->getLocation().z;
 float xDistance8 = joueurAI[7]->getLocationX()-ball->getLocation().x;
 float zDistance8 = joueurAI[7]->getLocation().z-ball->getLocation().z;
 float xDistance9 = joueurAI[8]->getLocationX()-ball->getLocation().x;
 float zDistance9 = joueurAI[8]->getLocation().z-ball->getLocation().z;
 float xDistance10 = joueurAI[9]->getLocationX()-ball->getLocation().x;
 float zDistance10 = joueurAI[9]->getLocation().z-ball->getLocation().z;
 
 */
float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));
			

if(hypotenuse<hypotenuse2 && hypotenuse<hypotenuse3 && hypotenuse<hypotenuse4 && hypotenuse<hypotenuse5 && hypotenuse<hypotenuse6 && hypotenuse<hypotenuse7 && hypotenuse<hypotenuse8 && hypotenuse<hypotenuse9 
&& hypotenuse<hypotenuse10 && hypotenuse>1)
{
joueurAI[0]->setNext(true);
}
else
{
joueurAI[0]->setNext(false);
}
if(joueurAI[0]->getNext()  )
{



											joueurAI[0]->movement(ball->getLocation());
										
}


if(hypotenuse2<hypotenuse && hypotenuse2<hypotenuse3 && hypotenuse2<hypotenuse4 && hypotenuse2<hypotenuse5 && hypotenuse2<hypotenuse6 && hypotenuse2<hypotenuse7 && hypotenuse2<hypotenuse8 && hypotenuse2<hypotenuse9 
&& hypotenuse2<hypotenuse10 &&hypotenuse2>1)
{
			
joueurAI[1]->setNext(true);
}
else
{
joueurAI[1]->setNext(false);
}
			if(joueurAI[1]->getNext() )
			{
										joueurAI[1]->movement(ball->getLocation());
										
}
if(hypotenuse3<hypotenuse && hypotenuse3<hypotenuse2 && hypotenuse3<hypotenuse4 && hypotenuse3<hypotenuse5 && hypotenuse3<hypotenuse6 && hypotenuse3<hypotenuse7 && hypotenuse3<hypotenuse8 && hypotenuse3<hypotenuse9 
&& hypotenuse3<hypotenuse10 &&hypotenuse3>1)
{
joueurAI[2]->setNext(true);
}
else
{
joueurAI[2]->setNext(false);
}
if(joueurAI[2]->getNext()   )
{


										joueurAI[2]->movement(ball->getLocation());
}

if(hypotenuse4<hypotenuse && hypotenuse4<hypotenuse2 && hypotenuse4<hypotenuse3 && hypotenuse4<hypotenuse5 && hypotenuse4<hypotenuse6 && hypotenuse4<hypotenuse7 && hypotenuse4<hypotenuse8 && hypotenuse4<hypotenuse9 
&& hypotenuse4<hypotenuse10 &&hypotenuse4>1)
{
joueurAI[3]->setNext(true);
}
else
{
joueurAI[3]->setNext(false);
}
if(joueurAI[3]->getNext()  )
{


											joueurAI[3]->movement(ball->getLocation());
}


if(hypotenuse5<hypotenuse && hypotenuse5<hypotenuse2 && hypotenuse5<hypotenuse3 && hypotenuse5<hypotenuse4 && hypotenuse5<hypotenuse6 && hypotenuse5<hypotenuse7 && hypotenuse5<hypotenuse8 && hypotenuse5<hypotenuse9
&& hypotenuse5<hypotenuse10  &&hypotenuse5>1)
{
joueurAI[4]->setNext(true);
}
else
{
joueurAI[4]->setNext(false);
}
if(joueurAI[4]->getNext()  )
{

				
											joueurAI[4]->movement(ball->getLocation());
}


if(hypotenuse6<hypotenuse && hypotenuse6<hypotenuse2 && hypotenuse6<hypotenuse3 && hypotenuse6<hypotenuse4 && hypotenuse6<hypotenuse5 && hypotenuse6<hypotenuse7 && hypotenuse6<hypotenuse8 && hypotenuse6<hypotenuse9 
&& hypotenuse6<hypotenuse10 &&hypotenuse6>1 )
{
joueurAI[5]->setNext(true);
}
else
{
joueurAI[5]->setNext(false);
}
if(joueurAI[5]->getNext() )
{


											joueurAI[5]->movement(ball->getLocation());
										
}


if(hypotenuse7<hypotenuse && hypotenuse7<hypotenuse2 && hypotenuse7<hypotenuse3 && hypotenuse7<hypotenuse4 && hypotenuse7<hypotenuse5 && hypotenuse7<hypotenuse6 && hypotenuse7<hypotenuse8 && hypotenuse7<hypotenuse9 
&& hypotenuse7<hypotenuse10 &&hypotenuse7>1 )
{
joueurAI[6]->setNext(true);
}
else
{
joueurAI[6]->setNext(false);
}
if(joueurAI[6]->getNext()  )
{

							joueurAI[6]->movement(ball->getLocation());
}




if(hypotenuse8<hypotenuse && hypotenuse8<hypotenuse2 && hypotenuse8<hypotenuse3 && hypotenuse8<hypotenuse4 && hypotenuse8<hypotenuse5 && hypotenuse8<hypotenuse6 && hypotenuse8<hypotenuse7 && hypotenuse8<hypotenuse9 
&& hypotenuse8<hypotenuse10 &&hypotenuse8>1 )
{

joueurAI[7]->setNext(true);
}
else
{
joueurAI[7]->setNext(false);
}
if(joueurAI[7]->getNext()  )
{


									joueurAI[7]->movement(ball->getLocation());
							
}


if(hypotenuse9<hypotenuse && hypotenuse9<hypotenuse2 && hypotenuse9<hypotenuse3 && hypotenuse9<hypotenuse4 && hypotenuse9<hypotenuse5 && hypotenuse9<hypotenuse6 && hypotenuse9<hypotenuse7 && hypotenuse9<hypotenuse8 
&& hypotenuse9<hypotenuse10  &&hypotenuse9>1)
{
joueurAI[8]->setNext(true);
}
else
{
joueurAI[8]->setNext(false);
}
if(joueurAI[8]->getNext()  )
{


											joueurAI[8]->movement(ball->getLocation());
										
}


if(hypotenuse10<hypotenuse && hypotenuse10<hypotenuse2 && hypotenuse10<hypotenuse3 && hypotenuse10<hypotenuse4 && hypotenuse10<hypotenuse5 && hypotenuse10<hypotenuse6 && hypotenuse10<hypotenuse7 && hypotenuse10<hypotenuse8 
&&  hypotenuse10<hypotenuse9&&hypotenuse10>1)
{
joueurAI[9]->setNext(true);
}
else
{
joueurAI[9]->setNext(false);
}
if(joueurAI[9]->getNext()   )
{



	joueurAI[9]->movement(ball->getLocation());
										
}


	
								
									
								
							

}
void putthem::camSetLocation(vector3d loc)
{
	camLoc=loc;
}
vector3d putthem::camGetLocation()
{
	return camLoc;
}
void putthem::lighting()
{
	GLfloat ambient[] = {0.7f,0.7f,0.7f,0.9f};
            GLfloat diffuse[] = {0.8f,0.8f,0.8f,0.8f};
            GLfloat light0_position [] = {0.0f, 5.0f, -20.0f, 10.0f};
            GLfloat specular_reflexion[] = {0.8f,0.8f,0.8f,1.0f};
            GLubyte shiny_obj = 128;

                        //positionnement de la lumière avec les différents paramètres
            glEnable(GL_LIGHTING);
            glLightfv(GL_LIGHT0,GL_AMBIENT,ambient);
            glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuse);
            glLightfv(GL_LIGHT0,GL_POSITION,light0_position);
            glEnable(GL_LIGHT0);

                         //spécification de la réflexion sur les matériaux
            glEnable(GL_COLOR_MATERIAL);
            glColorMaterial(GL_FRONT,GL_AMBIENT_AND_DIFFUSE);
            glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,ambient);
            glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,diffuse);
            glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,specular_reflexion);
            glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,shiny_obj);
}
void putthem::cameras_setup()
{
	  if(mode<=1 && mode>=0)
      {
      
      	 camSetLocation(vector3d(ball->getLocation().x+5*sin(ball->getangle().x*M_PI/180),ball->getLocation().y+12,ball->getLocation().z+5*cos(ball->getangle().z*M_PI/180)));
	  }
	  else if(mode>1 && mode<=2)
      {
      	
      	 camSetLocation(vector3d(ball->getLocation().x+sin(ball->getangle().x*M_PI/180),ball->getLocation().y+20,ball->getLocation().z+20*cos(ball->getangle().z*M_PI/180)));
	  }
else if(mode>2 && mode<=3)
	  {
	  	 camSetLocation(vector3d(ball->getLocation().x-10*cos(ball->getangle().x*M_PI/180),ball->getLocation().y+25,ball->getLocation().z+15*sin(ball->getangle().z*M_PI/180)));
	  
	  }
	
}


void putthem::show()
{
	if(menu==2)
	{
	playerCam_->update(levels[0]->getCollisionPlanes());
	for(int i=0;i<goal_.size();i++)
		goal_[i]->update(levels[0]->getCollisionPlanes());

    	ball->update(levels[0]->getCollisionPlanes());
     	 
										  					
for(int i=0;i<joueur.size();i++)
     	if( joueur[i]->update(levels[0]->getCollisionPlanes()))
     	 	{
			  	
		 }
	
	for(int i=0;i<joueurAI.size();i++)
     	if( joueurAI[i]->update(levels[0]->getCollisionPlanes()))
     	 	{
			  	
		 }
	

      for(int i=0;i<levels.size();i++)
      {
	  
      	levels[i]->update();
      	
      }
     update();

}


/*	 camX=ball->getLocation().x+20*sin(ball->getangle().x*M_PI/180);
	 camY=25;
	 camZ=ball->getLocation().z+20*cos(ball->getangle().z*M_PI/180);
	 */
	 
	int LightPos[4] = {-80,100,20,20};
int MatSpec [4] = {1,1,1,1};
glMaterialiv(GL_FRONT_AND_BACK,GL_SPECULAR,MatSpec);
glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,10);

	    

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
   
		//Control(0.2,0.2,mousein);
      if(menu==1)
      {

drawHud();
 

}
 if(menu==2)
 {
 gluLookAt(camGetLocation().x,camGetLocation().y,camGetLocation().z,ball->getLocation().x,ball->getLocation().y+5,ball->getLocation().z,0,1,0);


    lighting();
        //drawSkybox(50.0);

//glLightiv(GL_LIGHT0,GL_POSITION,LightPos);
 
				//soleil->show();
			
				ball->show();
			
				for(int i=0;i<goal_.size();i++)
				goal_[i]->show();
				
		
				
		   for(int i=0;i<joueur.size();i++)
          
		      joueur[i]->show();
		  
		      
		  for(int i=0;i<joueurAI.size();i++)
          
		      joueurAI[i]->show();

           for(int i=0;i<levels.size();i++)
		
      	           levels[i]->show();
			
			for(int i=0;i<support.size();i++)
			
				support[i]->show();

			 //drawHudJoueur();
			 drawHudJoueur();

			 
	
}
    
      
   //	player1->cam.loc.x=car1->loc.x+2;
        //UpdateCamera();
}





