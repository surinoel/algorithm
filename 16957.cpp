#include <cstring>
#include <iostream>

using namespace std;

typedef struct __point {
	int x, y;
	__point() : x(-1), y(-1) {}
} Point;

int n, m;
int mat[500][500];
int ans[500][500];
Point d[500][500];

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

Point go(int x, int y) {
	if (d[x][y].x != -1) {
		return d[x][y];
	}

	int minv = -1, minx, miny;
	for (int k = 0; k < 8; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
		if (mat[x][y] > mat[tx][ty]) {
			if (minv == -1 || minv > mat[tx][ty]) {
				minv = mat[tx][ty];
				minx = tx;
				miny = ty;
			}
		}
	}
	
	if (minv == -1) {
		d[x][y].x = x;
		d[x][y].y = y;
		return d[x][y];
	}
	return d[x][y] = go(minx, miny);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d[i][j].x == -1) {
				go(i, j);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[d[i][j].x][d[i][j].y] += 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}
