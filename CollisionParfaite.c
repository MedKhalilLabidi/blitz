#include "CollisionParfaite.h"



int collisionBox(SDL_Rect a, SDL_Rect b){
	int leftSideA = a.x;
	int rightSideA = a.x + 120;
	int topA = a.y;
	int bottomA = a.y + 290;

	int leftSideB = b.x;
	int rightSideB = b.x + 120;
	int topB = b.y;
	int bottomB = b.y + 290;

	if(bottomA <= topB){
		return 0;
	}

	if(topA >= bottomB){
		return 0;
	}

	if(rightSideA <= leftSideB){
		return 0;
	}

	if(leftSideA >= rightSideB){
		return 0;
	}

	return 1;
}



SDL_Color GetPixel(SDL_Surface *surface,int x,int y){

    SDL_Color color;
    Uint32 col = 0;

    //determine position
    char* pPosition = (char*) surface->pixels;

    //offset by y
    pPosition += surface->pitch * y;

    
    //offset by x
    pPosition += (surface->format->BytesPerPixel * x);


    //copy pixel data
    memcpy(&col, pPosition, surface->format->BytesPerPixel);


    //convert color
    SDL_GetRGB(col,surface->format,&color.r,&color.g,&color.b);

    return color;
}

int collisionParfaite(SDL_Surface *calque, SDL_Surface *perso, SDL_Rect posperso, int decalage, int direction){
	SDL_Color col;
	int c = 0;

	if(direction == 2){//Up
		col=GetPixel(calque,posperso.x+perso->w +decalage,posperso.y+(perso->h/2));

	}else if(direction == 3){//Down
		col=GetPixel(calque,posperso.x+60+decalage ,posperso.y+300+220);

	}else if(direction == 0){//Rigth
		col=GetPixel(calque,posperso.x+(120)+decalage,posperso.y+290+220);

	}else if(direction == 1){//Left
		col=GetPixel(calque,posperso.x+decalage,posperso.y+290+220 );

	}

	if ((col.r == 0) && (col.b == 0) && (col.g == 0))
		c = 1;
	
	
	return c;
}

