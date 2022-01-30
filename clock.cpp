#include "fstrl.h"
#include<iostream>
#include<cstring>
#include<ctime>
#include<cmath>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define Minutes 8
#define Seconds 10
#define Hours 6
#define PI 3.14159265
/*class Time
{

}*/
void toPoints(struct tm* timeinfo, time_t rawtime, int **hr_min_sec);
int main()
{
	int center[2]={10, 10};
	time_t rawtime;
	struct tm *timeinfo;
	char c='n';
	int **hr_min_sec=new int*[3];
	for(int i=0; i<3; i++)
	{
		hr_min_sec[i]= new int[2];
	}
	Grid *G=new Grid;
	Line *S=new Line;
	Line *M=new Line;
	Line *H=new Line;
	S->setGrid(G);
	M->setGrid(G);
	H->setGrid(G);
	while(true)
	{
		toPoints(timeinfo, rawtime, hr_min_sec);
		H->setpoints(center[0], center[1], hr_min_sec[0][1], hr_min_sec[0][0]);
		M->setpoints(center[0], center[1], hr_min_sec[1][1], hr_min_sec[1][0]);
		S->setpoints(center[0], center[1], hr_min_sec[2][1], hr_min_sec[2][0]);
		H->draw();
		M->draw();
		S->draw();
		G->print();
		G->restore();
		sleep(1);
		std::cout<<"finished";
	}
	for(int i=0; i<3; i++)
	{
		delete[] hr_min_sec[i];
	}
	delete[] hr_min_sec;
	delete G;
	delete H, M, S;
  return 0;
}
void toPoints(struct tm* timeinfo, time_t rawtime, int **hr_min_sec)
{
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	int hr;
	if(timeinfo->tm_hour<12) hr=timeinfo->tm_hour;
	else hr=timeinfo->tm_hour-12;
	std::cout<<"\nhr: "<<hr<<", min: "<<timeinfo->tm_min<<", sec: "<<timeinfo->tm_sec;
	hr_min_sec[0][0]=10-round((Hours*cos((((double)timeinfo->tm_hour)/12)*2*PI)));
	hr_min_sec[0][1]=10+round((Hours*sin((((double)timeinfo->tm_hour)/12)*2*PI)));
	hr_min_sec[1][0]=10-round((Minutes*cos((((double)timeinfo->tm_min)/60)*2*PI)));
	hr_min_sec[1][1]=10+round((Minutes*sin((((double)timeinfo->tm_min)/60)*2*PI)));
	hr_min_sec[2][0]=10-round((Seconds*cos((((double)timeinfo->tm_sec)/60)*2*PI)));
	hr_min_sec[2][1]=10+round((Seconds*sin((((double)timeinfo->tm_sec)/60)*2*PI)));
	std::cout<<std::endl;
	for(int k=0; k<3; k++)
	{
		for(int p=0; p<2; p++) std::cout<<hr_min_sec[k][p]<<", ";
	}
	std::cout<<std::endl;
}

