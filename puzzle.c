/*
puzzle.c
_ _ _ _ _ _ _

Role: Il s'agit ici d'ecrire la fonction qui permettra de créer le puzzle.
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"
#include "puzzle.h"

Position puzzle(Position *Correcte)
{
	int carte[5][5];
    SDL_Surface *mur = NULL, *texte = NULL;
    SDL_Surface *ecran = NULL, *image1 = NULL, *image2 = NULL, *image3 = NULL, *image4 = NULL, *image5 = NULL, *image6 = NULL, *image7 = NULL, *image8 = NULL, *vide = NULL, *background = NULL,*back = NULL;
    SDL_Surface *wallup1 = NULL, *walldown1 = NULL, *wallright1 = NULL, *wallleft1 = NULL, *wallupright = NULL, *wallupleft = NULL, *walldownright = NULL, *walldownleft = NULL; 
    SDL_Surface *wallup2 = NULL, *walldown2 = NULL, *wallright2 = NULL, *wallleft2 = NULL;
    SDL_Surface *wallup3 = NULL, *walldown3 = NULL, *wallright3 = NULL, *wallleft3 = NULL;
    SDL_Rect new, positionBackGround, positionBack,position;
    SDL_Rect positionUpRight, positionUpLeft, positionDownRight, positionDownLeft;
    SDL_Rect positionUp1, positionUp2, positionUp3, positionDown1, positionDown2, positionDown3, positionRight1, positionRight2, positionRight3, positionLeft1, positionLeft2, positionLeft3; 
    SDL_Event event;
	TTF_Font *police;
	SDL_Color Noire = {255,255,255};
    int continuer = 1, tempsActuel = 0, tempsPrecedent = 0, compteur = 0;
    Position Post;

	tempsActuel = SDL_GetTicks();
    SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
    ecran = SDL_SetVideoMode(1080, 720, 32, SDL_HWSURFACE);
    SDL_WM_SetCaption("PUZZLE", NULL);

    
    image1 =IMG_Load("1.png");
    image2 =IMG_Load("2.png");
    image3 =IMG_Load("3.png");
    image4 =IMG_Load("4.png");
    image5 =IMG_Load("5.png");
    image6 =IMG_Load("6.png");
    image7 =IMG_Load("7.png");
    image8 =IMG_Load("8.png");
     vide  =IMG_Load("vide.png");

    wallup1 =IMG_Load("up.png");
    wallup2 =IMG_Load("up.png");
    wallup3 =IMG_Load("up.png");

    walldown1 =IMG_Load("down.png");
    walldown2 =IMG_Load("down.png");
    walldown3 =IMG_Load("down.png");

    wallright1 =IMG_Load("right.png");
    wallright2 =IMG_Load("right.png");
    wallright3 =IMG_Load("right.png");

    wallleft1 =IMG_Load("left.png");
    wallleft2 =IMG_Load("left.png");
    wallleft3 =IMG_Load("left.png");

    wallupright =IMG_Load("upright.png");
    wallupleft =IMG_Load("upleft.png");
    walldownright =IMG_Load("downright.png");
    walldownleft =IMG_Load("downleft.png");
    background =IMG_Load("background.png");
    back= IMG_Load("back.png");

    SDL_SetColorKey(image1, SDL_SRCCOLORKEY, SDL_MapRGB(image1->format, 0, 0, 255));


    positionBackGround.x = 0;
    positionBackGround.y = 0;

    positionBack.x = ecran->w / 2 - image1->w / 2 - 150;
    positionBack.y = ecran->h / 2 - image1->h / 2 - 150;


    Post.positionImage1.x = ecran->w / 2 - image1->w / 2;
    Post.positionImage1.y = ecran->h / 2 - image1->h / 2;
    Post.positionImage2.x = ecran->w / 2 - image2->w / 2 - 100;
    Post.positionImage2.y = ecran->h / 2 - image2->h / 2 - 100;
    Post.positionImage3.x = ecran->w / 2 - image3->w / 2;
    Post.positionImage3.y = ecran->h / 2 - image3->h / 2 + 100;
    Post.positionImage4.x = ecran->w / 2 - image4->w / 2 + 100;
    Post.positionImage4.y = ecran->h / 2 - image4->h / 2;
    Post.positionImage5.x = ecran->w / 2 - image5->w / 2;
    Post.positionImage5.y = ecran->h / 2 - image5->h / 2 - 100;
    Post.positionImage6.x = ecran->w / 2 - image6->w / 2 - 100;
    Post.positionImage6.y = ecran->h / 2 - image6->h / 2;
    Post.positionImage7.x = ecran->w / 2 - image7->w / 2 - 100;
    Post.positionImage7.y = ecran->h / 2 - image7->h / 2 + 100;
    Post.positionImage8.x = ecran->w / 2 - image8->w / 2 + 100;
    Post.positionImage8.y = ecran->h / 2 - image8->h / 2 - 100;
    Post.positionVide.x = ecran->w / 2 - vide->w / 2 + 100;
    Post.positionVide.y = ecran->h / 2 - vide->h / 2 + 100;

	(*Correcte).positionImage1 = Post.positionImage2;
	(*Correcte).positionImage2 = Post.positionImage3;
	(*Correcte).positionImage3 = Post.positionImage7;
	(*Correcte).positionImage4 = Post.positionImage6;
	(*Correcte).positionImage5 = Post.positionImage1;
	(*Correcte).positionImage6 = Post.positionImage4;
	(*Correcte).positionImage7 = Post.positionImage8;
	(*Correcte).positionImage8 = Post.positionImage5;


    positionUp1.x = ecran->w / 2 - image1->w / 2 - 100;
    positionUp1.y = ecran->h / 2 - image1->h / 2 - 200;    
    positionUp2.x = ecran->w / 2 - image1->w / 2;
    positionUp2.y = ecran->h / 2 - image1->h / 2 - 200 ;
    positionUp3.x = ecran->w / 2 - image1->w / 2 + 100;
    positionUp3.y = ecran->h / 2 - image1->h / 2 - 200;

    positionDown1.x = ecran->w / 2 - image1->w / 2 - 100;
    positionDown1.y = ecran->h / 2 - image1->h / 2 + 200;    
    positionDown2.x = ecran->w / 2 - image1->w / 2;
    positionDown2.y = ecran->h / 2 - image1->h / 2 + 200;
    positionDown3.x = ecran->w / 2 - image1->w / 2 + 100;
    positionDown3.y = ecran->h / 2 - image1->h / 2 + 200;

    positionRight1.x = ecran->w / 2 - image1->w / 2 + 200;
    positionRight1.y = ecran->h / 2 - image1->h / 2 - 100;    
    positionRight2.x = ecran->w / 2 - image1->w / 2 + 200;
    positionRight2.y = ecran->h / 2 - image1->h / 2;
    positionRight3.x = ecran->w / 2 - image1->w / 2 + 200;
    positionRight3.y = ecran->h / 2 - image1->h / 2 + 100;

    positionLeft1.x = ecran->w / 2 - image1->w / 2 - 200;
    positionLeft1.y = ecran->h / 2 - image1->h / 2 - 100;    
    positionLeft2.x = ecran->w / 2 - image1->w / 2 - 200;
    positionLeft2.y = ecran->h / 2 - image1->h / 2;
    positionLeft3.x = ecran->w / 2 - image1->w / 2 - 200;
    positionLeft3.y = ecran->h / 2 - image1->h / 2 + 100;


/* -------------------------------------  



carte[0][0]=1;
carte[0][1]=1;
carte[0][2]=1;
carte[0][3]=1;
carte[0][4]=1;

carte[1][0]=1;
carte[1][1]=0;
carte[1][2]=0;
carte[1][3]=0;
carte[1][4]=1;

carte[2][0]=1;
carte[2][1]=0;
carte[2][2]=0;
carte[2][3]=0;
carte[2][4]=1;

carte[3][0]=1;
carte[3][1]=0;
carte[3][2]=0;
carte[3][3]=0;
carte[3][4]=1;

carte[4][0]=1;
carte[4][1]=1;
carte[4][2]=1;
carte[4][3]=1;
carte[4][4]=1;

*/

	police = TTF_OpenFont("Sometimes.ttf",65);
	texte = TTF_RenderText_Blended(police,"Vous avez 5 minutes pour resoudre cet enigme",Noire);

	tempsPrecedent = tempsActuel;
    	tempsActuel = SDL_GetTicks();
    while(continuer)
    {
	tempsActuel = SDL_GetTicks();
		if(tempsActuel - tempsPrecedent >= 1000)
		{
			compteur += 1;
			tempsPrecedent = tempsActuel;
		}
		if(compteur >300)
		{
			Post.Temps = 0;
			continuer = 0;
		}
        SDL_PollEvent(&event);
        switch(event.type)
        {
		
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                    case SDLK_UP: // Flèche haut
                        Post.positionVide.y-=100;

                        if(Post.positionImage1.x==Post.positionVide.x && Post.positionImage1.y==Post.positionVide.y)
                           {
                         	Post.positionImage1.y+=100;    
			   } 
                        if(Post.positionImage2.x==Post.positionVide.x && Post.positionImage2.y==Post.positionVide.y)
                           {
                         	Post.positionImage2.y+=100;    
			   }
                        if(Post.positionImage3.x==Post.positionVide.x && Post.positionImage3.y==Post.positionVide.y)
                           {
                         	Post.positionImage3.y+=100;    
			   }
                        if(Post.positionImage4.x==Post.positionVide.x && Post.positionImage4.y==Post.positionVide.y)
                           {
                         	Post.positionImage4.y+=100;    
			   }
                        if(Post.positionImage5.x==Post.positionVide.x && Post.positionImage5.y==Post.positionVide.y)
                           {
                         	Post.positionImage5.y+=100;    
			   }
                        if(Post.positionImage6.x==Post.positionVide.x && Post.positionImage6.y==Post.positionVide.y)
                           {
                         	Post.positionImage6.y+=100;    
			   }
                        if(Post.positionImage7.x==Post.positionVide.x && Post.positionImage7.y==Post.positionVide.y)
                           {
                         	Post.positionImage7.y+=100;    
			   }
                        if(Post.positionImage8.x==Post.positionVide.x && Post.positionImage8.y==Post.positionVide.y)
                           {
                         	Post.positionImage8.y+=100;    
			   }    
                        if((positionUp1.x==Post.positionVide.x && positionUp1.y==Post.positionVide.y) || (positionUp2.x==Post.positionVide.x && positionUp2.y==Post.positionVide.y) || (positionUp3.x==Post.positionVide.x && positionUp3.y==Post.positionVide.y))
                           {
                         	Post.positionVide.y+=100;   
			   }                     
                        
;

                        break;
                    case SDLK_DOWN: // Flèche bas
                        Post.positionVide.y+=100;

                        if(Post.positionImage1.x==Post.positionVide.x && Post.positionImage1.y==Post.positionVide.y)
                           {
                         	Post.positionImage1.y-=100;    
			   } 
                        if(Post.positionImage2.x==Post.positionVide.x && Post.positionImage2.y==Post.positionVide.y)
                           {
                         	Post.positionImage2.y-=100;    
			   }
                        if(Post.positionImage3.x==Post.positionVide.x && Post.positionImage3.y==Post.positionVide.y)
                           {
                         	Post.positionImage3.y-=100;    
			   }
                        if(Post.positionImage4.x==Post.positionVide.x && Post.positionImage4.y==Post.positionVide.y)
                           {
                         	Post.positionImage4.y-=100;    
			   }
                        if(Post.positionImage5.x==Post.positionVide.x && Post.positionImage5.y==Post.positionVide.y)
                           {
                         	Post.positionImage5.y-=100;    
			   }
                        if(Post.positionImage6.x==Post.positionVide.x && Post.positionImage6.y==Post.positionVide.y)
                           {
                         	Post.positionImage6.y-=100;    
			   }
                        if(Post.positionImage7.x==Post.positionVide.x && Post.positionImage7.y==Post.positionVide.y)
                           {
                         	Post.positionImage7.y-=100;    
			   }
                        if(Post.positionImage8.x==Post.positionVide.x && Post.positionImage8.y==Post.positionVide.y)
                           {
                         	Post.positionImage8.y-=100;    
			   }
                        if((positionDown1.x==Post.positionVide.x && positionDown1.y==Post.positionVide.y) || (positionDown2.x==Post.positionVide.x && positionDown2.y==Post.positionVide.y) || (positionDown3.x==Post.positionVide.x && positionDown3.y==Post.positionVide.y))
                           {
				Post.positionVide.y-=100;
                           }


                        break;
                    case SDLK_RIGHT: // Flèche droite
                        Post.positionVide.x+=100;
                        if(Post.positionImage1.x==Post.positionVide.x && Post.positionImage1.y==Post.positionVide.y)
                           {
                         	Post.positionImage1.x-=100;    
			   } 
                        if(Post.positionImage2.x==Post.positionVide.x && Post.positionImage2.y==Post.positionVide.y)
                           {
                         	Post.positionImage2.x-=100;    
			   }
                        if(Post.positionImage3.x==Post.positionVide.x && Post.positionImage3.y==Post.positionVide.y)
                           {
                         	Post.positionImage3.x-=100;    
			   }
                        if(Post.positionImage4.x==Post.positionVide.x && Post.positionImage4.y==Post.positionVide.y)
                           {
                         	Post.positionImage4.x-=100;    
			   }
                        if(Post.positionImage5.x==Post.positionVide.x && Post.positionImage5.y==Post.positionVide.y)
                           {
                         	Post.positionImage5.x-=100;    
			   }
                        if(Post.positionImage6.x==Post.positionVide.x && Post.positionImage6.y==Post.positionVide.y)
                           {
                         	Post.positionImage6.x-=100;    
			   }
                        if(Post.positionImage7.x==Post.positionVide.x && Post.positionImage7.y==Post.positionVide.y)
                           {
                         	Post.positionImage7.x-=100;    
			   }
                        if(Post.positionImage8.x==Post.positionVide.x && Post.positionImage8.y==Post.positionVide.y)
                           {
                         	Post.positionImage8.x-=100;    
			   }
                        if((positionRight1.x==Post.positionVide.x && positionRight1.y==Post.positionVide.y) || (positionRight2.x==Post.positionVide.x && positionRight2.y==Post.positionVide.y) || (positionRight3.x==Post.positionVide.x && positionRight3.y==Post.positionVide.y))
                           {
				Post.positionVide.x-=100;
                           }

                        break;
                    case SDLK_LEFT: // Flèche gauche
                        Post.positionVide.x-=100;

                        if(Post.positionImage1.x==Post.positionVide.x && Post.positionImage1.y==Post.positionVide.y)
                           {
                         	Post.positionImage1.x+=100;    
			   } 
                        if(Post.positionImage2.x==Post.positionVide.x && Post.positionImage2.y==Post.positionVide.y)
                           {
                         	Post.positionImage2.x+=100;    
			   }
                        if(Post.positionImage3.x==Post.positionVide.x && Post.positionImage3.y==Post.positionVide.y)
                           {
                         	Post.positionImage3.x+=100;    
			   }
                        if(Post.positionImage4.x==Post.positionVide.x && Post.positionImage4.y==Post.positionVide.y)
                           {
                         	Post.positionImage4.x+=100;    
			   }
                        if(Post.positionImage5.x==Post.positionVide.x && Post.positionImage5.y==Post.positionVide.y)
                           {
                         	Post.positionImage5.x+=100;    
			   }
                        if(Post.positionImage6.x==Post.positionVide.x && Post.positionImage6.y==Post.positionVide.y)
                           {
                         	Post.positionImage6.x+=100;    
			   }
                        if(Post.positionImage7.x==Post.positionVide.x && Post.positionImage7.y==Post.positionVide.y)
                           {
                         	Post.positionImage7.x+=100;    
			   }
                        if(Post.positionImage8.x==Post.positionVide.x && Post.positionImage8.y==Post.positionVide.y)
                           {
                         	Post.positionImage8.x+=100;    
			   }  
                        if((positionLeft1.x==Post.positionVide.x && positionLeft1.y==Post.positionVide.y) || (positionLeft2.x==Post.positionVide.x && positionLeft2.y==Post.positionVide.y) || (positionLeft3.x==Post.positionVide.x && positionLeft3.y==Post.positionVide.y))
                           {
				Post.positionVide.x+=100;
                           }  



                        break;
                }
                break;
		
		
        }


	position.x = 0;
	position.y = 0;
    
        
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

	
        SDL_BlitSurface(wallup1, NULL, ecran, &positionUp1);
        SDL_BlitSurface(wallup2, NULL, ecran, &positionUp2);
        SDL_BlitSurface(wallup3, NULL, ecran, &positionUp3);

        SDL_BlitSurface(walldown1, NULL, ecran, &positionDown1);
        SDL_BlitSurface(walldown2, NULL, ecran, &positionDown2);
        SDL_BlitSurface(walldown3, NULL, ecran, &positionDown3);

        SDL_BlitSurface(wallright1, NULL, ecran, &positionRight1);
        SDL_BlitSurface(wallright2, NULL, ecran, &positionRight2);
        SDL_BlitSurface(wallright3, NULL, ecran, &positionRight3);

        SDL_BlitSurface(wallleft1, NULL, ecran, &positionLeft1);
        SDL_BlitSurface(wallleft2, NULL, ecran, &positionLeft2);
        SDL_BlitSurface(wallleft3, NULL, ecran, &positionLeft3);
        SDL_BlitSurface(background, NULL, ecran, &positionBackGround);
	SDL_BlitSurface(texte, NULL, ecran, &position);
	SDL_BlitSurface(back, NULL, ecran, &positionBack);
        SDL_BlitSurface(vide, NULL, ecran, &Post.positionVide);
        SDL_BlitSurface(image2, NULL, ecran, &Post.positionImage2);
        SDL_BlitSurface(image3, NULL, ecran, &Post.positionImage3);
        SDL_BlitSurface(image4, NULL, ecran, &Post.positionImage4);
        SDL_BlitSurface(image5, NULL, ecran, &Post.positionImage5);
        SDL_BlitSurface(image6, NULL, ecran, &Post.positionImage6);
        SDL_BlitSurface(image7, NULL, ecran, &Post.positionImage7);
        SDL_BlitSurface(image8, NULL, ecran, &Post.positionImage8);
        SDL_BlitSurface(image1, NULL, ecran, &Post.positionImage1);
 
        SDL_Flip(ecran);
   }

	TTF_CloseFont(police);
	TTF_Quit();

	SDL_FreeSurface(texte);
	SDL_Quit();
    SDL_FreeSurface(background);
    SDL_FreeSurface(back);
    SDL_FreeSurface(image1);
    SDL_FreeSurface(image2);
    SDL_FreeSurface(image3);
    SDL_FreeSurface(image4);
    SDL_FreeSurface(image5);
    SDL_FreeSurface(image6);
    SDL_FreeSurface(image7);
    SDL_FreeSurface(image8);
    SDL_FreeSurface(vide);

    SDL_FreeSurface(wallup1);
    SDL_FreeSurface(wallup2);
    SDL_FreeSurface(wallup3);

    SDL_FreeSurface(walldown1);
    SDL_FreeSurface(walldown2);
    SDL_FreeSurface(walldown3);

    SDL_FreeSurface(wallright1);
    SDL_FreeSurface(wallright2);
    SDL_FreeSurface(wallright3);

    SDL_FreeSurface(wallleft1);
    SDL_FreeSurface(wallleft2);
    SDL_FreeSurface(wallleft3);

    SDL_Quit();

    return Post;
}

int resolution_enigme(int collision,int* score)
{ 
	SDL_Surface *ecran = NULL;
	Position Puzz, Correcte;
	SDL_Init(SDL_INIT_VIDEO);
	ecran = SDL_SetVideoMode(1080, 720, 32, SDL_HWSURFACE);
	SDL_Event event;
	
   	
	
	
		if(collision == 1){
			Puzz = puzzle(&Correcte);
			if(Puzz.Temps == Correcte.Temps){
				(*score)+=100;
			}
			else
			{
				if(Puzz.Temps!=1){
					(*score)-=100;
				}			
			}
		}
			
	
    	

	return EXIT_SUCCESS;
}



