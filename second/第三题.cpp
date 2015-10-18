// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//ΪCGoods�ඨ��С�������(��<��)�Ͳ�С�������(��>=��)������������غ�����
//CGoods������С�ıȽ��Ǹ�������Ʒ�۸�(price)��ֵ�Ĵ�С��ʵ�ֵġ�(���2����ͬ�Ĳ������ظ�)

#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
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

	return 0;
}

