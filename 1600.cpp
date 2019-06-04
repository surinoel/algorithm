#include <tuple>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int dist[31][200][200];
int mat[200][200];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ddx[8] = { 2, 1, -1, -2, 2, 1, -1, -2 };
int ddy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n, m;
	cin >> k >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int ,int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int z, x, y;
		tie(z, x, y) = q.front();
		q.pop();

		if (z + 1 <= k) {
			for (int u = 0; u < 8; u++) {
				int tx = x + ddx[u];
				int ty = y + ddy[u];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 1 || dist[z + 1][tx][ty] != -1) continue;
				dist[z + 1][tx][ty] = dist[z][x][y] + 1;
				q.push(make_tuple(z + 1, tx, ty));
			}
		}
	
		for (int u = 0; u < 4; u++) {
			int tx = x + dx[u];
			int ty = y + dy[u];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 1 || dist[z][tx][ty] != -1) continue;
			dist[z][tx][ty] = dist[z][x][y] + 1;
			q.push(make_tuple(z, tx, ty));
		}
	}

	int ans = -1;
	for (int i = 0; i <= k; i++) {
		if (dist[i][n - 1][m - 1] != -1) {
			if (ans == -1 || ans > dist[i][n - 1][m - 1]) {
				ans = dist[i][n - 1][m - 1];
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
