#include <stdio.h>

void blank(int n) {
	while (n--) {
		printf(" ");
	}
}

void star(int n) {
	while (n--) {
		printf("*");
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		blank(n - i);
		star(2 * i - 1);
		printf("\n");
	}
	return 0;
}
