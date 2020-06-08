#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "vie.h"
#include"score.h"
typedef struct
{


SDL_Surface *perssonage;
SDL_Rect posperso;
SDL_Rect rects[4][10];
int frame;
int direction;
SDL_Rect vitesse;
int  onground;
vie Vie;
score Score;

}perssonage;


void setrects(perssonage *p);
void initialiser_perssonage (perssonage *p);
void afficher_perssonage (perssonage p,SDL_Surface *screen,SDL_Rect camera);
void animer_perso (perssonage *p); 
void mouvementright (perssonage *p,int *startTicks);
void mouvementleft (perssonage *p,int *startTicks);
void mouvementdown (perssonage *p);
void mouvementjump (perssonage *p);



#endif 




