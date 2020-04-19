#include<stdio.h>
#include <stdlib.h>
#include "fct.h" 
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
void deplacerclaviersouris(SDL_Event event,perso *p,SDL_Surface *screen)  
{
while(SDL_PollEvent(&event))
    {
     switch(event.type)
     {
        case SDL_KEYDOWN://clavier
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
           p->pos.x -= 5;
            affiche_perso(p,screen);
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
            p->pos.x += 5;
            affiche_perso(p,screen);
         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
           p->pos.x+=10;
           p->pos.y -= 20;
             affiche_perso(p,screen);
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
          p->pos.y += 5;
            //affichage d image
           affiche_perso(p,screen);
         }
        break;
        case SDL_MOUSEBUTTONUP://souris
          if(event.button.button == SDL_BUTTON_LEFT )
          {
            p->pos.x -= 5;
            affiche_perso(p,screen);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           p->pos.x += 5;
            affiche_perso(p,screen);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
            p->pos.x+=10;
            p->pos.y -= 20;
             affiche_perso(p,screen);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            p->pos.y += 5;
