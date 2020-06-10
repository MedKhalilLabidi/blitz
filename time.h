typedef struct {
	int compteurM,compteurS;
	int tempP;
	SDL_Rect pos;
	SDL_Surface *text;
}time;
time T;
void init_time(time *t);
void timer(time *t);
void affichertimer();
