// head
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>

void explosion(int x, int y)
{
	circle(x, y, 5);
	delay(50);
	cleardevice();
	circle(x, y, 10);
	delay(50);
	cleardevice();
	circle(x, y, 15);
	delay(50);
	cleardevice();
	circle(x, y, 20);
	delay(50);
	cleardevice();
}

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x = 100, y = 100;
	explosion(x, y);
	getch();
	closegraph();
}
// tail