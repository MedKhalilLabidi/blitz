#include "scrolling.h"



int main (int argc , char *argv[])
{

SDL_Init(SDL_INIT_VIDEO);

SDL_Surface *ecran=NULL , *background=NULL ;

SDL_Event event ;

int continue1=1 ;
int x,y;
x = 0;
y = 0;
Uint32 start ;


int b[2] = {0,0}; 

SDL_Rect camera , position;
camera.x = 0;
camera.y = 0;
camera.w = SCREEN_WIDTH  ;
camera.h = SCREEN_HEIGHT;


position.x=0;
position.y=0;


ecran=SDL_SetVideoMode(SCREEN_WIDTH ,SCREEN_HEIGHT , 32 , SDL_HWSURFACE);
background=IMG_Load("background.jpg");

continue1=1;
while(continue1)
{

start=SDL_GetTicks();



while(SDL_PollEvent(&event))
{

switch(event.type) 
{

case SDL_QUIT:
continue1=0 ;
break;


case SDL_KEYDOWN:
switch(event.key.keysym.sym)
{


case SDLK_RIGHT:
b[0] = 1;
break;


case SDLK_LEFT:
b[1] = 1;
break;


case SDLK_ESCAPE:
continue1=0;
break;
}
break;


case SDL_KEYUP:
switch(event.key.keysym.sym)
{


case SDLK_RIGHT:
b[0] = 0;
break;


case SDLK_LEFT:
b[1] = 0;
break;


}
break;


}

}

scroll_function(&camera , b , ecran , background);

SDL_BlitSurface(background , &camera , ecran, NULL);

SDL_Flip(ecran);


}
 




if (1000/FPS > SDL_GetTicks()-start)
SDL_Delay(1000/FPS - (SDL_GetTicks()-start));


SDL_Quit();
return 0 ;
}
