#include <stdio.h>

char buf[10][11];
char ans[10][11];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (buf[i][j] == '.') {
				ans[i][j] = '.';
				continue;
			}
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int tx = i + dx[k];
				int ty = j + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || buf[tx][ty] == '.') {
					cnt += 1;
				}
			}
			if (cnt >= 3) {
				ans[i][j] = '.';
			}
			else {
				ans[i][j] = 'X';
			}
		}
	}

	int stx, sty, exx, exy;
	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 'X') {
				flag = 1;
			}
		}
		if (flag) {
			stx = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (ans[i][j] == 'X') {
				flag = 1;
			}
		}
		if (flag) {
			exx = i;
			break;
		}
	}

	for (int j = 0; j < m; j++) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i][j] == 'X') {
				flag = 1;
			}
		}
		if (flag) {
			sty = j;
			break;
		}
	}

	for (int j = m - 1; j >= 0; j--) {
		int flag = 0;
		for (int i = 0; i < n; i++) {
			if (ans[i][j] == 'X') {
				flag = 1;
			}
		}
		if (flag) {
			exy = j;
			break;
		}
	}

	for (int i = stx; i <= exx; i++) {
		for (int j = sty; j <= exy; j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}

	return 0;
}
