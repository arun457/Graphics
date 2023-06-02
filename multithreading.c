#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void *print_once()
{
	line(0, 0, 300, 300);

	return 0;
}

void *print_twice()
{
	line(0, 0, 300, 0);

	return 0;
}

int main(void)
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);

	pthread_t thread1, thread2;

	// make threads
	pthread_create(&thread1, NULL, print_once);
	pthread_create(&thread2, NULL, print_twice);

	// wait for them to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
