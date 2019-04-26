#include <queue>
#include <tuple>
#include <cstdio>
#include <cstring>

using namespace std;

int mat[50][50];
int dist[50][50][2500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	freopen("data.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &mat[i][j]);
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
			int tz = z;

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
			if (mat[tx][ty] == 1) {
				bool ok = true;
				for (int u = 0; u <= tz; u++) {
					if (dist[tx][ty][u] != -1) {
						ok = false;
						break;
					}
				}
				if (ok) {
					dist[tx][ty][tz] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, tz));
				}
			}
			else if (mat[tx][ty] == 0) {
				bool ok = true;
				for (int u = 0; u <= tz + 1; u++) {
					if (dist[tx][ty][u] != -1) {
						ok = false;
						break;
					}
				}
				if (ok) {
					dist[tx][ty][tz + 1] = dist[x][y][z] + 1;
					q.push(make_tuple(tx, ty, tz + 1));
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < 2500; i++) {
		if (dist[n - 1][n - 1][i] != -1) {
			ans = i;
			break;
		}
	}

	printf("%d\n", ans);
	return 0;
}
