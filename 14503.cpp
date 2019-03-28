#include <iostream>

using namespace std;

int n, m;
int mat[50][50];
bool visit[50][50];
bool is_end = false;
// ºÏ µ¿ ³² ¼­
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int go(int x, int y, int dir) {
	int ans = 0;
	if (visit[x][y] == false) {
		visit[x][y] = true;
		ans += 1;
	}
	int d = dir;
	for (int k = 0; k < 4; k++) {
		if (--d == -1) {
			d = 3;
		}
		int tx = x + dx[d];
		int ty = y + dy[d];
		if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
		if (mat[tx][ty] == 1) continue;
		if (visit[tx][ty] == true) continue;
		ans += go(tx, ty, d);
		if (is_end) return ans;
	}

	int tx = x - dx[dir];
	int ty = y - dy[dir];
	if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
		if (mat[tx][ty] == 1) {
			is_end = true;
		}
		else {
			ans += go(tx, ty, dir);
		}
	}

	return ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	int rx, ry, dir;
	cin >> rx >> ry >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	cout << go(rx, ry, dir) << '\n';
	return 0;
}
