#include <queue>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

int n, m, h, w;
int mat[1000][1000];
int dist[1000][1000];

bool check_corner(int x, int y) {

	for (int i = x; i < x + h; i++) {
		if (i < 0 || i > n - 1 || mat[i][y] == 1) return false;
		if (y + w - 1 > m - 1 || mat[i][y + w - 1] == 1) return false;
	}

	for (int j = y; j < y + w; j++) {
		if (j < 0 || j > m - 1 || mat[x][j] == 1) return false;
		if (x + h - 1 > n - 1 || mat[x + h - 1][j] == 1) return false;
	}

	return true;
}

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int sx, sy, ex, ey;
	cin >> h >> w >> sx >> sy >> ex >> ey;
	sx -= 1, sy -= 1, ex -= 1, ey -= 1;

	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	dist[sx][sy] = 0;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 1 || dist[tx][ty] != -1) continue;
			if (!check_corner(tx, ty)) continue;
			dist[tx][ty] = dist[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}	
	
	cout << dist[ex][ey] << '\n';
	return 0;
}
