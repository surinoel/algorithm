#include <stdio.h>

void blank(int blank)
{
	while (blank--)
	{
		printf(" ");
	}
}

void star(int star)
{
	while (star--)
	{
		printf("*");
	}
}

int main(void)
{
	int star_size;
	scanf("%d", &star_size);
	for (int i = 1; i <= star_size * 2 - 1; i++)
	{
		if (i <= star_size) {
			blank(star_size - i);
			star(2 * i - 1);
			printf("\n");
		}
		else
		{
			blank(i - star_size);
			star(2 * (star_size - (i - star_size)) - 1);
			printf("\n");
		}
	}
}
