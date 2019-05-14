#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include<string.h>

int main()
{
	int i = 0;
	char bar[102];
	memset(bar, 0, sizeof(bar));
	const char*lable = "|/-||";
	while (i <= 100)
	{
		printf("[%-100s][%d%%][%c]\r", bar, i,lable [i % 4]);
		fflush(stdout);
		bar[i++] = '#';
		sleep(50000);
	}
	printf("\n");
	system("pause");
	return 0;
}