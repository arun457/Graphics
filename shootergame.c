#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#define enemy_count 20

int killed[enemy_count + 1];
int nextkill = 0;
int enemy_spawn_height = 25;
int x = 320, y = 430; // cords of ship

void explosion(int x1, int y1)
{
	circle(x1, y1, 5);
	delay(50);
	cleardevice();
	circle(x1, y1, 10);
	delay(50);
	cleardevice();
	circle(x1, y1, 15);
	delay(50);
	cleardevice();
	circle(x1, y1, 20);
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

void ship()
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
	if (enemy_spawn_height >= y)
	{
		GameOver();
	}

	int gap = 25 + 5;
	for (int i = 0; i <= enemy_count; i++)
	{
		if (!iskilled(i))
			rectangle(2 + i * gap, enemy_spawn_height - 23, 25 + i * gap, enemy_spawn_height);
	}
}

void shoot()
{
	int Y = y;
	while (Y >= enemy_spawn_height)
	{
		cleardevice();
		ship();
		spawn_enemy();
		Y = Y - 5;
		rectangle(x - 5, Y - 10, x + 5, Y);
	}

	int killedindex = (x + 1) / 30;
	if (!iskilled(killedindex))
	{
		explosion(x, enemy_spawn_height - 13);
		killed[nextkill] = killedindex;
		nextkill = nextkill + 1;
	}
	cleardevice();
	ship();
	spawn_enemy();

	if (nextkill == enemy_count + 1)
		GameOver();
}

void movement(char ip)
{
	switch (ip)
	{
	case 'a':
		x = x - 5;
		break;
	case 'd':
		x = x + 5;
		break;
	case 's':
		y = y + 5;
		break;
	case 'w':
		y = y - 5;
		break;

	default:
		break;
	}

	cleardevice();
	spawn_enemy();
	ship();
}

void main()
{

	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	garbagekilled();

	char ip = 'l';
	int time = 0;

	while (ip != 'q')
	{

		time++;
		if (time % 10000 == 0)
		{
			enemy_spawn_height += 5;
			cleardevice();
			ship();
			spawn_enemy();
		}

		if (kbhit())
		{

			ip = getch();

			if (ip != ' ')
				movement(ip);
			else
			{
				shoot();
			}
		}
	}

	getch();
	closegraph();
}