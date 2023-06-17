#include <stdio.h>
#include <conio.h>
#include <graphics.h>

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, r;
    float x, y, pk;

    x1 = 150;
    y1 = 150;
    r = 100;

    x = 0;
    y = r;
    pk = 1 - r;

    while (x <= y)
    {

        if (pk < 0)
        {
            pk = pk + 2 * x + 3;
        }
        else
        {
            pk = pk + 2 * x - 2 * y + 5;
            y = y - 1;
        }
        x = x + 1;

        putpixel(x + x1, y + y1, WHITE);
        putpixel(y + x1, x + y1, WHITE);
        putpixel(-x + x1, y + y1, WHITE);
        putpixel(-y + x1, x + y1, WHITE);
        putpixel(-x + x1, -y + y1, WHITE);
        putpixel(-y + x1, -x + y1, WHITE);
        putpixel(x + x1, -y + y1, WHITE);
        putpixel(y + x1, -x + y1, WHITE);
    }

    getch();
    closegraph();
}