#include <stdio.h>

int d[101];

int main(void) {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	for (int i = 0; i < 3; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		for (int j = s; j < e; j++) {
			d[j] += 1;
		}
	}

	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		if (d[i] == 1) {
			ans += a * d[i];
		}
		else if (d[i] == 2) {
			ans += b * d[i];
		}
		else if (d[i] == 3) {
			ans += c * d[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
