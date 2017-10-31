#include<stdio.h>
#include<wiringPi.h>
#define Pformangle 5
#define Psunangle 1
void init();
int main()
{
        init();
        int formangle=0;
		int sunangle=0;
		printf("sun folow sys,please input formangle and sunangle\n");  
        scanf("%d%d",&formangle,&sunangle);

        int i=0;
        float x=0;

       unsigned char  k=2;//180次循环的时间够了
        for(k=0;k<2;k++)//(k--)
        {
                x=11.11*sunangle;
                digitalWrite(Psunangle,LOW);
                delayMicroseconds(500+x);
				digitalWrite(Psunangle,HIGH);
				delayMicroseconds(19500-x);
        
         }
		 delayMicroseconds(2000000);
		 for(k=0;k<2;k++)//(k--)
        {
                x=11.11*formangle;
                digitalWrite(Pformangle,LOW);
                delayMicroseconds(500+x);
				digitalWrite(Pformangle,HIGH);
				delayMicroseconds(19500-x);
        
         }
		 
	printf("Game Over");        
        return 0;
}


void init()
{
        wiringPiSetup();
        pinMode(Psunangle,OUTPUT);
		pinMode(Pformangle,OUTPUT);
}
