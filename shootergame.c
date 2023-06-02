// head
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#define enemy_count 20

int killed[enemy_count + 1];
int nextkill = 0;

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

void GameOver()
{
	cleardevice();
	printf("Gameover!!!\n");
	printf("Score = %d", nextkill);
	getch();
	exit(0);
}

void garbagekilled()
{
	for (int i = 0; i <= enemy_count; i++)
		killed[i] = 25;
}

int iskilled(int i)
{
	for (int j = 0; j <= enemy_count; j++)
	{
		if (i == killed[j])
			return 1;
	}

	return 0;
}

void ship(int x, int y)
{
	line(x - 10, y, x + 10, y);
	line(x - 10, y, x - 10, y + 30);
	line(x + 10, y, x + 10, y + 30);
	line(x - 45, y + 30, x - 10, y + 30);
	line(x + 10, y + 30, x + 45, y + 30);
	line(x - 45, y + 30, x - 45, y + 45);
	line(x + 45, y + 30, x + 45, y + 45);
	line(x - 45, y + 45, x + 45, y + 45);
}

void spawn_enemy()
{
	int gap = 25 + 5;
	for (int i = 0; i <= enemy_count; i++)
	{
		if (!iskilled(i))
			rectangle(2 + i * gap, 2, 25 + i * gap, 25);
	}
}

void shoot(int x, int y)
{
	int Y = y;
	while (Y >= 100)
	{
		cleardevice();
		ship(x, y);
		spawn_enemy();
		Y = Y - 5;
		rectangle(x - 5, Y - 10, x + 5, Y);
		// delay(50);
	}

	int killedindex = (x + 1) / 30;
	if (!iskilled(killedindex))
	{
		explosion(x, 12);
		killed[nextkill] = killedindex;
		nextkill = nextkill + 1;
	}
	cleardevice();
	ship(x, y);
	spawn_enemy();

	if (nextkill == enemy_count + 1)
		GameOver();
}

void movement(char ip, int *x, int *y)
{
	switch (ip)
	{
	case 'a':
		*x = *x - 5;
		break;
	case 'd':
		*x = *x + 5;
		break;
	case 's':
		*y = *y + 5;
		break;
	case 'w':
		*y = *y - 5;
		break;

	default:
		break;
	}

	cleardevice();
	spawn_enemy();
	ship(*x, *y);
	// delay(50);
}

void main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	int x = 250, y = 250;

	garbagekilled();

	char ip = 'l';

	while (ip != 'q')
	{

		ip = getch();

		if (ip != ' ')
			movement(ip, &x, &y);
		else
		{
			shoot(x, y);
		}
	}

	getch();
	closegraph();
}
// tail