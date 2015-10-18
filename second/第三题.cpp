// 第三题.cpp : 定义控制台应用程序的入口点。
//为CGoods类定义小于运算符(‘<’)和不小于运算符(‘>=’)两个运算符重载函数。
//CGoods类对象大小的比较是根据其商品价格(price)的值的大小来实现的。(与第2问相同的不用再重复)

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	CGoods(long new_no,char *new_p_name,double new_price);    //构造函数
	CGoods( CGoods &Goods);                                   //拷贝构造函数
	~CGoods()                                                 //析构函数
	{
		delete p_name;
		count--;
	}
void print();                                                 //打印成员函数
static int getCount();                                        //增加的成员函数
friend char*getName(CGoods &name);                            //增加的友元函数
bool operator<(CGoods &a);                                    //运算符<重载成员函数
bool operator>=(CGoods &b);                                   //运算符>=重载成员函数

private:                                                      //数据成员
	long no;
	char *p_name;
	double price;
static	int count;                                            //静态数据成员声明，用于统计商品总数

};
int CGoods::count=0;                                          //使用类名限定静态数据成员，定义并初始化

//构造函数的实现
CGoods::CGoods(long new_no, char *new_p_name, double new_price)
{
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];                //动态分配一个长度的字符数组空间，并把数组首地址赋给指针变量p_name.
	strcpy(p_name,new_p_name);
	price=new_price;
	count++;
}

//拷贝构造函数实现
CGoods::CGoods( CGoods &Goods)
{
	count=0;
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];
	strcpy(p_name,Goods.p_name);
	price=Goods.price;
	count++;

}
//打印数据成员函数实现
void CGoods::print()
{
	cout<<"商品号:"<<no<<endl;
	cout<<"商品名: "<<p_name<<endl;
	cout<<"商品价格:"<<price<<endl;
}
//实现获取商品总数
int CGoods::getCount()
{
	cout<<"商品总数:"<<count<<endl;
	return count;
}

//实现获取商品p_name函数
char *getName(CGoods &name)
{
	cout<<"获取商品名:"<<name.p_name<<endl;
	return name.p_name;
}
//小于运算符重载函数实现
bool CGoods::operator <(CGoods &a)
{
	if(price<a.price)
	{
		cout<<"小于运算符重载成功"<<endl;
		cout<<"price:"<<price<<endl;
		cout<<"a.price:"<<a.price<<endl;
		return true;
	}
	else
	{
		cout<<"小于运算符重载不成功"<<endl;
		return false;
	}
}
//大于等于运算符重载函数显示实现
bool CGoods::operator >=(CGoods &b)
{
	if(price>=b.price)
	{
		cout<<"大于等于运算符重载成功"<<endl;
		cout<<"price:"<<price<<endl;
		cout<<"b.price"<<b.price<<endl;
		return true;
	}
	else
	{
		cout<<"大于等于运算符重载不成功"<<endl;
		return false;
	}
}
int main()
{
	
	CGoods Goods(1,"apple",2.3);
	Goods.print();
	CGoods myCGoods=Goods;
	myCGoods.print();
	char *Name=getName(Goods);
	CGoods::getCount();
	CGoods D1(2,"apple1",2.2),D2(3,"apple2",2.4),D3(4,"apple2",3.0);
	
	D1.operator <(D2);
	D1.operator >=(D2);
	D2.operator >=(D3);
	D3.operator >=(D2);

	return 0;
}

