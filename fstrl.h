#ifndef _FSTRL_H
#define _FSTRL_H
class Grid
{
	bool vh[21][21];
	public:
	Grid();
	void change(int h,int v);
	void print();
	void restore();
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
	void setpoints(int v1,int h1,int v2,int h2);
	void setGrid(Grid *G);
	void tanangle();
	void draw();

};
#endif
