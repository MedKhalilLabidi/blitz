#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "initialiser_enemie.h"


void initialiser_enemie(enemie (*e))
{e->position.x =***;
 e->position.y =***;
(*e).sens=-1;
(*e).num_img_actuelle=0;
(*e).image[0]= IMG_Load("enemie pos1");
(*e).image[1]= IMG_Load("enemie pos2");
(*e).image[2]= IMG_Load("enemie pos3");
(*e).image[3]= IMG_Load("enemie pos4");
(*e).image[4]= IMG_Load("enemie pos5");
(*e).image[5]= IMG_Load("enemie pos6");
(*e).image[6]= IMG_Load("enemie pos7");
(*e).image[7]= IMG_Load("enemie pos8");

}


