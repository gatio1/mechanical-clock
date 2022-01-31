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
void Clear()// A function to clear everything printed so far on the screen
{
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
    system("clear");
#endif
}

void toPoints(struct tm* timeinfo, time_t rawtime, int **hr_min_sec);
int main()
{
	int center[2]={10, 10};
	time_t rawtime;
	struct tm *timeinfo;
	int a=0;
	time_t start_time;
	int time_duration;
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
	std::cout<<"How long do you want it to run?(seconds)"<<std::endl;
	std::cin>>time_duration;
	time(&start_time);
	time(&rawtime);
	while((int)difftime(rawtime, start_time)<time_duration)
	{
		Clear();
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
		time(&rawtime);
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
	hr_min_sec[0][0]=10-round((Hours*cos(((((double)hr)/12)+((((double)timeinfo->tm_min)/60)/12))*2*PI)));
	hr_min_sec[0][1]=10+round((Hours*sin(((((double)hr)/12)+((((double)timeinfo->tm_min)/60)/12))*2*PI)));
	hr_min_sec[1][0]=10-round((Minutes*cos((((double)timeinfo->tm_min)/60)*2*PI)));
	hr_min_sec[1][1]=10+round((Minutes*sin((((double)timeinfo->tm_min)/60)*2*PI)));
	hr_min_sec[2][0]=10-round((Seconds*cos((((double)timeinfo->tm_sec)/60)*2*PI)));
	hr_min_sec[2][1]=10+round((Seconds*sin((((double)timeinfo->tm_sec)/60)*2*PI)));
}

