// 第五题.cpp : 定义控制台应用程序的入口点。
//为了能够采用动态联编的方式调用派生类的usedFor()成员函数，应该在CGoods类及其派生类CClothes和CFood类中作何改动？

//联编是将模块或者函数合并在一起生成可执行代码的过程，同时对每个模块调用分配内存地址，并且对外部访问也分配正确的内存地址
//而实现动态联编要调用虚函数若想实现动态联编必须具备两个条件：一是共有继承，二是基类的指针或者引用间接指向派生类对象。
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	virtual void usedFor(){cout<<"动态联编的实现"<<endl;}     //定义虚函数实现动态联编
	void printf(){usedFor();}                                 //动态联编实现输出
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
//派生服装类的实现
class CClothes:public CGoods{
private:
	char *p_brand;
public:
	 CClothes(long C_no,char *C_p_name,double C_price,char *C_p_brand):CGoods(C_no, C_p_name, C_price)
	{
		p_brand=new char[strlen(C_p_brand)+1];              //动态分配一个长度的字符数组空间，并把数组首地址赋给指针变量p_brand.
		strcpy(p_brand,C_p_brand);
	}
	~CClothes(){delete p_brand;}
	void usedFor()                                       //类CClothes类中没有说明usedFor是虚函数，但是CClothes继承了virtual的性质
	{ 
		cout<<"成员函数实现"<<endl;
		cout<<"服装名："<<p_brand<<endl;
		 
	}
};
//派生食品类的实现
class CFood:public CGoods
{
private:
	    char *p_brand;
public:
     
	CFood(long F_no,char *F_name,double F_price,char *F_p_brand):CGoods(F_no,F_name,F_price)
	{
		p_brand=new char[strlen(F_p_brand)+1];               //动态分配一个长度的字符数组空间，并把数组首地址赋给指针变量p_brand              
		strcpy(p_brand,F_p_brand);
	}
	~CFood(){delete p_brand;}
	void usedFor() //类CFood类中没有说明usedFor是虚函数，但是CFood继承了virtual的性质
	{
        
		cout<<"成员函数实现"<<endl;
		cout<<"食品用途："<<p_brand<<endl;
	}

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
	CClothes Clothes(2,"bananas",10.0,"上衣");
	Clothes.CGoods::print();
	Clothes.usedFor();
	CFood Food(6,"peach",6.2,"水蜜桃皮很薄，果肉丰富，宜于生食，入口滑润不留渣子");
	Food.CGoods::print();
	Food.usedFor();
	CClothes clothes(2,"服装",100,"短裤");
	clothes.printf();
	CFood food(6,"山楂",6.2,"解渴");
	food.printf();

	


	return 0;
}



