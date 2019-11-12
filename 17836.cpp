#include <tuple>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;

int mat[100][100];
int dist[100][100][2];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	dist[0][0][0] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (z == 0) {
				if (mat[tx][ty] == 0 && dist[tx][ty][z] == -1) {
					dist[tx][ty][z] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z));
				}
				else if (mat[tx][ty] == 2 && dist[tx][ty][z] == -1) {
					dist[tx][ty][1] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, 1));
				}
			}
			else {
				if ((mat[tx][ty] == 0 || mat[tx][ty] == 1) && dist[tx][ty][z] == -1) {
					dist[tx][ty][z] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, z));
				}
			}
		}
	}

	int ans = -1;
	if (ans == -1 || ans > dist[n - 1][m - 1][0]) {
		ans = dist[n - 1][m - 1][0];
	}
	if (ans == -1 || ans > dist[n - 1][m - 1][1]) {
		ans = dist[n - 1][m - 1][1];
	}

	if (ans >= 0 && ans <= t) {
		cout << ans << '\n';
	}
	else {
		cout << "Fail\n";
	}

	return 0;
}
