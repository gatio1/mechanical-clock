#if _MATH_H
#include<cmath>
#endif
#if _IOSTREAM
#include<iostream>
#endif
using namespace std;
class Grid
{
	bool vh[100][100];
	public:
	Grid()
	{
		for(int v=0;v<100;v++)
		{
			for(int h=0;h<100;h++)
			{
				vh[v][h]=false;
			}
		}
	}
	void change(int h,int v)
	{
		vh[v][h]=true;
	}
	void print()
	{
		cout<<"  ";
		for(int i=0;i<100;i++)
		{
			if(i<10)cout<<" "<<i;
			else cout<<i;
		}
		cout<<endl;
		for(int v=0;v<100;v++)
		{
			if(v<10)cout<<" "<<v;
			else cout<<v;
			for(int h=0;h<100;h++)
			{
				if(vh[v][h]==false)cout<<"| ";
				else cout<<"$$";
			}
			cout<<endl;
		}
	}
	//file operations
};
class Line
{
	Grid *G;
	double v1;
	double h1;
	double v2;
	double h2;
	double tanang;
	int vertical=0;
	public:
	void setpoints(int v1,int h1,int v2,int h2)
	{
		vertical=0;
		this->h1=h1;
		this->v1=v1;
		this->h2=h2;
		this->v2=v2;
		tanangle();
	}
	void setGrid(Grid *G)
	{
		this->G=G;
	}
	void tanangle()
	{
		int ab;
		int ca;
		ab=v1-v2;
		ca=h1-h2;
		if((ca<1&&ca>=0)||(ca>-1&&ca<0)) vertical=1; 
		else tanang=ab/ca;
		cout<<endl<<"ca, ab:"<<ca<<", "<<ab<<"/t"<<"tan:"<<tanang<<endl;
	}
	void draw()
	{
		int sign=1;
		if(h1>h2) sign=-1;
		if(vertical==1)
		{
			for(int i=0; i+v1<v2; i+=sign)
				G->change((int)round(v1+i), (int)round(h1));
		}
		else
		{
			for(int i=0; i+h1<h2; i+=sign)
			{
				G->change((int)round(v1+i*tanang), (int)round(h1+i));
			}
		}
	}
};

