#include <stdio.h>

#define MID 200000

int a[5000];
int d[410000];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (d[a[i] - a[j] + MID] == 1) {
				ans += 1;
				break;
			}
		}

		for (int j = 0; j <= i; j++) {
			d[a[i] + a[j] + MID] = 1;
		}
	}

	printf("%d\n", ans);
	return 0;
}
