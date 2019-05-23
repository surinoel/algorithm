#include <stdio.h>
#include <string.h>

int a[200][3];
int d[101];
int ans[200];

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	for (int i = 0; i < 3; i++) {
		memset(d, 0, sizeof(d));
		for (int j = 0; j < n; j++) {
			d[a[j][i]] += 1;
		}
		for (int j = 0; j < n; j++) {
			if (d[a[j][i]] == 1) {
				ans[j] += a[j][i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}
