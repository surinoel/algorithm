#include <stdio.h>
#include <string.h>

#define max(n, m) n > m ? n : m
#define min(n, m) n > m ? m : n

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	
	return gcd(b, a%b);
}

int gcd3(int a, int b, int c) {
	int val = gcd(a, b);
	return gcd(max(val, c), min(val, c));
}

int main(void) {
	int n;
	scanf("%d", &n);
	if (n == 2) {
		int x, y;
		scanf("%d %d", &x, &y);
		int limit = gcd(max(x, y), min(x, y));
		for (int i = 1; i <= limit; i++) {
			if (limit % i == 0) {
				printf("%d\n", i);
			}
		}
	}
	else {
		int a[3];
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 3; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2 - i; j++) {
				if (a[j] < a[j + 1]) {
					int tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
		}
		int limit = gcd3(a[2], a[1], a[0]);
		for (int i = 1; i <= limit; i++) {
			if (limit % i == 0) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}
