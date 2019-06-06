#include <stdio.h>

short mat[2200][2200];
int ans[3];

void go(int n, int x, int y) {
	if (n == 1) {
		ans[mat[x][y] + 1] += 1;
		return;
	}

	int ok, val;
	for (int i = x - n / 2; i < x + n / 2 + 1; i++) {
		for (int j = y - n / 2; j < y + n / 2 + 1; j++) {
			if (i == x - n / 2 && j == y - n / 2) {
				ok = 1;
				val = mat[i][j];
			}
			else if (ok == 1 && val != mat[i][j]) {
				ok = -1;
				goto end;
			}
		}
	}
	ans[val + 1] += 1;

end:
	if (ok == -1) {
		go(n / 3, x, y);
		go(n / 3, x - n / 3, y - n / 3);
		go(n / 3, x - n / 3, y);
		go(n / 3, x - n / 3, y + n / 3);
		go(n / 3, x, y - n / 3);
		go(n / 3, x, y + n / 3);
		go(n / 3, x + n / 3, y);
		go(n / 3, x + n / 3, y - n / 3);
		go(n / 3, x + n / 3, y + n / 3);
	}
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	go(n, n / 2, n / 2);
	printf("%d\n%d\n%d\n", ans[0], ans[1], ans[2]);
	return 0;
}
