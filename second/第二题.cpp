// �ڶ���.cpp : �������̨Ӧ�ó������ڵ㡣
//
//2.ΪCGoods������һ����Ʒ����(int count)���ݳ�Ա��������һ����Ա����getCount()��ȡcount��ֵ��
//��дһ����Ԫ����getName()��ȡ��Ʒ����p_name���������޸ĺ�����ʵ��CGoods��(���1����ͬ�Ĳ������ظ�)
#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	CGoods(long new_no,char *new_p_name,double new_price);       //���캯��
	CGoods( CGoods &Goods);                                      //�������캯��
	~CGoods()                                                    //��������
	{
		delete p_name;
		cout<<"����������ʵ��"<<endl;
		count--;
	}
void print();                                                   //��ӡ��Ա����
static int getCount();                                          //��ȡ��Ʒ��Ա����
friend char*getName(CGoods &name);                              //��ȡ��Ʒ������Ԫ����


private:                                                       //���ݳ�Ա
	long no;
	char *p_name;
	double price;
static	int count;                                            //��̬���ݳ�Ա���������ڻ�ȡ��Ʒ����

};
int CGoods::count=0;                                          //ʹ�������޶���̬���ݳ�Ա�����岢��ʼ��

//���캯����ʵ��
CGoods::CGoods(long new_no, char *new_p_name, double new_price)
{
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];
	strcpy(p_name,new_p_name);
	price=new_price;
	count++;
}

//�������캯��ʵ��
CGoods::CGoods( CGoods &Goods)
{
	count=0;
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];                //��̬����һ�����ȵ��ַ�����ռ䣬���������׵�ַ����ָ�����p_name.
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
	cout<<"��Ԫ��ȡ����Ʒ��:"<<name.p_name<<endl;
	return name.p_name;
}
int main()
{
	
	CGoods Goods(1,"apple",2.3);                      //�������myGoods                     
	Goods.print();                                    //��ʾ���ݳ�Ա
	CGoods myCGoods=Goods;                            //��myGoods��ʼ��myCGoods,���ÿ������캯��
	myCGoods.print();                                   //��ʾ�����������ݳ�Ա
	char *Name=getName(Goods);                        //��ʾ��Ԫ������ȡ����Ʒ��
	CGoods::getCount();                                 //��ʾ��Ʒ����
	return 0;
}