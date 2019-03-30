#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

int mat[50][50];
int dist[50][50];

int dx[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 1) {
				q.push(make_pair(i, j));
				dist[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> nxt_q;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
	
		for (int k = 0; k < 8; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (dist[tx][ty] != -1) continue;
			dist[tx][ty] = dist[x][y] + 1;
			nxt_q.push(make_pair(tx, ty));
		}

		if (q.empty()) {
			q = nxt_q;
			while (!nxt_q.empty()) {
				nxt_q.pop();
			}
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (ans == -1 || dist[i][j] > ans) {
				ans = dist[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
