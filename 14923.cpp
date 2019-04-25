#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <algorithm>

using namespace std;

int mat[1000][1000];
int dist[1000][1000][2];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	sx -= 1;
	sy -= 1;
	ex -= 1;
	ey -= 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sx, sy, 0));
	dist[sx][sy][0] = 0;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (mat[tx][ty] == 0 && dist[tx][ty][z] == -1) {
				dist[tx][ty][z] = dist[x][y][z] + 1;
				q.push(make_tuple(tx, ty, z));
			}
			else if (mat[tx][ty] == 1 && z == 0) {
				dist[tx][ty][z + 1] = dist[x][y][z] + 1;
				q.push(make_tuple(tx, ty, z + 1));
			}
		}
	}

	if (dist[ex][ey][0] == -1 && dist[ex][ey][1] == -1) {
		cout << "-1\n";
		return 0;
	}
	if (dist[ex][ey][0] == -1) {
		cout << dist[ex][ey][1] << '\n';
	}
	else if (dist[ex][ey][1] == -1) {
		cout << dist[ex][ey][0] << '\n';
	}
	else {
		cout << min(dist[ex][ey][0], dist[ex][ey][1]) << '\n';
	}
	
	return 0;
}
