#include<stdio.h>
#include"sunfollow.h"
#define Pformangle 5
#define Psunangle 1
void init();
int main()
{

	init();
	
	mirrormove();
	printf("Game Over ! \n");
	return 0;
}


void init()
{
	wiringPiSetup();
	pinMode(Psunangle,OUTPUT);
	pinMode(Pformangle,OUTPUT);
}
