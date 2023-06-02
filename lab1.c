#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void draw_man(int X, int Y)
{
	circle(X, Y, 50);											  // head
	circle(X - 18, Y - 10, 10);									  // left eye
	circle(X + 18, Y - 10, 10);									  // right eye
	rectangle(X - 55, Y + 50, X + 55, Y + 50 + 150);			  // body
	rectangle(X - 55 - 5 - 20, Y + 50, X - 55 - 5, Y + 50 + 100); // left hand
	rectangle(X + 55 + 5, Y + 50, X + 55 + 5 + 20, Y + 50 + 100); // right hand
	rectangle(X - 40, Y + 50 + 150, X - 15, Y + 50 + 150 + 75);	  // left leg
	rectangle(X + 15, Y + 50 + 150, X + 40, Y + 50 + 150 + 75);	  // right leg
}
void main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	int X = 175, Y = 125, gap = 150;
	draw_man(X, Y);
	arc(X, Y + 5, 210, 330, 25); // mouth1
	draw_man(X + 55 + 5 + 20 + gap, Y);
	rectangle(X + 55 + 5 + 20 + gap - 20, Y + 12, X + 55 + 5 + 20 + gap + 20, Y + 12 + 15); // mouth2
	getch();
	closegraph();

	ellipse(X, Y, Starting Angle, Ending Angle, X - Radius, Y - Radius);
}