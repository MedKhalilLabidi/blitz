#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"button.h"
#include"background.h"
#include"menu.h"
#include"player.h"
#include"hero.h"
#include"game.h"
#include"game2.h"


void playerchoise(int *c){
	int n=10;
	SDL_Surface *image1,*image2;
	int buthov=-1;
	SDL_Event event;
	int done=0;
show_background();

showbutton(10);
showbutton(11);
while((*c)==0 && done !=1){
 while(SDL_PollEvent(&event))
{switch(event.type)
{ case SDL_QUIT:
 done=1;
 break;

  switch(event.key.keysym.sym){
     case SDLK_ESCAPE:
       done=1;
       break;
   }

case SDL_MOUSEBUTTONDOWN:
if( mouseclick(10,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[10].state=3;
update(10);

  (*c)=1;
  done=1;

   
}


if( mouseclick(11,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[11].state=3;
update(11);


  (*c)=2;
  done=1;
}







break;



case SDL_MOUSEMOTION:


if( mouseclick(10,event)==1){
buttons[10].state=2;
update(10);
buthov=1;
}
else if( mouseclick(11,event)==1){
buttons[11].state=2;
update(11);
buthov=1;}

else if(buthov!=-1)
  {if (mouseclick(10,event)==0 || mouseclick(11,event)==0 )


{
buttons[11].state=1;
buttons[10].state=1;
showbutton(10);
showbutton(11);
buthov=-1;
}}

break;

case SDL_MOUSEBUTTONUP:



buttons[11].state=1;
buttons[10].state=1;

showbutton(10);
showbutton(11);
break;

     



}
}

}

}











void player(){
int 	c=0;
int done=0;SDL_Event event;int tma=0,tmp=0;
int buthov=-1;int butpre=-1;int delay=0;
int i=0;
SDL_Rect position;
position.x=0;
position.y=0;
show_background();
showmenu3();
while(done!=1)
{tma=SDL_GetTicks();
  if(tma - tmp >30){

SDL_BlitSurface(b.anim[i],NULL,screen,&position);
SDL_Flip(screen);
i++;
delay++;

if(i==4){
  
  i=0;

tmp=tma;

}}
while(SDL_PollEvent(&event))
{switch(event.type)
{case SDL_QUIT:
done=1;
break;
case SDL_KEYDOWN:
  switch(event.key.keysym.sym){
     case SDLK_ESCAPE:
       done=1;
break;
    case SDLK_DOWN:
      
butpre=buthov;
 buthov++;
if(buthov>=10){buthov=7;}
            buttons[butpre].state=1;
    buttons[buthov].state=2;
   showbutton(buthov);
 showbutton(butpre);
     break;


 case SDLK_UP:
 if(buthov==-1){buthov=9;}
   butpre=buthov;
     buthov--;
     if(buthov<7){buthov=9;}
            buttons[butpre].state=1;
    buttons[buthov].state=2;
   showbutton(buthov);
 showbutton(butpre);

    break;
case SDLK_RETURN:
    if(buthov==9){
     done=1;}
    }
case SDL_MOUSEBUTTONDOWN:
if( mouseclick(7,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[7].state=3;
update(7);
playerchoise(&c);
if(c!=0)
   game(c);
   
}


if( mouseclick(8,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[8].state=3;
update(8);
game2();
}



if( mouseclick(9,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[9].state=3;
update(9);
}



break;



case SDL_MOUSEMOTION:


if( mouseclick(7,event)==1){
buttons[7].state=2;
update(7);
buthov=1;
}
else if( mouseclick(8,event)==1){
buttons[8].state=2;
update(8);
buthov=1;}
else if( mouseclick(9,event)==1){
buttons[9].state=2;
update(9);
buthov=1;
}
else if(buthov!=-1)
  {if (mouseclick(7,event)==0 || mouseclick(8,event)==0|| mouseclick(9,event)==0 )


{
buttons[7].state=1;
buttons[8].state=1;
buttons[9].state=1;
showmenu3();
buthov=-1;
}}

break;

case SDL_MOUSEBUTTONUP:
if( mouseclick(7,event)==1 ){

free_hero();
freemap();}
if( mouseclick(8,event)==1 ){

free_hero();
 freemap();}

if( mouseclick(9,event)==1){
done=1;
}


buttons[7].state=1;
buttons[8].state=1;
buttons[9].state=1;
showmenu3();
break;

      


}
}

}
show_background();
showmenu();
}