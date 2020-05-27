#include "scrolling.h"
#include "hero.h"
#include "background.h"
#include"anime.h"

void scroll_function( int b ,SDL_Rect *camera )
{
	if(b==0){
		(*camera).x+=6;
		
	}

	if(b==1){
		(*camera).x-=6;
		
		
	}


if((*camera).x< 0)
{
	(*camera).x=0;
}  

if((*camera).x> 5500)
(*camera).x=5500;


}



