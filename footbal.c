#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <stdlib.h>

int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int centerX = getmaxx() / 2;
	int centerY = getmaxy() / 2;
	int radiusX = 100;
	int radiusY = 150;

	ellipse(centerX, centerY, 0, 360, radiusX, radiusY);
	floodfill(centerX, centerY, WHITE);

	setcolor(WHITE);
	circle(centerX, centerY, radiusX);
	circle(centerX, centerY, radiusY);

	setcolor(BLACK);
	int i;
	for (i = 0; i <= 180; i += 10)
	{
		int x = centerX + radiusX * cos(i * 3.14159 / 180);
		int y = centerY + radiusY * sin(i * 3.14159 / 180);
		line(centerX, centerY, x, y);
	}

	delay(5000);
	closegraph();
	return 0;
}
