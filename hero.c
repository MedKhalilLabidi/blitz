#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"background.h"
#include"menu.h"
#include"player.h"
#include"hero.h"


void init_hero(){
	SDL_Color blanc={0,0,0};
	char nscore[20],nvie[20];
	TTF_Font *police;
H.pos.x=500;
H.pos.y=400;
H.score=0;
H.vie=3;
H.direction=0;
police=TTF_OpenFont("font/angelina.ttf",70);
sprintf(nscore,"Score:%d",H.score);
sprintf(nvie,"vie:%d",H.vie);
H.textscore=TTF_RenderText_Blended(police,nscore,blanc);
H.textvie=TTF_RenderText_Blended(police,nscore,blanc);


H.images=IMG_Load("images/robot.png");

}
void afficher_hero(){
	SDL_Rect position;
	position.x=1000;
	position.y=100;
 SDL_BlitSurface(H.textscore,NULL,screen,&position);
SDL_BlitSurface(H.images,NULL,screen,&H.pos);

}

