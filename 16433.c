#include <stdio.h>

int n, r, c;
int maxv = -1;
int mat[99][99];

int dx[4] = { 1, 1, -1, -1 };
int dy[4] = { 1, -1, 1, -1 };

void go(int x, int y) {
	if (x < 0 || y < 0 || x > n - 1 || y > n - 1 || mat[x][y] == 1) {
		return;
	}

	mat[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		go(tx, ty);
	}

	return;
}

int main(void) {
	scanf("%d %d %d", &n, &r, &c);
	
	go(r - 1, c - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				printf(".");
			}
			else {
				printf("v");
			}
		}
		printf("\n");
	}

	return 0;
}
