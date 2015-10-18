// 万年历表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
//判断平年或者闰年
int leap(int year)
{
	if(year%4==0&&year%100!=0||year%400==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//计算每一年每月的天数
int month_days(int year,int month)
{
	if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
	{
		return 31;
	}
	if(month==4||month==6||month==9||month==11)
	{
		return 30;
	}
	if(month==2&&leap(year)==1)               //对闰年还是平年的二月的天数进行判断
	{
		return 29;
	}
	else
	{
		return 28;
	}
}
//计算每个月的第一天是星期几
int month_firstday(int year,int month)
{
	if(month==1||month==2)
	{
		month=month+12;
		year=year-1;
	}
	int week=-1;
	week=(1+2*month+3*(month+1)/5+year+year/4+year/400-year/100+1)%7; //计算一个月第一天是星期几
	return week;
}
int main()
{
	int i;
	int j=1;
	int k=1;
	int a;
	int b;
	int month;
	int year;
	printf("\n input year、month:\n");
	scanf("%d%d",&year,&month);
	b=month_days(year,month);                //每个月的天数
	a=month_firstday(year,month);            //每月的第一天是星期几
	printf("  日  一  二  三  四  五  六 \n");
	if(a==7)
	{
		for(i=1;i<=b;i++)
		{
			printf("%4d",i);
			if(i%7==0)
			{
				printf(" \n");
			}
		}
	}
	if(a!=7)
	{
		while(j<4*a)
		{
			printf(" ");
			j++;
		}
	}
	for(i=1;i<=b;i++)
	{
		printf("%4d",i);
		if(i==7*k-a)
		{
			printf("\n");
				k++;
		}
	}
	printf("\n");
	return 0;

}

