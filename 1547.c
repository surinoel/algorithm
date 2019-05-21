#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);
	int ball = 1;
	while (n--) {
		int x, y;
		scanf("%d %d", &n, &y);
		if (x == y) continue;
		if (x == ball) ball = y;
		else if (y == ball) ball = x;
	}

	printf("%d\n", ball);
	return 0;
}
