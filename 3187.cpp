#include <tuple>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

int mat[250][250];
bool visit[250][250];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#') {
				mat[i][j] = -1;
			}
			else if (s[j] == 'v') {
				mat[i][j] = 1;
			}
			else if (s[j] == 'k') {
				mat[i][j] = 2;
			}
		}
	}

	int a1 = 0, a2 = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == true || mat[i][j] == -1) continue;
			int ta1 = 0, ta2 = 0;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			visit[i][j] = true;
			if (mat[i][j] == 2) ta1 += 1;
			else if (mat[i][j] == 1) ta2 += 1;

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == -1 || visit[tx][ty] == true) continue;
					if (mat[tx][ty] == 2) ta1 += 1;
					else if (mat[tx][ty] == 1) ta2 += 1;
					visit[tx][ty] = true;
					q.push(make_pair(tx, ty));
				}
			}

			if (ta1 > ta2) {
				a1 += ta1;
			}
			else {
				a2 += ta2;
			}
		}
	}

	cout << a1 << ' ' << a2 << '\n';
	return 0;
}
