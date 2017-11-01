#ifndef SUNFOLLOW_H 
#define SUNFOLLOW_H
#include <stdio.h>
#include<wiringPi.h>
#include<time.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned long uint32_t;
/***********************************
*********************************************
就是每次读写bin文件N个字节，然后再转化为hex格式流，hex格式流长度计算方式
: + 长度 + 地址 + 类型 + N个数据(N >= 0) + 校验
1 + 2	 + 4	+ 2	   + N * 2			 + 2
********************************************************************************/
#define Pformangle 5
#define Psunangle 1
#define MOTO1TO2DELAY 2000000

#define PWM19MS 19500
#define PWMD5MS 500

#define PWM_WORKTIME 2

#define FORMHOUR 26*2
#define FORANGLENUM 2


#define FORMangleMax 145
#define FORMangleMin  36

#define SUNangleMax 150
#define SUNangleMin  114

void mirrormove(void);

#endif
