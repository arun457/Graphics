#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>

float nextX(float x, float m)
{
	if (m <= 1)
		return x + 1;
	else
		return x + 1 / m;
}

float nextY(float y, float m)
{
	if (m <= 1)
		return y + m;
	else
		return y + 1;
}

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x1 = 0, y1 = 0, x2 = 100, y2 = 100;
	float x = x1, y = y1, m;

	m = (y2 - y1) / float(x2 - x1);

	while (x <= x2)
	{
		putpixel(x, y, WHITE);
		x = nextX(x, m);
		y = nextY(y, m);
	}

	getch();
	closegraph();
}