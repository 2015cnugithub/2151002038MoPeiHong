// ��һ��.cpp : �������̨Ӧ�ó������ڵ㡣
//
//1. ����һ����Ʒ��CGoods�����а�����Ʒ��(long no)����Ʒ��(char *p_name)����Ʒ�۸�(double price)�������ݳ�Ա��
//�Լ���Ӧ�Ĺ��캯�����������캯����������������ӡ���ݳ�Ա�ĳ�Ա������

#include<iostream>
#include<stdio.h>
#include <string.h> 
using namespace std;
class CGoods{
public:
	CGoods(long new_no,char *new_p_name,double new_price);                 //���캯��
	CGoods( CGoods &Goods);                                                //�������캯��
	~CGoods()                                                              //��������
	{
		delete p_name;
	}
void print();                                                              //��ӡ��Ա����


private:                                                                   //���ݳ�Ա
	long no;
	char *p_name;
	double price;

};
//���캯����ʵ��
CGoods::CGoods(long new_no, char *new_p_name, double new_price){
	no=new_no;
	p_name=new char[strlen(new_p_name)+1];                          //��̬����һ�����ȵ��ַ�����ռ䣬���������׵�ַ����ָ�����p_name.
	strcpy(p_name,new_p_name);
	price=new_price;
	cout<<"���캯����ʵ��"<<endl;
}

//�������캯��ʵ��
CGoods::CGoods( CGoods &Goods)
{
	no=Goods.no;
	p_name=new char[strlen(Goods.p_name)+1];
	strcpy(p_name,Goods.p_name);
	price=Goods.price;
	cout<<"�������캯����ʵ��"<<endl;

}
//��ӡ���ݳ�Ա����ʵ��
void CGoods::print(){
	cout<<"��Ʒ��:"<<no<<endl;
	cout<<"��Ʒ��: "<<p_name<<endl;
	cout<<"��Ʒ�۸�:"<<price<<endl;
}
int main()
{
	
	CGoods Goods(1,"apple",2.3);                                        //�������myGoods         
	Goods.print();                                                      //��ʾ���ݳ�Ա
	CGoods myCGoods=Goods;                                              //��myGoods��ʼ��myCGoods�����ÿ������캯��
	myCGoods.print();                                                     //��ʾ�������캯�����ݳ�Ա

	return 0;
}