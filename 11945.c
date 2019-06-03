#include <stdio.h>

char mat[10][10];

int main(void) {
	int n, m;
	char c;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", mat[i]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			printf("%c", mat[i][j]);
		}
		printf("\n");
	}

	return 0;
}
