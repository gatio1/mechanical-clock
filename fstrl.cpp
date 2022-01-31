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
			if(v<10)cout<<" [";
			else cout<<" |";
			for(int h=0;h<21;h++)
			{
				if(v==h&&h==10)printf("\x1B[31m$$\033[0m");
				else{
					if(vh[v][h]==false)cout<<"  ";
					else cout<<"$$";
				}
			}
			cout<<endl;
		}
	}
	void Line::setpoints(int v1,int h1,int v2,int h2)
	{
		vertical=0;
		horizontal=0;
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
		if((ca<1)&&(ca>-1)) horizontal=1;
	     	if((ab<1)&&(ab>-1)) vertical=1; 	
		else tanang=(double)ab/(double)ca;
	}
	void Line::draw()
	{
		int signh=1;
		int signv=1;
		int flag=0;
		if(h1>h2) signh=-1;
		if(v1>v2) signv=-1;
		if(vertical==1)
		{
			flag=1;
		}
		if(horizontal==1)
		{
			flag=2;
		}

		if(flag!=2)
		{
			for(int i=0; i+h1!=h2; i+=signh)
			{
				G->change(round(v1+i*tanang), round(h1+i));
			}
		}
		if(flag!=1)
		{
			for(int i=0; i+v1!=v2; i+=signv)
			{
				G->change(round(v1+i), round(h1+i/tanang));
			}
		}
	}


