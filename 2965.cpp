#include <stdio.h>

#define max(n, m) n > m ? n : m

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int ans = max(b - a, c - b);
	printf("%d\n", ans - 1);
	return 0;
}
