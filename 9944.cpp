#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int n, m;
int area;
int ans;
int mat[30][30];
bool visit[30][30];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void go(int x, int y, int d, int cnt, int stage) {
	if (cnt == area) {
		if (ans == -1 || ans > stage) {
			ans = stage;
		}
		return;
	}

	if (ans != -1 && stage > ans) return;

	int tx = x + dx[d];
	int ty = y + dy[d];
	if (tx >= 0 && ty >= 0 && tx <= n - 1 && ty <= m - 1 && visit[tx][ty] == false && mat[tx][ty] == 0) {
		visit[tx][ty] = true;
		go(tx, ty, d, cnt + 1, stage);
		visit[tx][ty] = false;
	}
	else {
		for (int k = 0; k < 4; k++) {
			if (k == d) continue;
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx <= n - 1 && ny <= m - 1 && visit[nx][ny] == false && mat[nx][ny] == 0) {
				visit[nx][ny] = true;
				go(nx, ny, k, cnt + 1, stage + 1);
				visit[nx][ny] = false;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tc = 1;
	while (cin >> n >> m) {
		ans = -1;
		area = 0;
		memset(mat, 0, sizeof(mat));
		memset(visit, 0, sizeof(visit));
		vector<pair<int, int>> dot;

		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			for (int j = 0; j < s.size(); j++) {
				if (s[j] == '.') {
					area += 1;
					dot.push_back(make_pair(i, j));
				}
				else {
					mat[i][j] = -1;
				}
			}
		}

		if (area == 1) {
			ans = 0;
		}
		else {
			for (int i = 0; i < dot.size(); i++) {
				int x = dot[i].first;
				int y = dot[i].second;
				for (int k = 0; k < 4; k++) {
					visit[x][y] = true;
					go(x, y, k, 1, 1);
					visit[x][y] = false;
				}
			}
		}

		cout << "Case " << tc++ << ": " << ans << '\n';
	}
	return 0;
}
