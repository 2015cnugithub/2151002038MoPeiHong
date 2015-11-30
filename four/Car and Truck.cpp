
#include<iostream>
#include <graphics.h>    
#include <conio.h>
#include<windows.h>
#include <math.h>
#include"dos.h"
using namespace std;
class Figure//����ͼ�λ���
{
public:
	virtual void Move()=0;
	virtual void hide()=0;//��������ͼ��
	virtual void draw()=0;//���ڻ滭ͼ��
};
 //struct Figurelink;
typedef struct Figurelink//��ͼ�ε�����
{
	Figure *q;
	Figurelink  * next;
};
class Circle:public Figure
{
protected:
	int x;                                     //Բ��x������
	int y;                                     //Բ��y������
	int radius;                                //Բ�İ뾶��
public:
	Circle(int X,int Y,int Radius)
	{
		x=X;
		y=Y;
		radius=Radius;
	}
	void Move()                                  //�������1
	{
		x=x+1;
	}
    void hide()                         
	{
	     setcolor(BLACK);                        //���õ�ǰ����ͼƬ��ɫ
	     circle(x,y,radius);
	}
	void draw()
	{
         setcolor(WHITE);              
	     circle(x,y,radius);
	}
};
class Rectangl:public Figure
{
protected:
	int left,right,top,bottom;
 public:
     Rectangl(int Left,int Top,int Right,int Bottom)//���캯��
	 {
		 left=Left;
		 top=Top;
		 right=Right;
		 bottom=Bottom;
	 }
	 void Move()
	{
		 left=left+1;
		 right=right+1;
	}
     void hide()
	 {
		setcolor(BLACK);
	    rectangle(left,top,right,bottom);
	 }
	 void draw()
	 {
       	setcolor(WHITE);
		rectangle(left,top,right,bottom);
	 }
};
class Triangle:public Figure
{
int x[6];
public:
	Triangle(int x1,int y1,int x2,int y2,int x3,int y3)  //���캯��
	{
	x[0]=x1;
	x[1]=y1;
	x[2]=x2;
	x[3]=y2;
	x[4]=x3;
	x[5]=y3;
	}
	 void Move()                                        //ǰ��
	 {
		 x[0]=x[0]+1;
		 x[2]=x[2]+1;
		 x[4]=x[4]+1;
	 }
     void hide()
	 {
       setcolor(BLACK);
	   polygon((POINT*)x, 3);                           //��������
	 }
	 void draw()
	 {
	   setcolor(WHITE);
	   polygon((POINT*)x, 3);
	 }
};
class Vehicle
{
	private:
	Figurelink *contents;
	int wheel_size,xstart,ystart;
	public:
	Vehicle(int x_start, int y_start, int Wheel_size)
	{
	 contents=new Figurelink; 
	 xstart=x_start;
	 ystart=y_start;
	 wheel_size=Wheel_size;
	}
	void set_size()//����С��������ͼ������
	{
		 Figure *p;
		 Figurelink *a,*b,*c,*d,*e,*f;
		 a=new Figurelink;
		 b=new Figurelink;
		 c=new Figurelink;
		 d=new Figurelink;
		 e=new Figurelink;
		 f=new Figurelink;
		 p=new Rectangl(xstart, ystart-2*wheel_size,xstart+8*wheel_size,ystart-wheel_size); 
		 a->q=p;
		 p=new Rectangl(xstart+2.25*wheel_size, ystart-3*wheel_size,xstart+5.75*wheel_size,ystart-wheel_size*2);
		 b->q=p;
		 p=new Circle(xstart+1.75*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 c->q=p;
		 p=new Circle(xstart+6.25*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 d->q =p;
		 p=new Triangle(xstart+1.25*wheel_size,ystart-2*wheel_size,xstart+2.25*wheel_size,ystart-2*wheel_size,xstart+2.25*wheel_size,ystart-3*wheel_size);
		 e->q=p;
		 p=new Triangle(xstart+5.75*wheel_size,ystart-2*wheel_size,xstart+5.75*wheel_size,ystart-3*wheel_size,xstart+6.75*wheel_size,ystart-2*wheel_size);
		 f->q=p;
		 contents->next=a;
		 a->next=b;
		 b->next=c;
		 c->next=d;
		 d->next=e;
		 e->next=f;
		 f->next=NULL;    
	}
	 void set_truck()//������������ͼ������
	 {
		 Figure *p;
		 Figurelink *a,*b,*c,*d,*e,*f,*g;
		 a=new Figurelink;
		 b=new Figurelink;
		 c=new Figurelink;
		 d=new Figurelink;
		 e=new Figurelink;
		 f=new Figurelink;
         g=new Figurelink;
		 p=new Rectangl(xstart, ystart-5*wheel_size,xstart+9*wheel_size,ystart-wheel_size); 
		 a->q=p;
		 p=new Rectangl(xstart+9*wheel_size, ystart-4*wheel_size,xstart+11*wheel_size,ystart-wheel_size);
		 b->q=p;
		 p=new Circle(xstart+wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 c->q=p;
		 p=new Circle(xstart+2.25*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 d->q =p;
		 p=new Circle(xstart+6.75*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 e->q=p;
		 p=new Circle(xstart+8*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 f->q=p;
         p=new Circle(xstart+10*wheel_size,ystart-0.5*wheel_size,0.5*wheel_size);
		 g->q=p;
		 contents->next=a;
		 a->next=b;
		 b->next=c;
		 c->next=d;
		 d->next=e;
		 e->next=f;
		 f->next=g;
		 g->next=NULL;  
	 }
	 void Delete()//ɾ��С�����򿨳�����ͼ���б�
	 {
        Figurelink *C,*T;
		C=contents->next;
		while(C!=NULL)
		{
			T=C;
			C=C->next;
			delete T;
			
		}
	 }

	void Draw()//��С�����򿨳�����ͼ���б�
	{
		Figurelink *C;
		C=contents->next;
		while(C!=NULL)
		{
			C->q->draw();
			C=C->next;
		}
	}
	void Hide()//����С�����򿨳�����ͼ���б�
	{
		Figurelink *C;
		C=contents->next;
		while(C!=NULL)
		{
			C->q->hide();
			C->q->Move();
			C=C->next;
		}
	}
};

class Car:public Vehicle
{
  public:
	  Car(int wheel_size, int xstart, int ystart):Vehicle(wheel_size,xstart,ystart){}
};

class Truck:public Vehicle
{
public:
	  Truck(int wheel_size, int xstart, int ystart):Vehicle(wheel_size,xstart,ystart){}
};

int main()
{
	int m=0;
	int i=0;
	char c;
	double x[8]={40,28,23,20,12,8,6,5};
	int t=3;

	//�����˵�
	initgraph(800, 480);
	RECT r1 = {0, 0,250, 30};
	drawtext(_T( "1.CAR 2.TRUCK 0.EXIT\t"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE); // ����easyx��ָ����������ָ����ʽ����ַ���
	RECT r2 = {0, 0, 250, 60};
	drawtext(_T( "Press <S> key to start moving\t"), &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
    RECT r3 = {0, 0, 250, 90};
	drawtext(_T( "Press <P> key to pause\t "), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4 = {0, 0, 250, 120};
	drawtext(_T( "Press <E> key to end moving \t"), &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5 = {0, 0, 250,150};
	drawtext(_T( "Press <+> key to speed up\t"), &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r6 = {0, 0,250, 180};
	drawtext(_T( "Press <-> key to speed down\t"), &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	

    //�����ʼ��
	Car car_car(10,400,20);
	Truck truck_truck(10,400,20);

	//����С�����Ϳ�������
	car_car.set_size();
	truck_truck.set_truck();


 while(1)
 {
	   if(kbhit())//�ж��Ƿ��а�������
	   {
			  c=getch();
			  if(c=='1') //������
			  {
				  truck_truck.Hide();car_car.Draw();m=1;
			  }
			  else if(c=='2')//������
			  {
				  car_car.Hide();truck_truck.Draw();m=2;
			  }
			  while(1)
			  {
					  if(kbhit())
					  {
						  c=getch();
						  if(c=='s')//��ʼ��ʻ
						  {		 
								while((c!='e')&&(c!='0'))//��ʻ������
								{
						  			  if(i==0)
									  {
										  if(m==1){car_car.Hide();car_car.Draw();}
										  if(m==2){truck_truck.Hide();truck_truck.Draw();}
										  Sleep(x[t]);
									  }
									   if(kbhit())
									   {
										 c=getch();
										 if((c=='=')&&(t<=7)) t=t+1;//����
										 if((c=='-')&&(t>=0)) t=t-1;//����
										 if((c=='p')&&(i==0)) i=1;//��ͣ
										 else if((c=='p')&&(i==1)) i=0;//����
									   }
									    if(c=='e')//ֹͣ�˻ص���ʼ״̬
										{
											 t=3;
											 if(m==1) {car_car.Hide();car_car.Delete();car_car.set_size();car_car.Draw();}//ɾ����Ȼ�����¹�������
											 if(m==2) {truck_truck.Hide();truck_truck.Delete();truck_truck.set_truck();truck_truck.Draw();}//ɾ����Ȼ�����¹�������
										}
									
								}
						  }
					  }
					  if(c=='e'||c=='0') break;
							
			  }
	   }
	 //   if(c=='0') break;//��������
	   
 }
	//ɾ������ͼ������
    car_car.Delete();
	truck_truck.Delete();
    closegraph();          // �ر�ͼ�ν���
	return 0;
}


