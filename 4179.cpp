#include <tuple>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int mat[1002][1002];
int dist[1002][1002];
int fdist[1002][1002];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int jx, jy;
	queue<pair<int, int>> fq;
	memset(dist, -1, sizeof(dist));
	memset(fdist, -1, sizeof(fdist));

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '#') {
				mat[i][j + 1] = -1;
			}
			else if (s[j] == 'F') {
				fq.push(make_pair(i, j + 1));
				fdist[i][j + 1] = 0;
			}
			else if (s[j] == 'J') {
				jx = i;
				jy = j + 1;
			}
		}
	}

	queue<pair<int, int>> nxt_fq;
	while (!fq.empty()) {
		int x, y;
		tie(x, y) = fq.front();
		fq.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 1 || ty < 1 || tx > n || ty > m || fdist[tx][ty] != -1 || mat[tx][ty] == -1) continue;
			fdist[tx][ty] = fdist[x][y] + 1;
			nxt_fq.push(make_pair(tx, ty));
		}

		if (fq.empty()) {
			fq = nxt_fq;
			nxt_fq = queue<pair<int, int>>();
		}
	}

	queue<pair<int, int>> q;
	q.push(make_pair(jx, jy));
	dist[jx][jy] = 0;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			if (tx < 0 || ty < 0 || tx > n + 1 || ty > m + 1 || mat[tx][ty] == -1 || dist[tx][ty] != -1 || (dist[x][y] + 1 >= fdist[tx][ty] && fdist[tx][ty] != -1)) continue;
			dist[tx][ty] = dist[x][y] + 1;
			q.push(make_pair(tx, ty));
		}
	}
	
	int ans = -1;
	for (int j = 0; j <= m + 1; j++) {
		if (ans == -1 || ans > dist[0][j]) {
			ans = dist[0][j];
		}
		if (ans == -1 || ans > dist[n + 1][j]) {
			ans = dist[n + 1][j];
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		if (ans == -1 || ans > dist[i][0]) {
			ans = dist[i][0];
		}
		if (ans == -1 || ans > dist[i][m + 1]) {
			ans = dist[i][m + 1];
		}
	}

	if (ans == -1) {
		cout << "IMPOSSIBLE\n";
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}
