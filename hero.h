/**
* @struct hero
* @brief struct for hero
*/
typedef struct 
{SDL_Rect pos,possprite,posimagevie;/*!< Rectangle*/
SDL_Surface *images,*textscore,*textvie,*imagevie;/*!< Surface. */
int score, vie, direction, onground;/*!< int */
TTF_Font *police;;/*!< font*/
SDL_Rect vitesse;/*!< Rectangle*/
}hero;
hero H,H2;




void init_hero(char nomimg[],hero *,int x);
void animate_hero(hero *h);
void afficher_hero(hero h,int x);
void free_hero();
void updatescore(int n);
void deplacer2(int T[],int *dec,int *dec2,int *startTicks);