#ifndef FONCTIONS_H_
#define FONCTIONS_H_
typedef struct {
SDL_Surface tab1[3];
SDL_Rect pos_vie;
int i;

}vie ;

typedef struct {
int score ;
SDL_Rect pos_score ;
}score ;


typedef struct {
score score ;
vie vie ;

}GAME; 


void init_vie(GAME *game);
void update_vie(GAME *game);
void display_vie(GAME *game);
void int_score(GAME *game);
void update_score (GAME *game);
void free_score(GAME *game);



#endif
