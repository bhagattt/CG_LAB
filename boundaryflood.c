#include<stdio.h> 
#include<graphics.h> 
#include<conio.h> 
#include<dos.h> 
void boundaryFill4(int x, int y, int fillColor, int bColor){     
if(getpixel(x,y)!=bColor && getpixel(x,y)!=fillColor){      
delay(5);                                               
putpixel(x, y, fillColor);                              
boundaryFill4(x+1, y, fillColor, bColor);               
boundaryFill4(x, y+1, fillColor, bColor); 
boundaryFill4(x-1, y, fillColor, bColor);                
boundaryFill4(x, y-1, fillColor, bColor); 
} 
} 
void floodFill4(int x, int y, int newColor, int oldColor){ 
if(getpixel(x,y) == oldColor){ 
delay(5); 
putpixel(x, y, newColor); 
floodFill4(x+1, y, newColor, oldColor); 
floodFill4(x, y+1, newColor, oldColor); 
floodFill4(x-1, y, newColor, oldColor); 
floodFill4(x, y-1, newColor, oldColor); 
} 
} 
int main() 
{ 
int choice,cochoice; 
int gDriver=DETECT, gMode, xc, yc, radius; 
initgraph(&gDriver, &gMode, "c:\\turboc3\\bgi");
printf("Enter the choice of Fill Algorithm : \n"); 
printf("1.Boundary Fill \n2.Flood Fill \n"); 
scanf("%d",&choice); 
printf("Enter the choice of color : \n"); 
printf("1.Red \n2.Green \n3.Blue\n"); 
    scanf("%d",&cochoice); 
    switch(choice) 
    { 
        case 1 :      
            switch(cochoice) 
            { 
                case 1 :  
                    printf("\n\nFirst Square filled by 4 connected approach"); 
                    rectangle(100, 150, 150, 200); 
                    boundaryFill4(125, 175, 4, 15); 
                    break; 
                case 2 :  
                    printf("\n\nFirst Square filled by 4 connected approach"); 
                    rectangle(100, 150, 150, 200); 
                    boundaryFill4(125, 175, 2, 15); 
                    break; 
                case 3 :  
                    printf("\n\nFirst Square filled by 4 connected approach"); 
                    rectangle(100, 150, 150, 200); 
                    boundaryFill4(125, 175, 1, 15); 
                    break; 
            } 
            break; 
        case 2 :  
                    switch(cochoice) 
            { 
                case 1 :  
                        printf("\nFlood Fill Algorithm"); 
                        printf("\n\nFirst Square filled by 4 connected approach"); 
                        rectangle(150, 250, 200, 300); 
                        floodFill4(175, 275, 4, 0); 
                        break;  
                case 2 :  
                        printf("\nFlood Fill Algorithm"); 
                        printf("\n\nFirst Square filled by 4 connected approach"); 
                        rectangle(150, 250, 200, 300); 
                        floodFill4(175, 275, 2, 0); 
                        break;  
                case 3 :  
                        printf("\nFlood Fill Algorithm"); 
                        printf("\n\nFirst Square filled by 4 connected approach"); 
                        rectangle(150, 250, 200, 300); 
                        floodFill4(175, 275, 7, 0); 
			break; 
} 
break; 
} 
delay(5000); 
closegraph(); 
return 0; 
}