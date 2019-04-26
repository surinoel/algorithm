#include <queue>
#include <tuple>
#include <vector>
#include <iostream>

using namespace std;

int mat[500][500];
int group[500][500];
int group_size[250001];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int group_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 0 || group[i][j] != 0) continue;
			group[i][j] = ++group_num;
			group_size[group[i][j]] = 1;
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));

			while (!q.empty()) {
				int x, y;
				tie(x, y) = q.front();
				q.pop();

				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];

					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 0 || group[tx][ty] != 0) continue;
					group[tx][ty] = group_num;
					group_size[group[tx][ty]] += 1;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}

	cout << group_num << '\n';
	int ans = 0;
	for (int i = 1; i <= group_num; i++) {
		if (group_size[i] > ans) {
			ans = group_size[i];
		}
	}

	cout << ans << '\n';
	return 0;
}
