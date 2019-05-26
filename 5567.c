#include <stdio.h>

int d[501][501];
int visit[501];

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	while (m--) {
	int x, y;
	scanf("%d %d", &x, &y);
	d[x][y] = 1;
	d[y][x] = 1;
	}

	int ans = 0;
	visit[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (d[1][i] == 1) {
			if(!visit[i]) {
				ans += 1;
				visit[i] = 1;
			}
			for (int j = 1; j <= n; j++) {
				if (d[i][j] == 1) {
					if(!visit[j]) {
						ans += 1;
						visit[j] = 1;
					}
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}
