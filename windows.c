#include <stdio.h>
#include <dos.h>

void interrupt (*prevTimerInterrupt)();

void interrupt timerInterrupt()
{
	printf("Timer interrupt\n");
	(*prevTimerInterrupt)();
}

void print_once()
{
	printf("Foo");
}

void print_twice()
{
	printf("Bar");
	printf("Bar");
}

int main()
{
	prevTimerInterrupt = getvect(0x08); // Get previous timer interrupt handler
	setvect(0x08, timerInterrupt);		// Set custom timer interrupt handler

	print_once();
	print_twice();

	setvect(0x08, prevTimerInterrupt); // Restore previous timer interrupt handler

	return 0;
}
