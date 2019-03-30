#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int mat[100][100][100];
int dist[100][100][100];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dist, -1, sizeof(dist));
	int n, m, h;
	cin >> m >> n >> h;
	queue<tuple<int, int, int>> q;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j][k];
				if (mat[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
					dist[i][j][k] = 0;
				}
			}
		}
	}

	queue<tuple<int, int, int>> nxt_q;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 6; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			int tz = z + dz[k];
			
			if (tx < 0 || ty < 0 || tz < 0 || tx > n - 1 || ty > m - 1 || tz > h - 1) continue;
			if (dist[tx][ty][tz] != -1 || mat[tx][ty][tz] == -1) continue;
			dist[tx][ty][tz] = dist[x][y][z] + 1;
			nxt_q.push(make_tuple(tx, ty, tz));
		}

		if (q.empty()) {
			q = nxt_q;
			while (!nxt_q.empty()) {
				nxt_q.pop();
			}
		}
	}

	int ans = -1;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j][k] == 0 && dist[i][j][k] == -1) {
					cout << "-1\n";
					return 0;
				}
				if (dist[i][j][k] > ans) {
					ans = dist[i][j][k];
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}