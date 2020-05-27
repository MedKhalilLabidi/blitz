typedef struct{
SDL_Rect pos;
SDL_Surface *imageup;
SDL_Surface *imagedown;
SDL_Surface *imageover;
int state;
}button;


button buttons[40];


void loadbutton(char nom[],int x ,int y,int *n);
void showbutton(int n);
int mouseclick(int n,SDL_Event event);
void freebuttons();

