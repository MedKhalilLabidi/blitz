/**
* @struct Background
* @brief struct for backround
*/

typedef struct{
SDL_Rect pos;/*!< Rectangle*/
SDL_Surface *imageup;/*!< Surface. */
SDL_Surface *imagedown;/*!< Surface. */
SDL_Surface *imageover;/*!< Surface. */
int state;/*!< integers. */
}button;


button buttons[40];


void loadbutton(char nom[],int x ,int y,int *n);
void showbutton(int n);
int mouseclick(int n,SDL_Event event);
void freebuttons();

