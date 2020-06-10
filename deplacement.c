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
void mouvementright (hero *p,int *startTicks)
{if(p->direction==1) p->vitesse.x=5;
p->direction=0;
int tempsActuel;
tempsActuel=SDL_GetTicks();
if(tempsActuel- *(startTicks)>=300)
{*(startTicks)=tempsActuel;
p->vitesse.x+=4;
}
if(p->vitesse.x>=20)
{
p->vitesse.x=20;
}

 

}
void mouvementleft (hero *p,int *startTicks)
{if(p->direction==0) p->vitesse.x=5;
p->direction=1;
int tempsActuel;
tempsActuel=SDL_GetTicks();
if(tempsActuel- *(startTicks)>=300)
{
*(startTicks)=tempsActuel;
p->vitesse.x+=4;
}
if(p->vitesse.x>=20)
{
p->vitesse.x=20;

}
}
void mouvementdown (hero *p)
{
p->pos.y--;
p->direction=3;
}




void mouvementjump (hero *p)
{


p->pos.y-=p->vitesse.y;
p->direction=4; 
}
void deplacerclaviersouris(SDL_Event event,int *dec,int cont,int *startTicks)  
{

    
     switch(event.type)
     {    
        case SDL_KEYDOWN:
        if(cont==0){//clavier
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {
          
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),1)!=1 && H.pos.x>0-(*dec)){
              animate_hero(&H);
              mouvementleft(&H,startTicks);
              if(Map.camera.x<=0 )
           H.pos.x -= H.vitesse.x;
               else{
            scroll_function(1,&Map.camera,&(*dec),1,H.vitesse);}
       }
             
       }

         
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          { 


            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),0)!=1  && H.pos.x<1750){
               
           animate_hero(&H);
              mouvementright(&H,startTicks);
  if(H.pos.x<960 || (*dec)>=3102)
           H.pos.x += H.vitesse.x;
               else{
            scroll_function(0,&Map.camera,&(*dec),1,H.vitesse);}




              
}}
        

         
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),3)==1 ){
           
           mouvementjump(&H);
            
          
            
}
         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {H.direction=3;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),3)!=1){
            
           mouvementdown (&H);

           }
         }
        break;
        
        
        case SDL_MOUSEBUTTONDOWN://souris
        if(cont==1){
          if(event.button.button == SDL_BUTTON_LEFT )
          {
             H.direction=1;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),1)!=1 && H.pos.x>0-(*dec)){
              animate_hero(&H);
              mouvementleft(&H,startTicks);
               if(Map.camera.x<=0 )
           H.pos.x -= H.vitesse.x;
               else{
            scroll_function(1,&Map.camera,&(*dec),1,H.vitesse);}
       }
}
                     }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
           if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),0)!=1  ){
            animate_hero(&H);
              mouvementright(&H,startTicks);
                if(H.pos.x<960 || (*dec)>=3102)
           H.pos.x += H.vitesse.x;
               else{
            scroll_function(0,&Map.camera,&(*dec),1,H.vitesse);}
       
}
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
             
            mouvementjump(&H);
            
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
            H.direction=3;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),3)!=1){
            
           mouvementdown (&H);
           }
         }
          }

  


break;}
        }