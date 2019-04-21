#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool check[1001];

int retlen(int n) {
	if (n == 0) {
		return 0;
	}
	return retlen(n / 10) + 1;
}

int main(void) {
	for (int i = 1; i <= 9; i++) {
		check[i] = true;
	}
	for (int i = 10; i <= 1000; i++) {
		int len = retlen(i);
		int ex = i % 10;
		int sx = (i / 10) % 10;
		int diff = sx - ex;
		ex = sx;
		bool ok = true;
		for (int j = 2; j < len; j++) {
			sx = (i / (int)(pow(10, j))) % 10;
			if (sx - ex != diff) {
				ok = false;
				break;
			}
			ex = sx;
		}
		if (ok) {
			check[i] = true;
		}
	}

	int n; 
	scanf("%d", &n);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i]) ans += 1;
	}
	printf("%d\n", ans);

	return 0;
}
