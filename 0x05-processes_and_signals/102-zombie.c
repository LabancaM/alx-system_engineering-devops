#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

/**
 * infinite_whil - compute infinite loop and return nothing
 * Return: 0 in the end
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - principal entry of program that creats 5 zombie process
 * Return: 0 if success
*/
int main(void)
{
	pid_t pid;
	int child;

	for (child = 0; child < 5; child++)
	{
		pid = fork();
		if (!pid)
			break;
		printf("Zombie process created, PID: %i\n", (int)pid);
	}
	if (pid != 0)
		infinite_while();
	return (0);
}
