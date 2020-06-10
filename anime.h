typedef struct 
{SDL_Rect posa,posspritea,posa2;
SDL_Surface *imagesa;
int directiona;
}anime;
anime A[20];


void init_anime(int nbr);
void animate_anime(int nbr);
void afficher_anime(int dec,int n,int nbr);
void deplacer(int timereal,int nbr ) ;

