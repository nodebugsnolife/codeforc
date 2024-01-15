#include <stdio.h>

int Add_2(int x, int y)
{
	return x + y;
}

int main()
{
	int p = 0;
	int i = 0;
	printf("input a target number:>");
	scanf("%d", &p);
	int t = p / 3;
	for (i = 1; i <= t; i++)
	{
		int a = 3 * i;
		printf("%d\n", a);

	}
}