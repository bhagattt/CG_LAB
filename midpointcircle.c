#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<graphics.h>

void drawCircle(int xc,int yc,int r){
int x = 0;
int y = r;
int d = 1-r;
while(x<y){
putpixel(xc+x,yc+y,7);
putpixel(xc+y,yc+x,7);
putpixel(xc-x,yc+y,7);
putpixel(xc-y,yc+x,7);
putpixel(xc+x,yc-y,7);
putpixel(xc+y,yc-x,7);
putpixel(xc-x,yc-y,7);
putpixel(xc-y,yc-x,7);
if(d<0){
x = x+1;
d = d + 2*x +1;
}
else{
x =x+1;
y=y-1;
d = d +2*x -2*y +1;
}

}

}

void main(){
int gd = DETECT,gm,x,y,r;
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
printf("Enter the center coordinates of circle\n");
scanf("%d%d",&x,&y);
printf("Radius\n");
scanf("%d",&r);
drawCircle(x,y,r);
getch();
closegraph();
}
// 100 100 /50