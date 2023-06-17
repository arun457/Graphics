#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x1, y1, x2, y2;
	float x, y, m, pk, pk1, dx, dy;

	printf("Enter the Cords: ");
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

	x = x1;
	y = y1;

	cleardevice();
	dy = float(y2 - y1);
	dx = float(x2 - x1);

	m = dy / dx;

	if (m < 1)
	{
		pk = 2 * dy - dx;
	}
	else
	{
		pk = 2 * dx - dy;
	}

	while (x <= x2)
	{
		if (m < 1)
		{
			x = x + 1;
			if (pk < 0)
			{
				pk = pk + 2 * dy;
			}
			else
			{
				y = y + 1;
				pk = pk + 2 * dy - 2 * dx;
			}
		}
		else
		{
			y = y + 1;
			if (pk < 0)
			{
				pk = pk + 2 * dx;
			}
			else
			{
				x = x + 1;
				pk = pk + 2 * dx - 2 * dy;
			}
		}

		putpixel(x, y, WHITE);
	}

	getch();
	closegraph();
}
