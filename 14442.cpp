#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}

	vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k + 1, -1)));
	dist[0][0][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int u = 0; u < 4; u++) {
			int tx = x + dx[u];
			int ty = y + dy[u];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (mat[tx][ty] == 0) {
				if (dist[tx][ty][z] == -1 && dist[x][y][z] != -1) {
					dist[tx][ty][z] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z));
				}
			}
			else {
				if (z == k) continue;
				if (dist[tx][ty][z + 1] == -1 && dist[x][y][z] != -1) {
					dist[tx][ty][z + 1] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z + 1));
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= k; i++) {
		if (dist[n - 1][m - 1][i] == -1) continue;
		if (ans == -1 || ans > dist[n - 1][m - 1][i]) {
			ans = dist[n - 1][m - 1][i];
		}
	}

	cout << ans << '\n';
	return 0;
}
