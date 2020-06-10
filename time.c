/**
* @file background.c
*/
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
#include"CollisionParfaite.h"
#include"scrolling.h"
#include"anime.h"
#include"time.h"
void init_time(time *t){
char time[20];
SDL_Color blanc={0,0,0};
(*t).compteurS=0;
	(*t).compteurM=0;
	(*t).tempP=0;




	sprintf(time,"Time%d:%d",(*t).compteurM,(*t).compteurS);
(*t).text=TTF_RenderText_Blended(H.police,time,blanc);
			
}
void timer(time *t){
	int timer;
char time[20];
SDL_Color blanc={0,0,0};
SDL_Rect pos;



  timer=SDL_GetTicks();

	if(timer-(*t).tempP>=1000){
		(*t).compteurS+=1;
     (*t).tempP=timer;
	}
	if((*t).compteurS==60)
		{(*t).compteurM+=1;
			(*t).compteurS=0;}

			sprintf(time,"Time %d:%d",(*t).compteurM,(*t).compteurS);
			T.text=TTF_RenderText_Blended(H.police,time,blanc);
			SDL_BlitSurface(T.text,NULL,screen,&pos);
}
void affichertimer(){

SDL_Rect pos;
pos.x=0;
pos.y=50;

SDL_BlitSurface(T.text,NULL,screen,&pos);

}