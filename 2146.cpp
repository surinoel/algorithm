#include <tuple>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int a[100][100];
int g[100][100];
int d[100][100];
int dist[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	int group_num = 0;
	queue<pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 1 && g[i][j] == 0) {
				g[i][j] = ++group_num;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || a[tx][ty] == 0 || g[tx][ty] != 0) continue;
						g[tx][ty] = group_num;
						q.push(make_pair(tx, ty));
					}
				}
			}
			if (a[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k];
					int ty = j + dy[k];
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || a[tx][ty] == 1) continue;
					d[i][j] += 1;
				}
				if (d[i][j] > 0) dq.push(make_pair(i, j));
			}
		}
	}
	
	int ans = -1;
	while (!dq.empty()) {
		int i, j;
		tie(i, j) = dq.front();
		dq.pop();

		memset(dist, -1, sizeof(dist));
		queue<pair<int, int>> q;
		q.push(make_pair(i, j));
		dist[i][j] = 0;
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
            		if(ans != -1 && dist[x][y] > ans) break;
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || dist[tx][ty] != -1 || g[i][j] == g[tx][ty]) continue;
				if (a[tx][ty] == 1) {
					if (ans == -1 || ans > dist[x][y]) {
						ans = dist[x][y];
						goto end;
					}
				}
				dist[tx][ty] = dist[x][y] + 1;
				q.push(make_pair(tx, ty));
			}
		}
	end:
		;
	}

	printf("%d\n", ans);
	return 0;
}
