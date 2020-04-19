#include<stdio.h>
#include <stdlib.h>
#include "fct.h" 
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
void init_vie(GAME *game)
{
    game->vie.pos_vie[0].x = 400;
    game->vie.pos_vie[0].y = 30;
    
    game->vie.tab1[0] = IMG_Load("vie/1.png");
    game->vie.tab1[1] = IMG_Load("vie/2.png");
    game->vie.tab1[2] = IMG_Load("vie/3.png");
    
    game->vie.i=2;
}
void update_vie(GAME *game)
{
    if (collisionmap(game))
        if(game->vie.i>0)
        {game->vie.i-=1;}
} 

void display_vie(GAME *game)
{
    
    game->vie.pos_vie[0].x = 700;
    game->vie.pos_vie[0].y = 30;
    SDL_BlitSurface(game->vie.tab1[game->vie.i],NULL,game->ecran,&game->vie.pos_vie[0]);
    
}

void int_score(GAME *game)
{
    game->score.score=0 ;
    game->score.pos_score.x=200;
    game->score.pos_score.y=30;
}
void update_score (GAME *game)
{
    game->score.score+=1 ;
}

void free_score(GAME *game)
{
    game->score.score =0 ;
}
