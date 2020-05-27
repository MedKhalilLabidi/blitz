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
#include"anime.h"



void init_anime(){

SDL_Color blanc={0,0,0};
	
A.posa.x=1000;
A.posa.y=600;
A.posa2.x=1000+920;
A.posa2.y=600;
A.posspritea.x=0;
A.posspritea.y=0;
A.posspritea.h=300;
A.posspritea.w=188;


 
A.directiona=0;


A.imagesa=IMG_Load("images/backsprite.png");


}




void animate_anime(){
if(A.directiona==0 ){
A.posspritea.y=0;
A.posspritea.w=188;}

 if(A.directiona==1){
	A.posspritea.y=300;
	A.posspritea.w=188;
}
if(A.posspritea.x==1316) A.posspritea.x=0;
else A.posspritea.x+=188;} 







void afficher_anime(int dec,int n){
	if(n==1){
		if(A.posa.x>0 ){
	
SDL_BlitSurface(A.imagesa,&A.posspritea,screen,&A.posa);}
}
if(n==2 ) {

if(A.posa.x>0 && A.posa.x<800){
	
SDL_BlitSurface(A.imagesa,&A.posspritea,screen,&A.posa);
}

	if(A.posa2.x>920 && A.posa2.x<1920)
SDL_BlitSurface(A.imagesa,&A.posspritea,screen,&A.posa2);
}

}




void deplacer(int timereal)  
{ int  time0=0;
     
if( ((timereal - time0)/1000)%2== 0) 
{A.directiona=0;
   	A.posa.x+=1;
   	animate_anime();
}
else  {A.posa.x-=1;
A.directiona=1;
animate_anime();
}
}

