#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int mat[20][20];
int dist[11][20][20];

int n, m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int x, int y, int grp) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	dist[grp][x][y] = 0;

	while (!q.empty()) {
		int tx, ty;
		tie(tx, ty) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ttx = tx + dx[k];
			int tty = ty + dy[k];

			if (ttx < 0 || tty < 0 || ttx > n - 1 || tty > m - 1) continue;
			if (dist[grp][ttx][tty] != -1 || mat[ttx][tty] == -1) continue;
			dist[grp][ttx][tty] = dist[grp][tx][ty] + 1;
			q.push(make_pair(ttx, tty));
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		cin >> m >> n;
		if (n == 0 && m == 0) {
			break;
		}
		int sx, sy;
		int region = 1;
		vector<tuple<int, int, int>> v;
		memset(mat, 0, sizeof(mat));
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == 'o') {
					sx = i, sy = j;
				}
				else if (s[j] == 'x') {
					mat[i][j] = -1;
				}
				else if (s[j] == '*') {
					v.push_back(make_tuple(i, j, region++));
				}
			}
		}

		bfs(sx, sy, 0);
		for (int i = 0; i < v.size(); i++) {
			bfs(get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
		}
		sort(v.begin(), v.end(), [](auto &v1, auto &v2) {
			return v1 < v2;
		});

		int ans = -1;
		do {
			int dst = dist[0][get<0>(v[0])][get<1>(v[0])];
			if (dst == -1) {
				continue;
			}
			bool ok = true;

			for (int i = 0; i < v.size() - 1; i++) {
				int tmp = dist[get<2>(v[i])][get<0>(v[i + 1])][get<1>(v[i + 1])];
				if (tmp == -1) {
					ok = false;
					break;
				}
				dst += tmp;
			}

			if (ok && (ans == -1 || ans > dst)) {
				ans = dst;
			}
		} while (next_permutation(v.begin(), v.end()));
		
		cout << ans << '\n';
	}

	return 0;
}
