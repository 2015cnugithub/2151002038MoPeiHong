//设计一个抽象基类Worker，并从该基类中派生出计时工人类HourlyWorker和计薪工人类SalariedWorker。每名工人都具有姓名name、年龄age、性别sex和小时工资额pay_per_hour等属性；周薪计算成员函数void Compute_pay(double hours)，
//（其中参数hours为每周的实际工作时数）和用于显示工人的基本信息的标准输出运算符友元函数ostream&operator<<(ostream&out, Worker&worker)。工人的薪金等级以小时工资额划分：
//计时工人的薪金等级分为10、20和40 US$/hour三个等级；计薪工人的薪金等级，分为30和50 US$/hour两个等级。不同类别和等级工人的周薪计算方法不同，计时工人周薪的计算方法是：
//如果每周的工作时数（hours）在40以内，则周薪 = 小时工资额×实际工作时数；如果每周的工作时数（hours）超过40，则周薪= 小时工资额× 40 + 1.5 ×小时工资额×（实际工作时数 – 40）。
//而计薪工周薪的计算方法是：如果每周的实际工作时数不少于35小时，则按40小时计周薪（允许有半个工作日的事/病假），超出40小时部分不计薪，即周薪= 小时工资额× 40；如果每周的实际工作时数少于35小时（不含35小时），则周薪= 小时工资额实际工作时数+ 0.5 ×小时工资额× (35 - 实际工作时数)。
//要求：
//1. 定义Worker、HourlyWorker和SalariedWorker类，并实现它们的不同周薪计算方法。2.在主函数main()中使用HourlyWorker和SalariedWorker类完成如下操作：
//①通过控制台输入、输出操作顺序完成对5个不同工人的基本信息（姓名、年龄、性别、类别和薪金等级）的注册。注意，5个工人应分属于两类工人的5个等级。
//②通过一个菜单结构实现在5个工人中可以任意选择一个工人，显示该工人的基本信息，根据每周的实际工作时数（通过控制台输入）计算并显示该工人的周薪。直至选择退出操作。
//提示：
//1.可以定义一个Worker类的指针数组Worker* workers[5];用于指向5个动态创建的HourlyWorker或SalariedWorker类对象。注意，程序结束前，应撤消这些动态创建的对象。
//2.可以为Worker类增加一个成员函数void Name();用于在菜单结构中显示每个工人的姓名作为用户选择的菜单项。

//运行环境vs2005
#include "stdafx.h"
#include<stdio.h>
#include<string>
#include <iostream>
using namespace std;

//定义Worker抽象类
class Worker
{
	protected:                                                               //定义保护类型成员数据
		string name;
		int age;
		string sex;
		double pay_per_hour;
	public: 
		virtual void Compute_pay(double hours)const= 0;                      //纯虚函数 
	    void Name();               
	    void getName(string name);                                           //设置工人姓名成员函数
	    void getAge(int age);                                                //设置工人年龄成员函数
	    void getSex(string sex);                                             //设置工人性别成员函数
	    void getPay(int pay_per_hour);                                       //设置工人时薪成员函数
		friend ostream& operator<<(ostream& out,Worker& worker);             //显示工人基本信息友元函数
};
//显示工人基本信息实现
ostream& operator<<(ostream& output,Worker& w)
{
	output<<"name:"<<w.name<<"age:"<<w.age<<"sex:"<<w.sex<<"pay_per_hour:"<<w.pay_per_hour<<endl; 
	return output;
}
//实现各成员函数
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

//定义计时工人派生类
class HourlyWorker:public Worker
{
	public:
		 void Compute_pay(double hours)const ;                         //用于实现计时工人周薪计算成员函数
};
//实现计时工人周薪函数
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
	cout<<"week_salary："<<salary<<endl;
	
}

//定义计薪工人派生类
class SalariedWorker:public Worker
{
	public:
		 void Compute_pay(double hours) const;                      //计薪工人周薪计算成员函数
		
};
//实现计薪工人周薪计算
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
	cout<<"week_salary："<<salary<<endl;
}
//显示五个工人名称 函数
Worker* WOrker(int type);
void display(Worker *worker[],int count); 
int main() 
{
	int choice; 
	int hours=0;
	                                                                  //实现两种类型的五种等级工人，1表示计时工人，2表示计薪工人
	Worker *worker[5];
	worker[0]=WOrker(1);
	worker[1]=WOrker(1);
	worker[2]=WOrker(1);
	worker[3]=WOrker(2);
	worker[4]=WOrker(2);

	display(worker,5);                                                //调用显示工人信息函数
	cout<<"输入编号查询工人情况:"<<endl;
	cin>>choice;
	if(choice!=0)
	{
		cout<<(&cout,*worker[choice-1]);
		cout<<"输入工人实际工作小时数:"; 
		cin>>hours;
		worker[choice-1]->Compute_pay(hours);
		
	
		display(worker,5);
		cout<<"输入编号查询下一个工人基本信息:"<<endl;
	    cin>>choice;
	}
	for(int i = 0 ;i < 5;i++) 
	{ 
	    delete(worker[i]);                                              //释放空间
    } 
	
	return 0;
}
//显示五个工人名字 
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
	Worker*	worker=NULL;                                             //初始化
	if( type == 1){
		cout<<"Input a Hourly Worker:"<<endl;
		worker=new HourlyWorker();                                  //给计时工人分配空间
	} else{
		cout<<"Input a Salary Worker:"<<endl;
		worker=new SalariedWorker();                                //给计薪工人分配空间  
	}
	//从键盘输入工人基本信息
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

