// 第一题.cpp : 定义控制台应用程序的入口点。
//
//1. 定义一个商品类CGoods，其中包含商品号(long no)、商品名(char *p_name)、商品价格(double price)三个数据成员，
//以及相应的构造函数、拷贝构造函数、析构函数、打印数据成员的成员函数。

#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	CGoods(long new_no,char *new_p_name,double new_price);                 //构造函数
	CGoods( CGoods &Goods);                                                //拷贝构造函数
	~CGoods()                                                              //析构函数
	{
		delete p_name;
	}
void print();                                                              //打印成员函数


private:                                                                   //数据成员
	long no;
	char *p_name;
	double price;

};
//构造函数的实现
CGoods::CGoods(long new_no, char *new_p_name, double new_price){
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];                          //动态分配一个长度的字符数组空间，并把数组首地址赋给指针变量p_name.
	strcpy(p_name,new_p_name);
	price=new_price;
	cout<<"构造函数的实现"<<endl;
}

//拷贝构造函数实现
CGoods::CGoods( CGoods &Goods)
{
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];
	strcpy(p_name,Goods.p_name);
	price=Goods.price;
	cout<<"拷贝构造函数的实现"<<endl;

}
//打印数据成员函数实现
void CGoods::print(){
	cout<<"商品号:"<<no<<endl;
	cout<<"商品名: "<<p_name<<endl;
	cout<<"商品价格:"<<price<<endl;
}
int main()
{
	
	CGoods Goods(1,"apple",2.3);                                        //定义对象myGoods         
	Goods.print();                                                      //显示数据成员
	CGoods myCGoods=Goods;                                              //用myGoods初始化myCGoods，调用拷贝构造函数
	myCGoods.print();                                                     //显示拷贝构造函数数据成员

	return 0;
}