typedef struct 
{SDL_Rect pos,possprite,posimagevie;
SDL_Surface *images,*textscore,*textvie,*imagevie;
int score;int vie; int direction;
TTF_Font *police;
}hero;
hero H,H2;




void init_hero(char nomimg[],hero *,int x);
void animate_hero(hero *h);
void afficher_hero(hero h,int x);
void free_hero();
void deplacerclaviersouris(SDL_Event event,int *dec) ;

void updatescore(hero *h);
void deplacer2(int T[],int *dec,int *dec2);