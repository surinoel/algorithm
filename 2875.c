#include <stdio.h>

int main(void) {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	
	int t, res;
	if (n >= 2 *m) {
		t = m;
	}
	else {
		t = n / 2;
	}
	res = n + m - 3 * t;
	if (k - res > 0) {
		res = k - res;
		t -= (res / 3 + 1);
		if (res % 3 == 0) {
			t += 1;
		}
		if (t < 0) {
			t = 0;
		}
	}
	printf("%d\n", t);
	return 0;
}
