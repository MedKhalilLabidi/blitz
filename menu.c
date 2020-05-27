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
#include"game.h"

void init_menu(int *n){

init_SDL();

init_screen();
load_background();
loadbutton("images/play",130,200,n);
loadbutton("images/options",130,440,n);
loadbutton("images/exit",130,710,n);
loadbutton("images/drag",1180,300,n);
loadbutton("images/fullscreen",650,490,n);
loadbutton("images/windowed",990,490,n);
loadbutton("images/back",690,731,n);
loadbutton("images/1player",130,200,n);
loadbutton("images/2player",130,440,n);
loadbutton("images/back",130,710,n);
loadbutton("images/1hero",600,500,n);
loadbutton("images/2hero",900,500,n);
}
void showmenu(){
int i;
for(i=0;i<3;i++){
showbutton(i);}
}	

void showmenu2(){
showbutton(6);
showbutton(5);
showbutton(4);

}
void showmenu3(){
showbutton(7);
showbutton(8);
showbutton(9);
}
void update(int n){
showbutton(n);
}



void soundsettting(){float t;int s;
s=buttons[3].pos.x;

t=((s-840)/480.0)*128;

s=t;



Mix_VolumeMusic(t);

}

	
void settings(int n){

SDL_Rect pos;
int done=0;SDL_Event event;
int drag=0;int hover=1;

pos.x=730;
pos.y=280;

show_background();
SDL_BlitSurface(b1.image,NULL,screen,&b1.pos);
SDL_BlitSurface(b1.image2,NULL,screen,&pos);
showbutton(3);
showmenu2();
while(done!=1){
while(SDL_PollEvent(&event))
{switch(event.type)
{case SDL_QUIT:
done=1;
break;
case SDL_KEYDOWN:
if(event.key.keysym.sym==SDLK_ESCAPE)
done=1;
break;
case SDL_MOUSEMOTION:
if(drag==1){
if((event.motion.x)>=855 && (event.motion.x)<=1230){
buttons[3].pos.x+=event.motion.xrel;

SDL_BlitSurface(b1.image2,NULL,screen,&pos);

 soundsettting();
update(3);
}}
else if( mouseclick(6,event)==1){
buttons[6].state=2;
update(6);
}
else if( mouseclick(5,event)==1){
buttons[5].state=2;
update(5);hover=1;
}
else if( mouseclick(4,event)==1){
buttons[4].state=2;
update(4);
hover=1;}
else {
buttons[6].state=1;
buttons[5].state=1;
buttons[4].state=1;
buttons[3].state=1;
showmenu2();
}

break;
case SDL_MOUSEBUTTONDOWN:
if( mouseclick(6,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[6].state=3;
update(6);
}
if( mouseclick(5,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[5].state=3;
update(5);

}
if( mouseclick(4,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[4].state=3;
update(4);


}
if( mouseclick(3,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[3].state=1;
update(3);
drag=1;
}
break;

case SDL_MOUSEBUTTONUP:
if( mouseclick(6,event)==1){
update(6);
done=1;}
if( mouseclick(5,event)==1){
screen=SDL_SetVideoMode(1920,1080,32,SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE   );
show_background();
SDL_BlitSurface(b1.image,NULL,screen,&b1.pos);
SDL_BlitSurface(b1.image2,NULL,screen,&pos);
showbutton(3);
showmenu2();
}
if( mouseclick(4,event)==1){
screen=SDL_SetVideoMode(1920,1080,32,SDL_SWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE | SDL_FULLSCREEN  );
show_background();
SDL_BlitSurface(b1.image,NULL,screen,&b1.pos);
SDL_BlitSurface(b1.image2,NULL,screen,&pos);
showbutton(3);
showmenu2();
}


buttons[3].state=1;
buttons[4].state=1;
buttons[5].state=1;
buttons[6].state=1;
showmenu2();

drag=0;
break;

}
}}

show_background();
showmenu();
}





void menu(){
	int n=0;int tma=0;int tmp=0,tma2=0,tmp2=0;
int done=0;int i=3;
int buthov=-1;int butpre;
SDL_Event event;
SDL_Rect position;
position.x=0;
position.y=0;
SDL_Rect pos,possprite;

init_menu(&n);


Mix_PlayMusic(b.music,-1);
show_background();
showmenu();
while(done!=1)
{tma=SDL_GetTicks();
  if(tma - tmp >30){
SDL_BlitSurface(b.anim[i],NULL,screen,&position);
SDL_Flip(screen);
i++;
if(i==4){i=0;}
tmp=tma;}

while(SDL_PollEvent(&event)){

switch(event.type)
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
if(buthov>=3){buthov=0;}
            buttons[butpre].state=1;
    buttons[buthov].state=2;
   showbutton(buthov);
 showbutton(butpre);
     break;


 case SDLK_UP:
 if(buthov==-1){buthov=2;}
   butpre=buthov;
     buthov--;
     if(buthov<0){buthov=2;}
            buttons[butpre].state=1;
    buttons[buthov].state=2;
   showbutton(buthov);
 showbutton(butpre);

    break;
case SDLK_RETURN:
    if(buthov==1){
     settings(n);}
if(buthov==2)
{done=1;}
if(buthov==0){player();}
break;
    }
case SDL_MOUSEBUTTONDOWN:
if( mouseclick(0,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[0].state=3;
update(0);
}


if( mouseclick(1,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[1].state=3;
update(1);
}



if( mouseclick(2,event)==1){
Mix_PlayChannel(1,b.son,0);
buttons[2].state=3;
update(2);
done=1;
}



break;



case SDL_MOUSEMOTION:


if( mouseclick(0,event)==1){
buttons[0].state=2;
update(0);
buthov=0;
}
else if( mouseclick(1,event)==1){
buttons[1].state=2;
update(1);
buthov=1;}
else if( mouseclick(2,event)==1){
buttons[2].state=2;
update(2);
buthov=2;
}
else if(buthov!=-1)
  {if (mouseclick(1,event)==0 || mouseclick(2,event)==0|| mouseclick(1,event)==0 )


{
buttons[0].state=1;
buttons[1].state=1;
buttons[2].state=1;
showmenu();
buthov=-1;
}}

break;

case SDL_MOUSEBUTTONUP:
if( mouseclick(0,event)==1){
player();
show_background();}

if( mouseclick(1,event)==1){
settings(n);}
if( mouseclick(2,event)==1){
done=1;
}


buttons[0].state=1;
buttons[1].state=1;
buttons[2].state=1;
showmenu();
break;

      


}
}

}

freebackground();
freebuttons();
SDL_FreeSurface(screen);
TTF_Quit();
SDL_Quit();


}
