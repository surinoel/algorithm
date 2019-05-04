#include <cstdio>
#include <cstdlib>
#include <cstring>

int mat[9][9];
bool row[9][10];
bool col[9][10];
bool sqaure[9][10];
void go(int idx) {
	if (idx == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	int x = idx / 9;
	int y = idx % 9;
	if (mat[x][y] != 0) {
		go(idx + 1);
	}
	else {
		bool check[10];
		memset(check, false, sizeof(check));
		for (int j = 1; j <= 9; j++) {
			if (row[x][j] == true) {
				check[j] = true;
			}
			if (col[y][j] == true) {
				check[j] = true;
			}
			if (sqaure[3 * (x / 3) + y / 3][j] == true) {
				check[j] = true;
			}
		}
	
		for (int i = 1; i <= 9; i++) {
			if (check[i] == false) {
				row[x][i] = true;
				col[y][i] = true;
				sqaure[3 * (x / 3) + y / 3][i] = true;
				mat[x][y] = i;
				go(idx + 1);
				mat[x][y] = 0;
				row[x][i] = false;
				col[y][i] = false;
				sqaure[3 * (x / 3) + y / 3][i] = false;
			}
		}
	}
}

int main(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			row[i][mat[i][j]] = true;
		}
	}
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			col[j][mat[i][j]] = true;
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sqaure[3 * (i / 3) + j / 3][mat[i][j]] = true;
		}
	}

	go(0);

	return 0;
}
