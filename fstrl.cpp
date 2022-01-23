#include<cmath>
#include<iostream>
#include "fstrl.h"
using namespace std;
Grid::Grid()
	{
		restore();
	}
	void Grid::change(int h,int v)
	{
		vh[v][h]=true;
	}
	void Grid::restore()
	{
		for(int v=0;v<21;v++)
		{
			for(int h=0;h<21;h++)
			{
				vh[v][h]=false;
			}
		}

	}
	void Grid::print()
	{
		cout<<endl;
		for(int v=0;v<21;v++)
		{
			if(v<10)cout<<" |";
			else cout<<" |";
			for(int h=0;h<21;h++)
			{
				if(vh[v][h]==false)cout<<"  ";
				else cout<<"$$";
			}
			cout<<endl;
		}
	}
	void Line::setpoints(int v1,int h1,int v2,int h2)
	{
		vertical=0;
		this->h1=h1;
		this->v1=v1;
		this->h2=h2;
		this->v2=v2;
		tanangle();
	}
	void Line::setGrid(Grid *G)
	{
		this->G=G;
	}
	void Line::tanangle()
	{
		int ab;
		int ca;
		ab=v1-v2;
		ca=h1-h2;
		if((ca<1&&ca>=0)||(ca>-1&&ca<0)) vertical=1; 
		else tanang=ab/ca;
		cout<<endl<<"ca, ab:"<<ca<<", "<<ab<<"/t"<<"tan:"<<tanang<<endl;
	}
	void Line::draw()
	{
		int sign=1;
		if(h1>h2) sign=-1;
		if(vertical==1)
		{
			for(int i=0; i+v1<=v2; i+=sign)
				G->change((int)round(v1+i), (int)round(h1));
		}
		else
		{
			for(int i=0; i+h1<=h2; i+=sign)
			{
				G->change((int)round(v1+i*tanang), (int)round(h1+i));
			}
		}
	}

