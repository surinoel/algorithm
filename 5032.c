#include <stdio.h>

int go(int n, int k) {
	if (n < k) return 0;
	return n / k + go(n / k + n%k, k);
}

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	printf("%d\n", go(n + m, k));
	return 0;
}
