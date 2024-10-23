#include<stdio.h>
#include<math.h>
#include<graphics.h>
#define SIN(x) sin(3.141592653589793*x/180)
#define COS(x) cos(3.141592653589793*x/180)
void translate(int x[], int y[], int tx, int ty, int n) 
{
int i;
for(i=0; i<n; i++)
{
x[i] += tx;
y[i] += ty;
}
}
void rotate(int x[], int y[], double angle, int n)
{
int i, X, Y;
for(i=0; i<n; i++)
 X = x[i], Y= y[i];
x[i]= X*COS(angle)- Y*SIN(angle);
y[i]= X*SIN(angle)+ Y*COS(angle);
}
void scale(int x[], int y[], float sx, float sy, int n)
{
int i;
for(i=0; i<n; i++)
x[i]*=sx;
y[i]*=sy;
}
void reflect(int x[], int y[], int axis, int n)
{
int i;
for(i=0; i<n; i++)
{
if(axis==0)
y[i]*=-1;
else
x[i]*=-1;
}
}
void shear(int x[], int y[], float shx, float shy, int n)
{
int i, X, Y; 
for(i=0; i<n; i++)
X= x[i], Y=y[i];
x[i]+=shx*Y;
y[i]+=shy*X;
}
int main()
{
int i, n ,xc, yc, gd=DETECT, gm, choice, tx, ty, angle, axis, x[100], y[100], input[200];
float sx, sy, shx, shy;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
xc = getmaxx()/2;
yc = getmaxy()/2;
printf("\n2D TRANSFORMATIONS\n\nEnter no.of vertices of the polygon:");
scanf("%d", &n);
for(i=0; i<n; i++)
{
printf("Enter x%d y%d:", i+1, i+1);
scanf("%d%d", &x[i], &y[i]);
input[2*i] = xc + x[i];
input[2*i+1] = yc-y[i];
}
input[2*n] = input[0]; input[2*n+1] = input[1];
line(0, yc, getmaxx(), yc);
line(xc, 0, xc, getmaxy());
drawpoly(n+1, input);
printf("Choose an option:\n1.Translate\n2.Rotate\n3.Scale\n4.Reflect\n5.Shear\n\nYour choice:");
scanf("%d", &choice); switch(choice)
{
case 1:
printf("Enter the translation units:\n");
scanf("%d%d", &tx, &ty);
translate(x, y, tx, ty, n);
break;
case 2:
printf("Enter angle:");
scanf("%d", &angle);
rotate(x, y, angle, n);
break;
case 3:
printf("Enter scaling factors:");
scanf("%f%f", &sx, &sy);
scale(x, y, sx, sy, n);
break;
case 4:
printf("Enter 0 to reflect about x-axis and 1 to reflect about y-axis:");
scanf("%d", &axis);
reflect(x, y, axis, n);
break;
case 5:
printf("Enter shearing factors:");
scanf("%f%f", &shx, &shy);
shear(x, y, shx, shy, n);
break;
default:
printf("Invalid choice\n");
}
for(i=0; i<n; i++)
{
input[2*i] = xc+x[i];
input[2*i+1] = yc-y[i];
input[2*n] = input[0];
input[2*n+1] = input[1];
}
drawpoly(n+1, input);
getch();
return 0;
} 
// 10 60
//  10 60 
//  60 60 
//  60 10
