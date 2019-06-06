#include <stdio.h>

double memo[51];

double fact(int n) {
	if (n == 1 || n == 0) return 1;
	if (memo[n] > 0) {
		return memo[n];
	}
	return memo[n] = n * fact(n - 1);
}

double comb(int n, int r) {
	double a, b, c;
	a = fact(n);
	b = fact(r);
	c = fact(n - r);

	return a / (b*c);
}

int main(void) {
	int n, m, r;
	scanf("%d %d", &n, &m);
	r = m - n;
	printf("%.lf\n", comb(n + r - 1, r));
	return 0;
}
