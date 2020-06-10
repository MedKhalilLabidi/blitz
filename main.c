/**
* @file main.c
* @brief Testing Program.
* @author Khalil
* @version 2.0
* @date June 01, 2020
*
* Testing prototype 2
*
*/


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
#include"hero.h"
int main(){

menu();

TTF_Quit();
SDL_Quit();
return 0;
}