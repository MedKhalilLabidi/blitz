#include "scrolling.h"
#include "hero.h"
#include "background.h"
#include"anime.h"

void scroll_function( int b ,SDL_Rect *camera,int *dec,int n,SDL_Rect vitesse )
{
	if(b==0 && (*camera).x<3100){
		(*camera).x+=vitesse.x;
		for(int i=1;i<3;i++){
			if(n==1)
		A[i].posa.x-=vitesse.x;
         if(n==2)
		A[i].posa2.x-=vitesse.x;}
		(*dec)+=vitesse.x;
	}

	if(b==1 & (*camera).x> 0){
		(*camera).x-=vitesse.x;
		for(int i=1;i<3;i++){
			if(n==1)
 		A[i].posa.x+=vitesse.x;
 	if(n==2)
        A[i].posa2.x+=vitesse.x;
          } 
           (*dec)-=vitesse.x;
	}


if((*camera).x< 0)
{
	(*camera).x=0;
}  

if((*camera).x>3100)
(*camera).x=3100;


}



