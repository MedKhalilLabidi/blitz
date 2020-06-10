#include<stdio.h>
#include<stdlib.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include"SDL/SDL_ttf.h"
#include"background.h" 
#include"menu.h"

void init_SDL(){
if(SDL_Init(SDL_INIT_VIDEO)!=0){
printf("unable to initialize SDL:%s\n",SDL_GetError());
}


if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    
}

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{printf("%s",Mix_GetError());
}
}


void init_screen(){
screen=SDL_SetVideoMode(1920,1080,32,SDL_SWSURFACE | SDL_DOUBLEBUF   );

}

void load_background(){

SDL_Color blanc={255,255,255};
SDL_Color gold={255,223,0};

b.police=TTF_OpenFont("font/angelina.ttf",70);
b.police2=TTF_OpenFont("font/title.ttf",300);
b.text=TTF_RenderText_Blended(b.police,"Simplicity.Prod ",blanc);
b.title=TTF_RenderText_Blended(b.police2,"BLitz",gold);

b.postxt.x=60;
b.postxt.y= 1000;
b.postitle.y=200;
b.postitle.x=900;

b.music=Mix_LoadMUS("son/music.mp3");
b.image=IMG_Load("images/background.jpg");
b.son=Mix_LoadWAV("son/son.wav");
b1.image=IMG_Load("images/setting.png");
b1.pos.x=503;
b1.pos.y=165;

b1.image2=IMG_Load("images/bar.png");

b.anim[0]=IMG_Load("images/1.png");
b.anim[1]=IMG_Load("images/2.png");
b.anim[2]=IMG_Load("images/3.png");
b.anim[3]=IMG_Load("images/4.png");
b.anim[4]=IMG_Load("images/5.png");
b.anim[5]=IMG_Load("images/6.jpg");

}
void show_background(){
SDL_Rect position;
int pidx=0;
position.x=0;
position.y=0;
SDL_BlitSurface(b.image,NULL,screen,&position);
SDL_Flip(screen);
SDL_BlitSurface(b.text,NULL,screen,&b.postxt);
SDL_BlitSurface(b.title,NULL,screen,&b.postitle);

SDL_Flip(screen);
}
void show_anim(int *n){
int i;SDL_Rect position;
position.x=0;
position.y=0;

for(i=0;i<10;i++){

SDL_BlitSurface(b.anim[i],NULL,screen,&position);
showmenu((*n));
SDL_Delay(150);
SDL_Flip(screen);
}}
void load_map(int m){

Map.image=IMG_Load("images/background2.jpg");
Map.masque=SDL_LoadBMP("images/backgroundmasque.bmp");
if(m==1){
Map.pos.x=0;
Map.pos.y=0;
Map.pos.h=1080;
Map.pos.w=1920/2;

Map.camera.w=1920;
Map.camera.x=0;
Map.camera.y=220;
Map.camera.h=1080;}
else if(m==2){Map.pos.x=0;
Map.pos.y=0;
Map.pos.h=1080;
Map.pos.w=1920/2;

Map.camera.w=1920/2;
Map.camera.x=0;
Map.camera.y=220;
Map.camera.h=1080;}

Map.pos2.x=1920/2;
Map.pos2.y=0;
Map.pos2.h=1080;
Map.pos2.w=1920/2;
Map.camera2.w=1920/2;
Map.camera2.x=0;
Map.camera2.y=220;
Map.camera2.h=1080;


 

}

void show_map(int m){
	SDL_Rect line;
	line.x=960;
	line.y=0;
	line.h=1080;
	line.w=10;
	
SDL_BlitSurface(Map.image,&Map.camera,screen,&Map.pos);
if(m==2){
SDL_BlitSurface(Map.image,&Map.camera2,screen,&Map.pos2);
SDL_FillRect(screen,&line,SDL_MapRGB(screen->format,0,0,0));
}
}






void freebackground(){
	
Mix_FreeMusic(b.music);
SDL_FreeSurface(b.image);
SDL_FreeSurface(screen);
SDL_FreeSurface(b1.image);
SDL_FreeSurface(b1.image2);
TTF_CloseFont(b.police);
TTF_CloseFont(b.police2);
SDL_FreeSurface(b.text);
SDL_FreeSurface(b.title);
Mix_FreeChunk(b.son);
}
void freemap(){
	SDL_FreeSurface(Map.image);
SDL_FreeSurface(Map.masque);
}
