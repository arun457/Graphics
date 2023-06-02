#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>

int border[640];
void draw_border()
{
	for (int i = 0; i < 640; i++)
	{
		putpixel(i, border[i], BLUE);
	}
}

void initiateborder()
{
	for (int i = 0; i < 640; i++)
	{
		border[i] = 479;
	}
}

void rect(int x, int y)
{
	rectangle(x - 20, y - 20, x + 20, y);
}

void movement(char ip, int *x, int *y)
{
	switch (ip)
	{
	case 'a':
		*x = *x - 40;
		break;
	case 'd':
		*x = *x + 40;
		break;
	case 's':
		*y = *y + 25;
		break;

	default:
		break;
	}
}

void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	initiateborder();

	int x = 20,
		y = 20;
	char ip;

	while (y < border[x] - 25)
	{
		cleardevice();
		draw_border();
		if (!kbhit())
		{
			y = y + 25;
			rect(x, y);
		}
		else
		{
			ip = getch();
			fflush(stdin);
			movement(ip, &x, &y);
			continue;
		}

		delay(100);
	}

	for (int i = x - 20; i < x + 20; i++)
	{
		border[i] = border[i] - y - 20;
	}

	printf("here");

	draw_border();
	printf("HEY");

	getch();
	closegraph();
}