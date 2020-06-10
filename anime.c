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



void init_anime(int nbr){
int dec=0;
SDL_Color blanc={0,0,0};
for(int i=1;i<=nbr;i++)
{	
A[i].posa.x=1000+dec;
A[i].posa.y=600;
A[i].posa2.x=1000+920+dec;
A[i].posa2.y=600;
A[i].posspritea.x=0;
A[i].posspritea.y=0;
A[i].posspritea.h=300;
A[i].posspritea.w=188;


 
A[i].directiona=0;
 dec+=2100;
}

A[1].imagesa=IMG_Load("images/backsprite.png");


}




void animate_anime(int nbr){
	for(int i=1;i<=nbr;i++)
{
if(A[i].directiona==0 ){
A[i].posspritea.y=0;
A[i].posspritea.w=188;}

 if(A[i].directiona==1){
	A[i].posspritea.y=300;
	A[i].posspritea.w=188;
}
if(A[i].posspritea.x==1316) A[i].posspritea.x=0;
else A[i].posspritea.x+=188;} 


}




void afficher_anime(int dec,int n,int nbr){
	
		for(int i=1;i<=nbr;i++)
{    if(n==1){
		if(A[i].posa.x>0 ){
	
SDL_BlitSurface(A[1].imagesa,&A[i].posspritea,screen,&A[i].posa);}}

if(n==2 ) {

if(A[i].posa.x>0 && A[i].posa.x<800){
	
SDL_BlitSurface(A[1].imagesa,&A[i].posspritea,screen,&A[i].posa);
}

	if(A[i].posa2.x>920 && A[i].posa2.x<1920)
SDL_BlitSurface(A[1].imagesa,&A[i].posspritea,screen,&A[i].posa2);
}
}
}




void deplacer(int timereal,int nbr)  
{ int  time0=0;
     for(int i=1;i<=nbr;i++){
if( ((timereal - time0)/1000)%2== 0) 
{A[i].directiona=0;
   	A[i].posa.x+=1;
   	animate_anime(nbr);
}
else  {A[i].posa.x-=1;
A[i].directiona=1;
animate_anime(nbr);
}
}
}


