#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int mat[1000][1000];
int group[1000][1000];
int group_size[1000001];
int ans[1000][1000];

int main(void) {
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}

	int group_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 || group[i][j] > 0) continue;
			group_num++;
			
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			group[i][j] = group_num;
			group_size[group_num] = 1;

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
					if (mat[tx][ty] == 1 || group[tx][ty] > 0) continue;
					group[tx][ty] = group_num;
					group_size[group_num] += 1;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0) continue;
			vector<int> sub;
			ans[i][j] = 1;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x < 0 || y < 0 || x > n - 1 || y > m - 1) continue;
				if (mat[x][y] == 1) continue;
				sub.push_back(group[x][y]);
			}

			sort(sub.begin(), sub.end());
			sub.erase(unique(sub.begin(), sub.end()), sub.end());
			for (auto it = sub.begin(); it != sub.end(); ++it) {
				if (*it == 0) continue;
				ans[i][j] += group_size[*it];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] % 10;
		}
		cout << '\n';
	}

	return 0;
}
