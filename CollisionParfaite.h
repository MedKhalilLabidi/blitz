#ifndef CollisionParfaite_h_
#define CollisionParfaite_h_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct{
    int x, y;
    int r;
}Circle;

double distanceSquared(int x1, int y1, int x2, int y2);

int collisionBxC(Circle a, SDL_Rect b);

int collisionCxC(Circle a, Circle b);

int collisionBox(SDL_Rect a, SDL_Rect b);

SDL_Color GetPixel(SDL_Surface *surface, int x, int y);

int collisionParfaite(SDL_Surface *calque, SDL_Surface *perso, SDL_Rect posperso, int decalage, int direction);
#endif


