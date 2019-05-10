#include <stdio.h>

#define max(n, m) (n>=m) ? n : m
#define min(n, m) (n>=m) ? m : n

long long gcd(long long n, long long m) {
	if (m == 0) {
		return n;
	}
	return gcd(m, n%m);
}

int main(void) {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	
	for (int i = 0; i < gcd(max(n, m), min(n, m)); i++) {
		printf("%d", 1);
	}
	printf("\n");
	return 0;
}
