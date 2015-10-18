// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//Ϊ���ܹ����ö�̬����ķ�ʽ�����������usedFor()��Ա������Ӧ����CGoods�༰��������CClothes��CFood�������θĶ���

//�����ǽ�ģ����ߺ����ϲ���һ�����ɿ�ִ�д���Ĺ��̣�ͬʱ��ÿ��ģ����÷����ڴ��ַ�����Ҷ��ⲿ����Ҳ������ȷ���ڴ��ַ
//��ʵ�ֶ�̬����Ҫ�����麯������ʵ�ֶ�̬�������߱�����������һ�ǹ��м̳У����ǻ����ָ��������ü��ָ�����������
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	virtual void usedFor(){cout<<"��̬�����ʵ��"<<endl;}     //�����麯��ʵ�ֶ�̬����
	void printf(){usedFor();}                                 //��̬����ʵ�����
	CGoods(long new_no,char *new_p_name,double new_price);    //���캯��
	CGoods( CGoods &Goods);                                   //�������캯��
	~CGoods()                                                 //��������
	{
		delete p_name;
		count--;
	}
void print();                                                 //��ӡ��Ա����
static int getCount();                                        //���ӵĳ�Ա����
friend char*getName(CGoods &name);                            //���ӵ���Ԫ����
bool operator<(CGoods &a);                                    //�����<���س�Ա����
bool operator>=(CGoods &b);                                   //�����>=���س�Ա����

private:                                                      //���ݳ�Ա
	long no;
	char *p_name;
	double price;
static	int count;                                            //��̬���ݳ�Ա����������ͳ����Ʒ����

};
//������װ���ʵ��
class CClothes:public CGoods{
private:
	char *p_brand;
public:
	 CClothes(long C_no,char *C_p_name,double C_price,char *C_p_brand):CGoods(C_no, C_p_name, C_price)
	{
		p_brand=new char[strlen(C_p_brand)+1];              //��̬����һ�����ȵ��ַ�����ռ䣬���������׵�ַ����ָ�����p_brand.
		strcpy(p_brand,C_p_brand);
	}
	~CClothes(){delete p_brand;}
	void usedFor()                                       //��CClothes����û��˵��usedFor���麯��������CClothes�̳���virtual������
	{ 
		cout<<"��Ա����ʵ��"<<endl;
		cout<<"��װ����"<<p_brand<<endl;
		 
	}
};
//����ʳƷ���ʵ��
class CFood:public CGoods
{
private:
	    char *p_brand;
public:
     
	CFood(long F_no,char *F_name,double F_price,char *F_p_brand):CGoods(F_no,F_name,F_price)
	{
		p_brand=new char[strlen(F_p_brand)+1];               //��̬����һ�����ȵ��ַ�����ռ䣬���������׵�ַ����ָ�����p_brand              
		strcpy(p_brand,F_p_brand);
	}
	~CFood(){delete p_brand;}
	void usedFor() //��CFood����û��˵��usedFor���麯��������CFood�̳���virtual������
	{
        
		cout<<"��Ա����ʵ��"<<endl;
		cout<<"ʳƷ��;��"<<p_brand<<endl;
	}

};
int CGoods::count=0;                                          //ʹ�������޶���̬���ݳ�Ա�����岢��ʼ��

//���캯����ʵ��
CGoods::CGoods(long new_no, char *new_p_name, double new_price)
{
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];                //��̬����һ�����ȵ��ַ�����ռ䣬���������׵�ַ����ָ�����p_name.
	strcpy(p_name,new_p_name);
	price=new_price;
	count++;
}

//�������캯��ʵ��
CGoods::CGoods( CGoods &Goods)
{
	count=0;
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];
	strcpy(p_name,Goods.p_name);
	price=Goods.price;
	count++;

}
//��ӡ���ݳ�Ա����ʵ��
void CGoods::print()
{
	cout<<"��Ʒ��:"<<no<<endl;
	cout<<"��Ʒ��: "<<p_name<<endl;
	cout<<"��Ʒ�۸�:"<<price<<endl;
}
//ʵ�ֻ�ȡ��Ʒ����
int CGoods::getCount()
{
	cout<<"��Ʒ����:"<<count<<endl;
	return count;
}

//ʵ�ֻ�ȡ��Ʒp_name����
char *getName(CGoods &name)
{
	cout<<"��ȡ��Ʒ��:"<<name.p_name<<endl;
	return name.p_name;
}
//С����������غ���ʵ��
bool CGoods::operator <(CGoods &a)
{
	if(price<a.price)
	{
		cout<<"С����������سɹ�"<<endl;
		cout<<"price:"<<price<<endl;
		cout<<"a.price:"<<a.price<<endl;
		return true;
	}
	else
	{
		cout<<"С����������ز��ɹ�"<<endl;
		return false;
	}
}
//���ڵ�����������غ�����ʾʵ��
bool CGoods::operator >=(CGoods &b)
{
	if(price>=b.price)
	{
		cout<<"���ڵ�����������سɹ�"<<endl;
		cout<<"price:"<<price<<endl;
		cout<<"b.price"<<b.price<<endl;
		return true;
	}
	else
	{
		cout<<"���ڵ�����������ز��ɹ�"<<endl;
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
	CClothes Clothes(2,"bananas",10.0,"����");
	Clothes.CGoods::print();
	Clothes.usedFor();
	CFood Food(6,"peach",6.2,"ˮ����Ƥ�ܱ�������ḻ��������ʳ����ڻ���������");
	Food.CGoods::print();
	Food.usedFor();
	CClothes clothes(2,"��װ",100,"�̿�");
	clothes.printf();
	CFood food(6,"ɽ�",6.2,"���");
	food.printf();

	


	return 0;
}



