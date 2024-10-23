#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int dx,dy,p,x,y,x0,y0,x1,y1;
void drawLine(int x0,int y0,int x1,int y1){
x=x0;
y=y0;
dx = x1-x0;
dy = y1-y0;
p = 2*dy - dx;
while(x<x1){
if(p>=0){
putpixel(x,y,7);
 y = y+1;
p=p+2*dy-2*dx;
}
else{
putpixel(x,y,7);
 p = p + 2*dy;
}
x = x+1;
}
}
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
printf("Enter x1 & y1\n");
scanf("%d%d",&x0,&y0);
printf("Enter x2 & y2\n");
scanf("%d%d",&x1,&y1);
drawLine(x0,y0,x1,y1);
getch();
closegraph();
}
//input 100 200 
// 300 400
