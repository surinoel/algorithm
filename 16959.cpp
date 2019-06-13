#include <tuple>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int mat[10][10];
int dist[3][10][10][100];
int dx1[] = { 1, 2, 1, 2, -1, -2, -1, -2 };
int dy1[] = { -2, -1, 2, 1, 2, 1, -2, -1 };
int dx2[] = { 1, -1, 0, 0 };
int dy2[] = { 0, 0, 1, -1 };
int dx3[] = { 1, -1, 1, -1 };
int dy3[] = { 1, 1, -1, -1 };
 
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, sx, sy;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			mat[i][j] -= 1;
			if (mat[i][j] == 0) {
				sx = i, sy = j;
			}
		}
	}

	queue<tuple<int, int, int, int>> q;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < 3; i++) {
		dist[i][sx][sy][0] = 0;
		q.push(make_tuple(i, sx, sy, 0));
	}

	int ans = -1;
	while (!q.empty()) {
		int kind, x, y, num;
		tie(kind, x, y, num) = q.front();
		q.pop();

		if (num == n*n - 1) {
			if (ans == -1 || ans > dist[kind][x][y][num]) {
				ans = dist[kind][x][y][num];
			}
			continue;
		}

		for (int k = 0; k < 3; k++) {
			if (kind == k) continue;
			if (dist[k][x][y][num] == -1) {
				dist[k][x][y][num] = dist[kind][x][y][num] + 1;
				q.push(make_tuple(k, x, y, num));
			}
		}

		if (kind == 0) {
			for (int i = 0; i < 8; i++) {
				int tx = x + dx1[i];
				int ty = y + dy1[i];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
				int n = num;
				if (mat[tx][ty] == n + 1) {
					n += 1;
				}
				if (dist[kind][tx][ty][n] == -1) {
					dist[kind][tx][ty][n] = dist[kind][x][y][num] + 1;
					q.push(make_tuple(kind, tx, ty, n));
				}
			}
		}
		else if (kind == 1) {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; ; j++) {
					int tx = x + dx2[i] * j;
					int ty = y + dy2[i] * j;
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) break;
					int n = num;
					if (mat[tx][ty] == n + 1) {
						n += 1;
					}
					if (dist[kind][tx][ty][n] == -1) {
						dist[kind][tx][ty][n] = dist[kind][x][y][num] + 1;
						q.push(make_tuple(kind, tx, ty, n));
					}
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				for (int j = 1; ; j++) {
					int tx = x + dx3[i] * j;
					int ty = y + dy3[i] * j;
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) break;
					int n = num;
					if (mat[tx][ty] == n + 1) {
						n += 1;
					}
					if (dist[kind][tx][ty][n] == -1) {
						dist[kind][tx][ty][n] = dist[kind][x][y][num] + 1;
						q.push(make_tuple(kind, tx, ty, n));
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
