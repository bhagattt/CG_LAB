#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>

void main() {
    float x, y, x1, y1, x2, y2, dx, dy;
    int i, gd = DETECT, gm, step;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

    // Take input from user for two points
    printf("Enter the values of x1 and y1:\n");
    scanf("%f %f", &x1, &y1);
    printf("Enter the values of x2 and y2:\n");
    scanf("%f %f", &x2, &y2);

    // Calculate dx and dy
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    // Determine the number of steps to take
    if (dx >= dy) {
        step = dx;
    } else {
        step = dy;
    }

    // Normalize dx and dy to step
    dx = (x2 - x1) / step;
    dy = (y2 - y1) / step;

    // Initialize starting point
    x = x1;
    y = y1;

    // Draw the line by putting pixels
    for (i = 1; i <= step; i++) {
        putpixel(x, y, YELLOW);  // Draw the pixel
        x = x + dx;              // Increment x
        y = y + dy;              // Increment y
        delay(150);              // Add a delay for animation effect
    }

    // Wait for a key press and close the graphics window
    getch();
    closegraph();
    // input 100 200 300 100
}