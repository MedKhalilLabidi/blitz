#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED


typedef struct enemie
{ SDL_Surface *image[8];
int num_img_actuelle;
SDL_Rect position;
int sens;
 }enemie;

void initialiser_enemie(enemie (*e));


#endif
