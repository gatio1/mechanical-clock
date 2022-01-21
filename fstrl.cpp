#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
#define PI 3.14159265
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
	void fprint()
	{
		ofstream fp;
		fp.open("strlsave.txt",ios::out);
		for(int v=0;v<100;v++)
		{
			for(int h=0;h<100;h++)
			{
				if(vh[v][h]==false)fp<<0;
				else fp<<1;
				fp<<"\t";
			}
			fp<<"\n";
		}
		fp.close();
	}
	void fget()
	{
		ifstream pf;
		pf.open("strlsave.txt",ios::in);
		bool o;
		for(int v=0;v<100;v++)
		{
			for(int h=0;h<100;h++)
			{
				pf>>o;
				if(o==true) vh[v][h]=true;
			}
		}
		pf.close();
	}
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
int main()
{
	char c;
	cout<<"l to load";
	cin>>c;
	Grid *G1=new Grid;
	if (c=='l') G1->fget();
	cout<<endl;
	Line *Lines=new Line;
	do{
		G1->print();
		int va,ha,vb,hb=0;
		cout<<"point a x=";
		cin>>va;
		cout<<"point a y=";
		cin>>ha;
		cout<<"point b x=";
		cin>>vb;
		cout<<"point b y=";
		cin>>hb;
		Lines->setpoints(va, ha, vb, hb);
		Lines->setGrid(G1);
		Lines->draw();
		G1->print();
		cout<<"press any key but q(quit) or s(save and continue) to continue:";
		cin>>c;
		if(c=='s') G1->fprint();
	}while(c!='q');
	return 0;
}
