// 第二题.cpp : 定义控制台应用程序的入口点。
//
//2.为CGoods类增加一个商品总数(int count)数据成员，并增加一个成员函数getCount()获取count的值，
//编写一个友元函数getName()获取商品名称p_name。做如上修改后，重新实现CGoods类(与第1问相同的不用再重复)
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	CGoods(long new_no,char *new_p_name,double new_price);       //构造函数
	CGoods( CGoods &Goods);                                      //拷贝构造函数
	~CGoods()                                                    //析构函数
	{
		delete p_name;
		cout<<"析构函数的实现"<<endl;
		count--;
	}
void print();                                                   //打印成员函数
static int getCount();                                          //获取商品成员函数
friend char*getName(CGoods &name);                              //获取商品名的友元函数


private:                                                       //数据成员
	long no;
	char *p_name;
	double price;
static	int count;                                            //静态数据成员声明，用于获取商品总数

};
int CGoods::count=0;                                          //使用类名限定静态数据成员，定义并初始化

//构造函数的实现
CGoods::CGoods(long new_no, char *new_p_name, double new_price)
{
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];
	strcpy(p_name,new_p_name);
	price=new_price;
	count++;
}

//拷贝构造函数实现
CGoods::CGoods( CGoods &Goods)
{
	count=0;
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];                //动态分配一个长度的字符数组空间，并把数组首地址赋给指针变量p_name.
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
	cout<<"友元获取的商品名:"<<name.p_name<<endl;
	return name.p_name;
}
int main()
{
	
	CGoods Goods(1,"apple",2.3);                      //定义对象myGoods                     
	Goods.print();                                    //显示数据成员
	CGoods myCGoods=Goods;                            //用myGoods初始化myCGoods,调用拷贝构造函数
	myCGoods.print();                                   //显示拷贝构造数据成员
	char *Name=getName(Goods);                        //显示友元函数获取商商品名
	CGoods::getCount();                                 //显示商品总数
	return 0;
}