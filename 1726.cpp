#include <queue>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

int mat[100][100];
int dist[100][100][5];

int dx[5] = { 0, 0, 0, 1, -1 };
int dy[5] = { 0, 1, -1, 0 ,0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	int sx, sy, sdir;
	cin >> sx >> sy >> sdir;
	int ex, ey, edir;
	cin >> ex >> ey >> edir;

	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(sx - 1, sy - 1, sdir));
	dist[sx - 1][sy - 1][sdir] = 0;

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		int cz, ccz;
		if (z == 1) cz = 4;
		else if (z == 2) cz = 3;
		else if (z == 3) cz = 1;
		else cz = 2;

		if (dist[x][y][cz] == -1) {
			q.push(make_tuple(x, y, cz));
			dist[x][y][cz] = dist[x][y][z] + 1;
		}

		if (z == 1) ccz = 3;
		else if (z == 2) ccz = 4;
		else if (z == 3) ccz = 2;
		else ccz = 1;

		if (dist[x][y][ccz] == -1) {
			q.push(make_tuple(x, y, ccz));
			dist[x][y][ccz] = dist[x][y][z] + 1;
		}

		for (int k : { 1, 2, 3 }) {
			int tx = x + k*dx[z];
			int ty = y + k*dy[z];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 1) break;
			if (dist[tx][ty][z] != -1) continue;
			q.push(make_tuple(tx, ty, z));
			dist[tx][ty][z] = dist[x][y][z] + 1;
		}
	}
	
	cout << dist[ex - 1][ey - 1][edir] << '\n';
	return 0;
}
