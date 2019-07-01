#include <tuple>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int mat[100][100];
int dist[201][100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n, m;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}
	
	memset(dist, -1, sizeof(dist));
	dist[0][0][0] = 0;
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	while (!q.empty()) {
		int z, x, y;
		tie(z, x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (mat[tx][ty] == 0 && dist[z][tx][ty] == -1) {
				dist[z][tx][ty] = dist[z][x][y] + 1;
				q.push(make_tuple(z, tx, ty));
			}
			else if (mat[tx][ty] == 1 && dist[z + 1][tx][ty] == -1) {
				dist[z + 1][tx][ty] = dist[z][x][y] + 1;
				q.push(make_tuple(z + 1, tx, ty));
			}
		}
	}

	for (int i = 0; i <= 200; i++) {
		if (dist[i][n - 1][m - 1] != -1) {
			printf("%d\n", i);
			return 0;
		}
	}
}
