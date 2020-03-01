typedef struct 
{SDL_Rect pos;
SDL_Surface *images,*textscore,*textvie;
int score,vie,direction;
}hero;
hero H;




void init_hero();
void afficher_hero();