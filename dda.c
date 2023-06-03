#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x1 = 0, y1 = 0, x2 = 100, y2 = 100;
	float x = x1, y = y1, m;

	m = (y2 - y1) / float(x2 - x1);

	while (x <= x2)
	{
		if (m <= 1)
		{
			x = x + 1;
			y = y + m;
		}
		else
		{
			y = y + 1;
			x = x + 1 / m;
		}
		putpixel(int(x + 0.5), int(y + 0.5), WHITE);
	}

	getch();
	closegraph();
}