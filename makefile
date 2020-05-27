prog: background.o button.o  menu.o hero.o game.o player.o CollisionParfaite.o scrolling.o anime.o game2.o main.o
	gcc background.o button.o  menu.o hero.o game.o player.o CollisionParfaite.o scrolling.o anime.o game2.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer 
main.o:main.c
	gcc -c main.c 
game2.o:game2.c
	gcc -c game2.c
anime.o:anime.c
	gcc -c anime.c
scrolling.o:scrolling.c
	gcc -c scrolling.c
CollisionParfaite.o:CollisionParfaite.c
	gcc -c CollisionParfaite.c
player.o:player.c
	gcc -c player.c
game.o:game.c
	gcc -c game.c
hero.o:hero.c
	gcc -c hero.c
menu.o:menu.c
	gcc -c menu.c
button.o:button.c
	gcc -c button.c 
background.o:background.c
	gcc -c background.c


