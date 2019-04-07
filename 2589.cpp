#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int mat[50][50];
int dist[50][50];
int group[50][50];
int group_size[2500];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'L') {
				mat[i][j] = 1;
			}
		}
	}
	memset(group, -1, sizeof(group));
	int group_num = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] != -1 || mat[i][j] == 0) continue;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			int size = 1;
			group[i][j] = ++group_num;

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
					if (mat[tx][ty] == 0 || group[tx][ty] != -1) continue;
					group[tx][ty] = group_num;
					size++;
					q.push(make_pair(tx, ty));
				}
			}
			group_size[group_num] = size;
		}
	}
	int ssize = -1;
	int idx;
	for (int i = 0; i <= group_num; i++) {
		if (group_size[i] > ssize) {
			idx = i;
			ssize = group_size[i];
		}
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (group[i][j] != idx) continue;
			memset(dist, -1, sizeof(dist));
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			dist[i][j] = 0;
			int tmp = dist[i][j];

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
					if (dist[tx][ty] != -1 || mat[tx][ty] == 0) continue;
					dist[tx][ty] = dist[x][y] + 1;
					tmp = dist[tx][ty];
					q.push(make_pair(tx, ty));
				}
			}
			ans = max(ans, tmp);
		}
	}

	cout << ans << '\n';
	return 0;
}