#include<stdio.h>
#include <stdlib.h>
#include "fct.h" 
#include "SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"hero.h"
void deplacerclaviersouris(SDL_Event event)  
{

     switch(event.type)
     {
        case SDL_KEYDOWN://clavier
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {H.direction=0;
           H.pos.x -= 5;
       animate_hero();

         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {
             H.pos.x += 5;
             H.direction=1;
            animate_hero();

         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
            H.pos.x+=10;
            H.pos.y -= 20;
         animate_hero();

         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {
           H.pos.y += 5;

            //affichage d image
           animate_hero();

           
         }
        break;
        case SDL_MOUSEBUTTONUP://souris
          if(event.button.button == SDL_BUTTON_LEFT )
          {H.direction=0;
             H.pos.x -= 5;

            
animate_hero();
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {H.direction=1;
            H.pos.x += 5;
           
animate_hero();
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
             H.pos.x+=10;
             H.pos.y -= 20;
             
          animate_hero();
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
             H.pos.y += 5;
                
          animate_hero();
          }
        }}