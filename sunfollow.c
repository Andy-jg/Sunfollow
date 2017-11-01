#include "sunfollow.h"

/********************************************************************************
input:
	dest: 为转换后的结果
	p->addr[0]: 高地址
	p->addr[1]: 低地址
	p->type: 记录类型
	p->data: 为bin格式流有效数据指针
	p->len: 为bin格式流有效数据长度
output:
	返回有效数据的长度
********************************************************************************/


float x=0;
int formangle=0;
int sunangle=0;

int indexTime=0;
//int sunangle=0;  
// HOUR FORANGLE SUNANGLE
const float  formAngTab[FORMHOUR][FORANGLENUM]=
	{
		{90,90},  //0
		{90,90},  //0.30
		{90,90},  // 1
		{90,90},  // 1.30
		{90,90},  // 2
		{90,90},  // 2.30
		{90,90},  // 3
		{90,90},  // 3.30
		{90,90},  // 4
		{90,90},  // 4.30
		{90,90},  // 5
		{90,90},  // 5.30
		{145,150},  // 6
		{140.5,147},  // 6.30
		{136,144},  // 7
		{131.5,141},  // 7.30
		{127,138},  // 8
		{122.5,135},  // 8.30
		{118,132},  // 9
		{113.5,129},  // 9.30
		{109,126},  // 10
		{104.5,123},  // 10.30
		{100,120},  // 11
		{95.5,117},  // 11.30
		{90,114},  // 12		
		{85.5,117},  // 12.30
		{81,120},  // 13
		{76.5,123},  // 13.30
		{72,126},  // 14
		{67.5,129},  // 14.30
		{63,132},  // 15
		{58.5,135},  // 15.30
		{54,138},  // 16
		{49.5,141},  // 16.30
		{45,144},  // 17
		{40.5,147},  // 17.30
		{36,150},  // 18
		{90,90},  // 18.30
		{90,90},  // 19
		{90,90},  // 19.30
		{90,90},  // 20
		{90,90},  // 20.30
		{90,90},  // 21
		{90,90},  // 21.30
		{90,90},  // 22
		{90,90},  // 22.30
		{90,90},  // 23
		{90,90},  // 23.30
		{90,90},  // 24
		{90,90},  // debug
		{90,90},  // debug.
	};


time_t t;
struct tm * lt;

 void worktimecalc(void)
{

	time (&t);//��ȡUnixʱ�����
	lt = localtime (&t);//תΪʱ��ṹ��
	printf ( "%d/%d/%d %d:%d:%d\n",lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//������
	if(0==(uint8_t)lt->tm_min)
	{
		indexTime=lt->tm_hour*2;
	}
	else if(30==(uint8_t)lt->tm_min)
	{
		indexTime=lt->tm_hour*2+1;
	}
	else 
	{
		indexTime=lt->tm_hour*2;
	}
	formangle=formAngTab[indexTime][0];
	sunangle=formAngTab[indexTime][1];
	printf("formangle is %d , sunangle is %d ,time index is %d \n",formangle,sunangle,indexTime);
}
void mirrormove(void)
{
	//every 30min work ..
	worktimecalc();
	unsigned char  k=PWM_WORKTIME;//180次循环的时间够了

	printf("sun folow sys,please input formangle and sunangle\n");
	//scanf("%d%d",&formangle,&sunangle);

	if(formangle<FORMangleMin)
	{
		formangle=FORMangleMin;
		printf("formangle is %d too low get the lim min!!\n",formangle);


	}
	else if(formangle>FORMangleMax)
	{
		formangle=FORMangleMax;
		printf("formangle is %d too big get the lim max !!\n",formangle);
	}
	else
	{
		printf("formangle is %d nomal  !!\n",formangle);
	}

	if(sunangle<SUNangleMin)
	{
		sunangle=SUNangleMin;
		printf("sunangle is %d too low get the lim min!!\n",sunangle);

	}
	else if(sunangle>SUNangleMax)
	{
		sunangle=SUNangleMax;
		printf("sunangle is %d too big get the lim max !!\n",sunangle);
	}
	else
	{
		printf("formangle is %d nomal  !!\n",sunangle);
	}


	for(k=0; k<PWM_WORKTIME; k++) //(k--)
	{
		x=11.11*sunangle;
		digitalWrite(Psunangle,LOW);
		delayMicroseconds(PWMD5MS+x);
		digitalWrite(Psunangle,HIGH);
		delayMicroseconds(PWM19MS-x);

	}
	delayMicroseconds(MOTO1TO2DELAY);
	for(k=0; k<PWM_WORKTIME; k++) //(k--)
	{
		x=11.11*formangle;
		digitalWrite(Pformangle,LOW);
		delayMicroseconds(PWMD5MS+x);
		digitalWrite(Pformangle,HIGH);
		delayMicroseconds(PWM19MS-x);

	}
}



