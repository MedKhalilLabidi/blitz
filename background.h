typedef struct{
SDL_Surface *image,*image2;
SDL_Surface *anim[9];
SDL_Surface *text,*title;
SDL_Rect pos,postxt,postitle;
TTF_Font *police,*police2;
Mix_Music *music;
Mix_Chunk *son;
}background;
background b,bgame;
background b1;
typedef struct
{SDL_Surface *image,*masque;
  SDL_Rect pos,pos2,camera,camera2;
	
}map;
map Map;
SDL_Surface *screen;

void init_SDL();
void init_screen();
void load_background();
void show_background();
void show_anim(int *n);
void load_map(int m);
void show_map(int m);
void freebackground();
void freemap();