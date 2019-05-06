#include <cstdio>

int go(int n, int m) {
	if (n == 0) return 0;
	return n + go(n / m, m);
}

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n", go(n, m));
	return 0;
}
