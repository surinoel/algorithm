#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct __wall {
	bool up, down, left, right;
	__wall() { up = down = left = right = false; }
	__wall(bool _up, bool _down, bool _left, bool _right) : up(_up), down(_down), left(_left), right(_right) {}
} wall;

wall mat[50][50];
int group[50][50];
int group_size[2501];
bool visit[50][50];
bool group_check[2501];

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x; cin >> x;
			bool up, down, left, right;
			up = down = left = right = false;
			for (int k = 0; k < 4; k++) {
				if (x & (1 << k)) {
					if (k == 0) left = true;
					else if (k == 1) up = true;
					else if (k == 2) right = true;
					else down = true;
				}
			}
			mat[i][j] = wall(up, down, left, right);
		}
	}
	
	int group_num = 0;
	int max_group_size = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group[i][j] != 0) continue;
			group[i][j] = ++group_num;
			group_size[group_num] = 1;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || group[tx][ty] != 0) continue;
					if (k == 0) {
						if (mat[x][y].left) continue;
					}
					else if (k == 1) {
						if (mat[x][y].up) continue;
					}
					else if (k == 2) {
						if (mat[x][y].right) continue;
					}
					else {
						if (mat[x][y].down) continue;
					}
					q.push(make_pair(tx, ty));
					group[tx][ty] = group_num;
					group_size[group_num] += 1;
				}
			}
			if (max_group_size == -1 || group_size[group_num] > max_group_size) {
				max_group_size = group_size[group_num];
			}
		}
	}

	cout << group_num << '\n';
	cout << max_group_size << '\n';

	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (group_check[group[i][j]]) continue;
			memset(visit, false, sizeof(visit));

			visit[i][j] = true;
			int gnum = group[i][j];
			int gsize = group_size[group[i][j]];
			group_check[gnum] = true;

			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			vector<int> sub;

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || visit[tx][ty] == true) continue;
					visit[tx][ty] = true;
					if (group[x][y] != group[tx][ty]) {
						sub.push_back(group[tx][ty]);
					}
					else {
						q.push(make_pair(tx, ty));
					}
				}
			}

			if (!sub.empty()) {
				sort(sub.begin(), sub.end());
				sub.erase(unique(sub.begin(), sub.end()), sub.end());
				for (int k = 0; k < sub.size(); k++) {
					if (gsize + group_size[sub[k]] > ans) {
						ans = gsize + group_size[sub[k]];
					}
				}
			}
		
		}
	}

	cout << ans << '\n';
	return 0;
}
