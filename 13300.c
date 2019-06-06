#include <stdio.h>

int a[2][7];

int main(void) {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x][y] += 1;
	}

	int ans = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= 6; j++) {
			ans += (a[i][j] / k + 1);
			if (a[i][j] % k == 0) {
				ans -= 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
