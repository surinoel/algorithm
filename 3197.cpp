#include <tuple>
#include <queue>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int mat[1500][1500];
int ice_dist[1500][1500];
int dist[1500][1500];
int group[1500][1500];
bool visit[1500][1500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int sx, sy, ex, ey;
	sx = sy = ex = ey = -1;
	memset(ice_dist, -1, sizeof(ice_dist));
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'X') {
				mat[i][j] = 1;
			}
			else if (s[j] == 'L') {
				if (sx == -1) {
					sx = i, sy = j;
				}
				else {
					ex = i, ey = j;
				}
				q.push(make_pair(i, j));
				ice_dist[i][j] = 0;
			}
			else {
				q.push(make_pair(i, j));
				ice_dist[i][j] = 0;
			}
		}
	}

	queue<pair<int, int>> nxt_q;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (ice_dist[tx][ty] == -1) {
				ice_dist[tx][ty] = ice_dist[x][y] + 1;
				q.push(make_pair(tx, ty));
			}
		}
	}

	queue<pair<int, int>> mem;
	q = queue<pair<int, int>>();
	memset(dist, -1, sizeof(dist));
	q.push(make_pair(sx, sy));
	dist[sx][sy] = 0;
	visit[sx][sy] = true;

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		int cnt = 0;
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || visit[tx][ty]) continue;
			if (mat[tx][ty] == 1) {
				cnt += 1;
				continue;
			}
			q.push(make_pair(tx, ty));
			dist[tx][ty] = 0;
			visit[tx][ty] = true;
		}

		if (cnt > 0) {
			mem.push(make_pair(x, y));
		}
	}

	memset(visit, false, sizeof(visit));
	memset(group, -1, sizeof(group));
	q = queue<pair<int, int>>();
	visit[ex][ey] = true;
	group[ex][ey] = 0;
	q.push(make_pair(ex, ey));

	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 1 || group[tx][ty] == 0) continue;
			q.push(make_pair(tx, ty));
			group[tx][ty] = 0;
			visit[tx][ty] = true;
		}
	}

	nxt_q = queue<pair<int, int>>();
	while (!mem.empty()) {
		int x, y;
		tie(x, y) = mem.front();
		mem.pop();

		if (group[x][y] == 0) {
			cout << dist[x][y] << '\n';
			break;
		}

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (mat[tx][ty] == 1) {
				if (ice_dist[tx][ty] == dist[x][y] + 1) {
					if (dist[tx][ty] == -1) {
						dist[tx][ty] = dist[x][y] + 1;
						nxt_q.push(make_pair(tx, ty));
					}
				}
				else if (ice_dist[tx][ty] < dist[x][y] + 1) {
					if (dist[tx][ty] == -1) {
						dist[tx][ty] = dist[x][y];
						mem.push(make_pair(tx, ty));
					}
				}
			}
			else {
				if (dist[tx][ty] == -1) {
					dist[tx][ty] = dist[x][y];
					mem.push(make_pair(tx, ty));
				}
			}
		}

		if (mem.empty()) {
			mem = nxt_q;
			nxt_q = queue<pair<int, int>>();
		}
	}

	return 0;
}
