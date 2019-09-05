#include <queue>
#include <deque>
#include <tuple>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

char mat[102][102];
bool visit[102][102];
bool key[26];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(visit, false, sizeof(visit));
		memset(key, false, sizeof(key));
		
		int n, m;
		cin >> n >> m;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				mat[i][j] = '.';
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> mat[i][j];
			}
		}

		string s;
		cin >> s;
		if (s != "0") {
			for (int i = 0; i < s.size(); i++) {
				key[s[i] - 'a'] = true;
			}
		}

		queue<pair<int, int>> door[26];
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		visit[0][0] = true;

		int ans = 0;
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];

				if (tx < 0 || ty < 0 || tx > n + 1 || ty > m + 1 || visit[tx][ty] || mat[tx][ty] == '*') continue;
				visit[tx][ty] = true;
				if (mat[tx][ty] == '.') {
					q.push(make_pair(tx, ty));
				}
				else if (mat[tx][ty] == '$') {
					ans += 1;
					q.push(make_pair(tx, ty));
				}
				else if (mat[tx][ty] >= 'A' && mat[tx][ty] <= 'Z') {
					if (key[mat[tx][ty] - 'A']) {
						q.push(make_pair(tx, ty));
					}
					else {
						door[mat[tx][ty]-'A'].push(make_pair(tx, ty));
					}
				}
				else if (mat[tx][ty] >= 'a' && mat[tx][ty] <= 'z') {
					q.push(make_pair(tx, ty));
					if (!key[mat[tx][ty] - 'a']) {
						key[mat[tx][ty] - 'a'] = true;
						while (!door[mat[tx][ty]-'a'].empty()) {
							q.push(make_pair(door[mat[tx][ty] - 'a'].front().first, door[mat[tx][ty] - 'a'].front().second));
							door[mat[tx][ty] - 'a'].pop();
						}
					}
				}
			}
		}

		cout << ans << '\n';
	}
	return 0;
}
