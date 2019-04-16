#include <stdio.h>

int d[15][15];

int main(void) {
	for (int i = 0; i <= 14; i++) {
		for (int j = 1; j <= 15; j++) {
			if (i == 0) d[i][j] = j;
			else {
				for (int k = 1; k <= j; k++) {
					d[i][j] += d[i - 1][k];
				}
			}
		}
	}
	
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, k;
		scanf("%d %d", &n, &k);
		printf("%d\n", d[n][k]);
	}

	return 0;
}
