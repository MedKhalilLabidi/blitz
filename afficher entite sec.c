#include "afficher_entite_sec.h"

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL, *background = NULL, *entite = NULL;
    SDL_Rect positionFond, positionentite;

    positionFond.x = 0;
    positionFond.y = 0;
    positionentite.x = 500;
    positionentite.y = 260;

    SDL_Init(SDL_INIT_VIDEO);

    ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("Chargement d'images en SDL", NULL);

    imageDeFond = SDL_LoadBMP("background.bmp");
    SDL_BlitSurface(background, NULL, ecran, &positionfond);

    zozor = SDL_LoadBMP("entite.bmp");
    SDL_BlitSurface(zozor, NULL, ecran, &positionZozor);

    SDL_Flip(ecran);
    pause();

    SDL_FreeSurface(background);
    SDL_FreeSurface(entite);
    SDL_Quit();

    return;
}
