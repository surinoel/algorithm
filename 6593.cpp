#include <tuple>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 1, -1, 0, 0, 0, 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		int n, m, c;
		cin >> n >> m >> c;
		if (n == 0 && m == 0 && c == 0) break;
		int sz, sx, sy, ez, ex, ey;
		vector<vector<vector<int>>> mat(n, vector<vector<int>>(m, vector<int>(c)));
		vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(c, -1)));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				string s; cin >> s;
				for (int k = 0; k < s.size(); k++) {
					if (s[k] == '#') mat[i][j][k] = -1;
					else if (s[k] == '.') mat[i][j][k] = 0;
					else if (s[k] == 'S') {
						sz = i, sx = j, sy = k;
					}
					else if (s[k] == 'E') {
						ez = i, ex = j, ey = k;
					}
				}
			}
		}

		queue<tuple<int, int, int>> q;
		q.push(make_tuple(sz, sx, sy));
		dist[sz][sx][sy] = 0;
		while (!q.empty()) {
			int x, y, z;
			tie(z, x, y) = q.front();
			q.pop();

			for (int k = 0; k < 6; k++) {
				int tz = z + dz[k];
				int tx = x + dx[k];
				int ty = y + dy[k];

				if (tx < 0 || ty < 0 || tz < 0 || tx > m - 1 || ty > c - 1 || tz > n - 1 || mat[tz][tx][ty] == -1 || dist[tz][tx][ty] != -1) continue;
				q.push(make_tuple(tz, tx, ty));
				dist[tz][tx][ty] = dist[z][x][y] + 1;
 			}
		}

		if (dist[ez][ex][ey] != -1) {
			cout << "Escaped in " << dist[ez][ex][ey] << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}
	return 0;
}
