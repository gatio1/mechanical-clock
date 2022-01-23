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
#define Minutes 9
#define Seconds 10
#define Hours 6
#define PI 3.14159265
/*class Time
{

}*/
void toPoints(strict tm* timeinfo, time_t rawtime, int **hr_min_sec)
{
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	hr_min_sec[0][0]=10+(int)(Hours*sin((24/(double)timeinfo->tm_hour)*2*PI));
	hr_min_sec[0][1]=10-(int)(Hours*cos((24/timeinfo->tm_hour)*2*PI));
	hr_min_sec[1][0]=10+(int)(Minutes*sin((60/timeinfo->tm_min)*2*PI));
	hr_min_sec[1][1]=10-(int)(Minutes*cos((60/timeinfo->tm_min)*2*PI));
	hr_min_sec[2][0]=10+(int)(Seconds*sin((60/timeinfo->tm_sec)*2*PI));
	hr_min_sec[2][1]=10-(int)(Seconds*cos((60/timeinfo->tm_sec)*2*PI));
}
int main()
{
	int center[2]={10, 10};
	time_t rawtime;
	struct *tm timeinfo;
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
		sleep(1000);
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

