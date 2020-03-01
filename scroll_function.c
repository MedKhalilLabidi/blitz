#include "scrolling.h"


SDL_Rect scroll_function(SDL_Rect *camera , int *b , SDL_Surface *ecran , SDL_Surface *background)
{



switch(b[0])
{


case 0 :
SDL_BlitSurface(background, camera, ecran, NULL);
SDL_Flip(ecran);
break ;

case 1 :

camera->x += speed;


SDL_BlitSurface(background, camera, ecran, NULL);
SDL_Flip(ecran);
break ;




}





switch(b[1])
{

case 0 :
SDL_BlitSurface(background, camera, ecran, NULL);
SDL_Flip(ecran);
break ;


case 1 :

camera->x -= speed;


SDL_BlitSurface(background, camera, ecran, NULL);

SDL_Flip(ecran);

break ;

}



return *camera ;


}



