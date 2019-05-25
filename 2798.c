#include <stdio.h>

using namespace std;

int a[100];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (i == j || j == k || i == k) continue;
				int sum = a[i] + a[j] + a[k];
				if ((ans == -1 && sum <= m) || (sum > ans && sum <= m)) {
					ans = sum;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
