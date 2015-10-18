//���һ���������Worker�����Ӹû�������������ʱ������HourlyWorker�ͼ�н������SalariedWorker��ÿ�����˶���������name������age���Ա�sex��Сʱ���ʶ�pay_per_hour�����ԣ���н�����Ա����void Compute_pay(double hours)��
//�����в���hoursΪÿ�ܵ�ʵ�ʹ���ʱ������������ʾ���˵Ļ�����Ϣ�ı�׼����������Ԫ����ostream&operator<<(ostream&out, Worker&worker)�����˵�н��ȼ���Сʱ���ʶ�֣�
//��ʱ���˵�н��ȼ���Ϊ10��20��40 US$/hour�����ȼ�����н���˵�н��ȼ�����Ϊ30��50 US$/hour�����ȼ�����ͬ���͵ȼ����˵���н���㷽����ͬ����ʱ������н�ļ��㷽���ǣ�
//���ÿ�ܵĹ���ʱ����hours����40���ڣ�����н = Сʱ���ʶ��ʵ�ʹ���ʱ�������ÿ�ܵĹ���ʱ����hours������40������н= Сʱ���ʶ�� 40 + 1.5 ��Сʱ���ʶ����ʵ�ʹ���ʱ�� �C 40����
//����н����н�ļ��㷽���ǣ����ÿ�ܵ�ʵ�ʹ���ʱ��������35Сʱ����40Сʱ����н�������а�������յ���/���٣�������40Сʱ���ֲ���н������н= Сʱ���ʶ�� 40�����ÿ�ܵ�ʵ�ʹ���ʱ������35Сʱ������35Сʱ��������н= Сʱ���ʶ�ʵ�ʹ���ʱ��+ 0.5 ��Сʱ���ʶ�� (35 - ʵ�ʹ���ʱ��)��
//Ҫ��
//1. ����Worker��HourlyWorker��SalariedWorker�࣬��ʵ�����ǵĲ�ͬ��н���㷽����2.��������main()��ʹ��HourlyWorker��SalariedWorker��������²�����
//��ͨ������̨���롢�������˳����ɶ�5����ͬ���˵Ļ�����Ϣ�����������䡢�Ա�����н��ȼ�����ע�ᡣע�⣬5������Ӧ���������๤�˵�5���ȼ���
//��ͨ��һ���˵��ṹʵ����5�������п�������ѡ��һ�����ˣ���ʾ�ù��˵Ļ�����Ϣ������ÿ�ܵ�ʵ�ʹ���ʱ����ͨ������̨���룩���㲢��ʾ�ù��˵���н��ֱ��ѡ���˳�������
//��ʾ��
//1.���Զ���һ��Worker���ָ������Worker* workers[5];����ָ��5����̬������HourlyWorker��SalariedWorker�����ע�⣬�������ǰ��Ӧ������Щ��̬�����Ķ���
//2.����ΪWorker������һ����Ա����void Name();�����ڲ˵��ṹ����ʾÿ�����˵�������Ϊ�û�ѡ��Ĳ˵��

//���л���vs2005
#include "stdafx.h"
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

//����Worker������
class Worker
{
	protected:                                                               //���屣�����ͳ�Ա����
		string name;
		int age;
		string sex;
		double pay_per_hour;
	public: 
		virtual void Compute_pay(double hours)const= 0;                      //���麯�� 
	    void Name();               
	    void getName(string name);                                           //���ù���������Ա����
	    void getAge(int age);                                                //���ù��������Ա����
	    void getSex(string sex);                                             //���ù����Ա��Ա����
	    void getPay(int pay_per_hour);                                       //���ù���ʱн��Ա����
		friend ostream& operator<<(ostream& out,Worker& worker);             //��ʾ���˻�����Ϣ��Ԫ����
};
//��ʾ���˻�����Ϣʵ��
ostream& operator<<(ostream& output,Worker& w)
{
	output<<"name:"<<w.name<<"age:"<<w.age<<"sex:"<<w.sex<<"pay_per_hour:"<<w.pay_per_hour<<endl; 
	return output;
}
//ʵ�ָ���Ա����
void Worker::Name()
{
	cout<<this->name;
}
void Worker::getName(string name)
{
	this->name=name;
}
void Worker::getSex(string sex)
{
	this->sex=sex;
}
void Worker::getAge(int  age)
{
	this->age=age;
}
void Worker::getPay(int pay_per_hour)
{
	this->pay_per_hour=pay_per_hour;
}

//�����ʱ����������
class HourlyWorker:public Worker
{
	public:
		 void Compute_pay(double hours)const ;                         //����ʵ�ּ�ʱ������н�����Ա����
};
//ʵ�ּ�ʱ������н����
void HourlyWorker::Compute_pay(double hours) const
{
	double salary=0;
	if(hours>40)
	{
	    salary = this->pay_per_hour *40 +1.5*this->pay_per_hour*(hours-40);
	} 
	else
	{
		salary=this->pay_per_hour *hours;
	} 
	cout<<"week_salary��"<<salary<<endl;
	
}

//�����н����������
class SalariedWorker:public Worker
{
	public:
		 void Compute_pay(double hours) const;                      //��н������н�����Ա����
		
};
//ʵ�ּ�н������н����
void SalariedWorker::Compute_pay(double hours) const
{
	double salary=0;
	if( hours >=35) 
	{
		salary = this->pay_per_hour*40;
	}
	else
	{
		salary = this->pay_per_hour*hours+ 0.5*this->pay_per_hour*(35-hours);
	}
	cout<<"week_salary��"<<salary<<endl;
}
//��ʾ����������� ����
Worker* WOrker(int type);
void display(Worker *worker[],int count); 
int main() 
{
	int choice; 
	int hours=0;
	                                                                  //ʵ���������͵����ֵȼ����ˣ�1��ʾ��ʱ���ˣ�2��ʾ��н����
	Worker *worker[5];
	worker[0]=WOrker(1);
	worker[1]=WOrker(1);
	worker[2]=WOrker(1);
	worker[3]=WOrker(2);
	worker[4]=WOrker(2);

	display(worker,5);                                                //������ʾ������Ϣ����
	cout<<"�����Ų�ѯ�������:"<<endl;
	cin>>choice;
	if(choice!=0)
	{
		cout<<(&cout,*worker[choice-1]);
		cout<<"���빤��ʵ�ʹ���Сʱ��:"; 
		cin>>hours;
		worker[choice-1]->Compute_pay(hours);
		
	
		display(worker,5);
		cout<<"�����Ų�ѯ��һ�����˻�����Ϣ:"<<endl;
	    cin>>choice;
	}
	for(int i = 0 ;i < 5;i++) 
	{ 
	    delete(worker[i]);                                              //�ͷſռ�
    } 
	
	return 0;
}
//��ʾ����������� 
void display(Worker *worker[],int count) 
{
	for(int i = 0 ;i < count;i++) 
	{ 
		cout<<i+1<<":";
	   worker[i]->Name();
	   cout<<endl;
    } 
}
Worker* WOrker(int type)
{
	string name;
	int age;
	string sex;
	double pay_per_hour=0;
	Worker*	worker=NULL;                                             //��ʼ��
	if( type == 1){
		cout<<"Input a Hourly Worker:"<<endl;
		worker=new HourlyWorker();                                  //����ʱ���˷���ռ�
	} else{
		cout<<"Input a Salary Worker:"<<endl;
		worker=new SalariedWorker();                                //����н���˷���ռ�  
	}
	//�Ӽ������빤�˻�����Ϣ
	cout<<"Input name:";
	cin>>name;
	worker->getName(name);
	cout<<"Input age:";
	cin>>age;
	worker->getAge(age);
	cout<<"Input sex:";
	cin>>sex;
	worker->getSex(sex);
	if( type == 1)
	{
	   cout<<"Input the salary level10 or 20 or 40"<<endl;
	}
	if(type==2)
	{
	   cout<<"Input the salary level 30 or 50"<<endl;
	}
	   
	cin>>pay_per_hour;
	worker->getPay(pay_per_hour);
	return worker;
}

