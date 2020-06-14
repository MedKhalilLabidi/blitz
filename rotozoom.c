#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_rotozoom.h>
#include <SDL/SDL_image.h>

#define TEMPS   30 //Le temps entre chaque augmentation de l'angle.
void rotozoom(int argc, char *argv[])
{
    SDL_Surface *ecran=NULL, *image=NULL , *rotation=NULL ;
    SDL_Rect rect;
    SDL_Event ecent;
    double angle = 0;
    double zoom = 1;
    
    int continuer=1;
    int tempsPrecedent=0, tempsActuel=0;
    SDL_Init(SDL_INIT_VIDEO);

    image=IMG_Load("image.jpg");

    rect.x=150;
    rect.y=150;
while(continuer)
{
    SDL_PollEvent(&event);
    switch(event.type)
    {
       case SDL_QUIT:
           continuer=0;
           break;
    }
   tempsActuel=SDL_GetTicks();
   if(tempsActuel-tempsPrecedent>TEMPS)
{
   angle +=2; //Augmenter l'angle pour tourner l'image sur elle-meme.
   zoom+=0.0025;
  
   tempsPrecedent=tempsActuel;
}
else
{
   SDL_Delay(TEMPS-(tempsActuel-tempPrecedent));
}

   SDL_FillRect(ecran,NULL,SDL_MapRGB(ecran->format,255,255,255));
   rotation=rotozoomSurFace(image,angle,zoom,1); //Transformer la surface image.
   SDL_BlitSurface(rotation,NULL,ecran,&rect); //Afficher la rotation de la surface.
   SDL_FreeSurface(rotation); //Effacer la surface rotation.

   SDL_Flip(ecran);
}

SDL_FreeSurface(ecran);
SDL_FreeSurface(image);
SDL_Quit();

}