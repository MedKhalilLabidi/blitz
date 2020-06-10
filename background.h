/**
* @struct Background
* @brief struct for backround
*/
typedef struct{
SDL_Surface *image,*image2;/*!< Surface. */
SDL_Surface *anim[9];/*!< Surface. */
SDL_Surface *text,*title;/*!< Surface. */
SDL_Rect pos,postxt,postitle;/*!< Rectangle*/
TTF_Font *police,*police2;/*!< font*/
Mix_Music *music;/*!< music*/
Mix_Chunk *son;/*!< son*/
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