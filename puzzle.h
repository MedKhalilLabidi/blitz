/*
puzzle.h
_ _ _ _ _ _ _

Role: Ils'agi
*/

#ifndef PUZZLE_H_
#define PUZZLE_H_
typedef struct
{
	SDL_Rect positionImage1, positionImage2, positionImage3, positionImage4, positionImage5, positionImage6, positionImage7, positionImage8, positionVide;
	int Temps;
}Position;
Position puzzle(Position *Correcte);
int resolution_enigme(int collision,int* score);

#endif
