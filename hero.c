/**
* @file hero.c
* @brief all hero fonctions
* @author Khalil
* @version 2.0
* @date June 01, 2020
*
* Testing personnage
*
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
#include"deplacement.h"
/**
* @brief To initialize  hero h.
* @param h 
* @param nomomg the url of the image
* @param int x position
* @return Nothing
*/
void init_hero(char nomimg[],hero *h,int x){
	SDL_Color blanc={0,0,0};
	char nscore[20],nvie[20];
	
(*h).pos.x=x;
(*h).pos.y=600;
(*h).possprite.x=0;
(*h).possprite.y=0;
(*h).possprite.h=304;
(*h).possprite.w=330;
(*h).score=0;
(*h).vie=3;
 (*h).vitesse.x=5;
 (*h).vitesse.y=400;
(*h).direction=0;
(*h).onground=1;


(*h).police=TTF_OpenFont("font/title.ttf",40);
sprintf(nscore,"Score:%d",(*h).score);
sprintf(nvie,"vie:%d",(*h).vie);

(*h).textscore=TTF_RenderText_Blended(H.police,nscore,blanc);
(*h).textvie=TTF_RenderText_Blended(H.police,"life:",blanc);
(*h).imagevie=IMG_Load("images/life1.png");


(*h).images=IMG_Load(nomimg);


}
 /**
* @brief animate hero h.
* @param h hero
* 
* @return Nothing
*/

void animate_hero(hero *h){

if((*h).direction==0){
(*h).possprite.y=0;
(*h).possprite.w=330;}

 if((*h).direction==1){
	(*h).possprite.y=304;
	(*h).possprite.w=300;
}
if((*h).possprite.x==6780-339) (*h).possprite.x=0;
else (*h).possprite.x+=339;} 
/**
* @brief To show  hero h.
* @param h 
* @param int x position
* @return Nothing
*/

void afficher_hero(hero h,int x){
  int i=0;
SDL_Color blanc={0,0,0};
  TTF_Font *police;
  char nscore[20];
	SDL_Rect position,position2,poslife;
	position.x=1300-x;
	position.y=50;
	position2.x=1550-x;
position2.y=50;
poslife.x=1650-x;
poslife.y=30;

//printf("%d \n",H.vie);
 SDL_BlitSurface(h.textscore,NULL,screen,&position);
 SDL_BlitSurface(h.textvie,NULL,screen,&position2);
if(h.vie>0) SDL_BlitSurface(H.imagevie,NULL,screen,&poslife);
if(h.vie>1){
  poslife.x+=70;
  SDL_BlitSurface(H.imagevie,NULL,screen,&poslife);
 }
if(h.vie>2){poslife.x+=70;
  SDL_BlitSurface(H.imagevie,NULL,screen,&poslife);
 }

SDL_BlitSurface(h.images,&h.possprite,screen,&h.pos);
//SDL_BlitSurface(H.imagevie[1],NULL,screen,&poslife);


}







  /**
* @brief To free  hero h.
* @param h 
* @return Nothing
*/
void free_hero(){


 SDL_FreeSurface(H.images);
	SDL_FreeSurface(H.textscore);
	SDL_FreeSurface(H.textvie);
	SDL_FreeSurface(H.imagevie);
	

	SDL_FreeSurface(A[1].imagesa);
  SDL_FreeSurface(H2.images);
  SDL_FreeSurface(H2.textscore);
  SDL_FreeSurface(H2.textvie);
  SDL_FreeSurface(H2.imagevie);
  TTF_CloseFont(H.police);
    TTF_CloseFont(H2.police);
   SDL_FreeSurface(T.text);
  

	
}

  /**
* @brief To update  score
* @param h 
* @return Nothing
*/

void updatescore(int n){
    char nscore[30];char nscore2[30];
SDL_Color blanc={0,0,0};
if(n==1){
sprintf(nscore,"Score:%d",H.score);
SDL_FreeSurface(H.textscore);
H.textscore=TTF_RenderText_Blended(H.police,nscore,blanc);
}
else{


sprintf(nscore2,"Score:%d",H2.score);
SDL_FreeSurface(H2.textscore);
H2.textscore=TTF_RenderText_Blended(H.police,nscore2,blanc);



}

 /*SDL_FreeSurface((*h).textvie);
(*h).textvie=TTF_RenderText_Blended((*h).police,nvie,blanc);*/
}
/**
* @brief To move h1 et h2
* @param h  to hero
* @param  dec to decalage
* @return Nothing
*/
void deplacer2(int T[],int *dec,int *dec2,int *startTicks)  
{

    
     
        
          if(T[SDLK_LEFT]==1)
          {
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,1)!=1 && H.pos.x>970-(*dec)){
       
        animate_hero(&H);
              mouvementleft(&H,startTicks);
               if(Map.camera2.x<=0) H.pos.x -= H.vitesse.x;
       else{scroll_function(1,&Map.camera2,&(*dec),2,H.vitesse);
       

}}}
         
          if(T[SDLK_RIGHT]==1)
          {if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,0)!=1 && H.pos.x<1750 ){
             
            
            animate_hero(&H);
      
              mouvementright(&H,startTicks);
              if(H.pos.x<1440 || (*dec)>=3102) H.pos.x +=H.vitesse.x;
          else  {scroll_function(0,&Map.camera2,&(*dec),2,H.vitesse);
            }
}
        
}
if(T[SDLK_UP]==1)
          {
          if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,3)==1 ){

          mouvementjump(&H);

         }}

if(T[SDLK_DOWN]==1)
          {
        
             
          if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,3)!=1){
            H.pos.y += 10;

         animate_hero(&H);

         }

         }

         

         

 if(T[SDLK_q]==1)
          {
            if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),1)!=1 && H2.pos.x>0-(*dec2) ){
           

       animate_hero(&H2);
         mouvementleft(&H2,startTicks);
         if (Map.camera.x<=0)H2.pos.x -= H2.vitesse.x;
      else{

 
            scroll_function(1,&Map.camera,&(*dec2),1,H2.vitesse);
}
         }}
 if(T[SDLK_d]==1)
          {if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),0)!=1  && H2.pos.x<920){
            
     
             
animate_hero(&H2);

mouvementright(&H2,startTicks);
if(H2.pos.x<480  ||(*dec)>=3102)H2.pos.x += H2.vitesse.x;
else{

             
             scroll_function(0,&Map.camera,&(*dec2),1,H2.vitesse);
        

}
      }  
}
if(T[SDLK_z]==1)
          {if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),3)==1 ){
          
            mouvementjump(&H2);
         }}

if(T[SDLK_s]==1)
          {
            H2.direction=3; 
             
          if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),3)!=1){
            H2.pos.y += 10;

         animate_hero(&H2);

         }

         }

 
        }

