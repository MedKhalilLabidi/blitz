/**
* @file game.c
* @brief Testing game coop.
* @author Khalil
* @version 2.0
* @date June 01, 2020
*
* coop game
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

#include"hero.h"
#include"CollisionParfaite.h"
#include"anime.h"
#include"game2.h"
void game2(){
int done=0;
int startTicks=0;
int keyheld[323]={0};
SDL_Surface *b2;
SDL_Rect pos,camera;
SDL_Event event;
int dec=0;int dec2=0;
int timereal=0;
int oldtime=0;
int nbre=1;
load_map(2);
 show_map(2);
init_hero("images/sprites4.png",&H,970);
init_hero("images/sprites2.png",&H2,0);
init_anime(nbre);

afficher_hero(H,0);
afficher_hero(H2,1000);


SDL_Flip(screen);
SDL_EnableKeyRepeat(10, 10);
while(done!=1){
show_map(2);
afficher_hero(H,0);
afficher_hero(H2,1000);
timereal=SDL_GetTicks();
	
deplacer(timereal,nbre);

afficher_anime(dec,2,nbre);



SDL_Flip(screen);

if(collisionParfaite(Map.masque,H.images,H.pos,dec-970,3)!=1)

 H.pos.y+=5;
if(collisionParfaite(Map.masque,H.images,H2.pos,dec2,3)!=1)

 H2.pos.y+=5;

if (collisionBox(H2.pos,A[1].posa)==1)
	{
H2.score-=100;
H2.vie-=1;

updatescore(2);
if(H2.direction==0)
H2.pos.x-=100;
Map.camera.x-=100;
if(H2.direction==1)
	H2.pos.x+=100;
Map.camera.x+=100;
}


if (collisionBox(H.pos,A[1].posa2)==1)
	{
H.score-=100;
H.vie-=1;

updatescore(1);
if(H.direction==0)
H.pos.x-=100;
Map.camera2.x-=100;
if(H.direction==1)
H.pos.x+=100;
Map.camera2.x+=100;
}




	while(SDL_PollEvent(&event)){
	switch(event.type){
		case SDL_QUIT:
		done=1;
		break;
		case SDL_KEYDOWN:
		keyheld[event.key.keysym.sym]=1;
if(event.key.keysym.sym==SDLK_ESCAPE)
done=1;
break;
case SDL_KEYUP:
keyheld[event.key.keysym.sym]=0;

}




}
deplacer2(keyheld,&dec,&dec2,&startTicks);

}

 free_hero();
 freemap();


}