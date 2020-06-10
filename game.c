/**
* @file game.c
* @brief Testing game solo.
* @author Khalil
* @version 2.0
* @date June 01, 2020
*
* solo game
*
*/


#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"button.h"
#include"background.h"
#include"menu.h"
#include"player.h"
#include"game.h"
#include"hero.h"
#include"CollisionParfaite.h"
#include"anime.h"
#include"time.h"
#include"deplacement.h"


void game(int c ,int controller){
    int start=0;
int done=0;
SDL_Surface *b2;
SDL_Rect pos,camera;
SDL_Event event;
int dec=0;
int timereal=0;
int oldtime=0;
int nbre=2;
load_map(1);
 show_map(1);
 if(c==1)
init_hero("images/sprites4.png",&H,0);
if(c==2)
init_hero("images/sprites2.png",&H,0);

afficher_hero(H,0);
init_anime(nbre);
 init_time(&T);


SDL_EnableKeyRepeat(10, 10);
while(done!=1){
	timereal=SDL_GetTicks();


	 show_map(1);
afficher_hero(H,0);


 timer(&T);
 affichertimer();

deplacer(timereal,nbre);

afficher_anime(dec,1,nbre);
if(collisionParfaite(Map.masque,H.images,H.pos,dec,3)!=1)

 H.pos.y+=5;



SDL_Flip(screen);
for(int i=1;i<3;i++){
if (collisionBox(H.pos,A[i].posa)==1)
	{
H.score-=100;
H.vie-=1;

updatescore(1);
if(H.direction==0)
H.pos.x-=100;

if(H.direction==1)
H.pos.x+=100;

}}
while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)done=1;
      if( event.type==  SDL_KEYDOWN){
        	if(event.key.keysym.sym == SDLK_ESCAPE )
      
        {
        	done=1;
        }  }
deplacerclaviersouris(event,&dec,controller,&start);


}

    }
    free_hero();
 freemap();


}

