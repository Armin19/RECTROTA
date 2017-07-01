#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<dos.h>

double angle=0;
double rectpoints[4][2]={ {-100,-100},
			  {100,-100},
			  {100,100},
			  {-100,100}};

double rectlines[4][2]={{0,1},{0,3},{1,2},{2,3}};
const double PI=3.141592;
void rotate(double x,double y,double &rx,double &ry){
	double rad=angle/180*PI;
	rx=x*cos(rad)-y*sin(rad);
	ry=x*sin(rad)+y*cos(rad);
	}
void drawrect(){
	cleardevice();
	for(int i=0;i<4;i++){
	double x1=rectpoints[rectlines[i][0]][0];
	double y1=rectpoints[rectlines[i][0]][1];
	double x2=rectpoints[rectlines[i][1]][0];
	double y2=rectpoints[rectlines[i][1]][1];
	double rx1,ry1,rx2,ry2;
	rotate(x1,y1,rx1,ry1);
	rotate(x2,y2,rx2,ry2);
	line(rx1+getmaxx()/2,ry1+getmaxy()/2,rx2+getmaxx()/2,ry2+getmaxy()/2);
	}
	}
int main(){
	int Device=DETECT;
	int Mode=DETECT;
	initgraph(&Device,&Mode,"C:\\TURBOC3\\BGI");
	cleardevice();
	while(1){
	/*double rad=angle/180*PI;
	cleardevice();
	double rx=x*cos(rad)-y*sin(rad);
	double ry=x*sin(rad)+y*cos(rad);
	line(0,0,(int)rx,(int)ry);*/
	drawrect();
	if(kbhit())return -1;
	delay(200);
	angle++;
	}

getch();
closegraph();
return 0;
}