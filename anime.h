typedef struct 
{SDL_Rect posa,posspritea,posa2;
SDL_Surface *imagesa;
int directiona;
}anime;
anime A;


void init_anime();
void animate_anime();
void afficher_anime(int dec,int n);
void deplacer(int timereal) ;

