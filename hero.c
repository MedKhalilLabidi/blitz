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
 
(*h).direction=0;


(*h).police=TTF_OpenFont("font/angelina.ttf",70);
sprintf(nscore,"Score:%d",(*h).score);
sprintf(nvie,"vie:%d",(*h).vie);

(*h).textscore=TTF_RenderText_Blended((*h).police,nscore,blanc);
(*h).textvie=TTF_RenderText_Blended((*h).police,"vie",blanc);
(*h).imagevie=IMG_Load("images/life1.png");


(*h).images=IMG_Load(nomimg);


}

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


void afficher_hero(hero h,int x){
  int i=0;
SDL_Color blanc={0,0,0};
  TTF_Font *police;
  char nscore[20];
	SDL_Rect position,position2,poslife;
	position.x=1300-x;
	position.y=50;
	position2.x=1600-x;
position2.y=50;
poslife.x=1650-x;
poslife.y=50;

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












void deplacerclaviersouris(SDL_Event event,int *dec)  
{

    
     switch(event.type)
     {
        case SDL_KEYDOWN://clavier
          if((event.key.keysym.sym == SDLK_LEFT )|| (event.key.keysym.sym ==SDLK_q))
          {H.direction=1;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),1)!=1 && H.pos.x>0-(*dec)){
              animate_hero(&H);
              if(Map.camera.x<=0 )
           H.pos.x -= 6;
               else{
            scroll_function(1,&Map.camera);
A.posa.x+=6;

           
           (*dec)-=6;
       }
}
         }
          if((event.key.keysym.sym == SDLK_RIGHT)|| (event.key.keysym.sym ==SDLK_d))
          {if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),0)!=1  ){
            H.direction=0;
           animate_hero(&H);
              if(H.pos.x<960 )
           H.pos.x += 6;
               else{
            scroll_function(0,&Map.camera);
A.posa.x-=6;

           
           (*dec)+=6;
       }
}
        

         }
         if((event.key.keysym.sym == SDLK_UP)|| (event.key.keysym.sym ==SDLK_z))
          {
          
            H.pos.y -= 20;

         animate_hero(&H);

         }
          if((event.key.keysym.sym == SDLK_DOWN)|| (event.key.keysym.sym ==SDLK_s))
          {H.direction=3;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec),3)!=1){
            
           H.pos.y += 5;
            //affichage d image
           animate_hero(&H);

           }
         }
        break;
        case SDL_MOUSEBUTTONDOWN://souris
          if(event.button.button == SDL_BUTTON_LEFT )
          {
             H.pos.x -= 5;
            H.direction=1;
           
animate_hero(&H);
          }
          if(event.button.button == SDL_BUTTON_RIGHT)
          {
            H.pos.x += 5;
           H.direction=0;

           
animate_hero(&H);
          }
          if(event.button.button== SDL_BUTTON_WHEELUP)
          {
             H.pos.x+=10;
             H.pos.y -= 20;
             
          animate_hero(&H);
          }
          if(event.button.button == SDL_BUTTON_WHEELDOWN)
          {
             H.pos.y += 5;
                
          animate_hero(&H);
          }



        }}
void free_hero(){


 SDL_FreeSurface(H.images);
	SDL_FreeSurface(H.textscore);
	SDL_FreeSurface(H.textvie);
	SDL_FreeSurface(H.imagevie);
	
	SDL_FreeSurface(A.imagesa);
  SDL_FreeSurface(H2.images);
  SDL_FreeSurface(H2.textscore);
  SDL_FreeSurface(H2.textvie);
  SDL_FreeSurface(H2.imagevie);
  

	
}


void updatescore(hero *h){
    char nscore[20],nvie[20];
SDL_Color blanc={0,0,0};
sprintf(nscore,"Score:%d",(*h).score);
SDL_FreeSurface(H.textscore);
(*h).textscore=TTF_RenderText_Blended((*h).police,nscore,blanc);


 /*SDL_FreeSurface((*h).textvie);
(*h).textvie=TTF_RenderText_Blended((*h).police,nvie,blanc);*/
}
void deplacer2(int T[],int *dec,int *dec2)  
{

    
     
        
          if(T[SDLK_LEFT]==1)
          {H.direction=1;
            if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,1)!=1 && H.pos.x>970-(*dec)){
       animate_hero(&H);
       if(Map.camera2.x<=0) H.pos.x -= 5;
       else{scroll_function(1,&Map.camera2);
        A.posa2.x+=5;
           
           (*dec)-=6;

}}
         }
          if(T[SDLK_RIGHT]==1)
          {if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,0)!=1  ){
             
             H.direction=0; 
            animate_hero(&H);
        if(H.pos.x<1440) H.pos.x += 5;
          else  {scroll_function(0,&Map.camera2);
            (*dec)+=6;A.posa2.x-=5;}
}
        
}
if(T[SDLK_UP]==1)
          {
          
            H.pos.y -= 20;

         animate_hero(&H);

         }

if(T[SDLK_DOWN]==1)
          {
          if (collisionParfaite(Map.masque,H.images,H.pos,(*dec)-970,3)!=1){
            H.pos.y += 10;

         animate_hero(&H);

         }

         }

          if(T[SDLK_q]==1)
          {H2.direction=1;
            if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),1)!=1 && H2.pos.x>0-(*dec)){
           

       animate_hero(&H2);
      if (Map.camera.x<=0)H2.pos.x -= 5;
      else{

 
            scroll_function(1,&Map.camera);
A.posa.x+=5;
           
           (*dec2)-=6;

      }
}
         }
          if(T[SDLK_d]==1)
          {if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),0)!=1  ){
            
             H2.direction=0; 
             


            animate_hero(&H2);
if(H2.pos.x<480)H2.pos.x += 5;
else{

             (*dec2)+=6;
             scroll_function(0,&Map.camera);
         A.posa.x-=5;



}



}
        
}
if(T[SDLK_z]==1)
          {
          
            H2.pos.y -= 20;

         animate_hero(&H2);

         }

if(T[SDLK_s]==1)
          {
            H2.direction=3; 
             
          if (collisionParfaite(Map.masque,H2.images,H2.pos,(*dec2),3)!=1){
            H2.pos.y += 10;

         animate_hero(&H2);

         }

         }
        }