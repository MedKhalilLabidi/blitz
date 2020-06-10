
/**
* @file button.c
*/

#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"

#include"background.h"
#include"button.h"
#include"string.h"
/**
* @brief To initialize the buttons .
* @param  x ,y to position n to number of buttons
* @param name the url of the image
* @param  n to number of buttons
* @return Nothing
*/


void loadbutton(char name[],int x ,int y,int *n){
button but;

char fname[40]="";char hname[30]="";char sname[30]="";
strcpy(fname,name);
strcat(fname,".png");
strcpy(hname,name);
strcat(hname,"2.png");
strcpy(sname,name); 
strcat(sname,"3.png");

but.imageup=IMG_Load(fname);
but.imageover=IMG_Load(hname);
but.imagedown=IMG_Load(sname);

but.pos.x=x;
but.pos.y=y;
but.state=1;
buttons[(*n)]=but;

(*n)++;

}
/**
* @brief To show buttons  .
* &param n to number of buttons
* @return Nothing
*/
void showbutton(int n){
if(buttons[n].state==1){
SDL_BlitSurface(buttons[n].imageup,NULL,screen,&buttons[n].pos);
}
if(buttons[n].state==2){
SDL_BlitSurface(buttons[n].imageover,NULL,screen,&buttons[n].pos);
}
if(buttons[n].state==3){
SDL_BlitSurface(buttons[n].imagedown,NULL,screen,&buttons[n].pos);
}
SDL_Flip(screen);
}
/**
* @brief check mouse click  .
* &param n to number of buttons
* &param event to SDL_event
* @return Nothing
*/
int mouseclick(int n,SDL_Event event){
int i=0;
if(buttons[n].pos.x< event.button.x && event.button.x < buttons[n].pos.x + buttons[n].imageup->w && buttons[n].pos.y < event.button.y && event.button.y < buttons[n].pos.y + buttons[n].imageup->h) i=1;
return i;}
/**
* @brief To Free buttons .
* @return Nothing
*/

void freebuttons(){
int i;
for(i=0;i<14;i++){

SDL_FreeSurface(buttons[i].imageup);
SDL_FreeSurface(buttons[i].imageover);
SDL_FreeSurface(buttons[i].imagedown);}
}



