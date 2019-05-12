#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int mat[100][100];
int group[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	int cheeze = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			cheeze += mat[i][j];
		}
	}

	int tc = 0;
	while (cheeze > 0) {
		int group_num = -1;
		memset(group, 0, sizeof(group));
		group[0][0] = group_num;
		queue<pair<int, int>> q;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty >m - 1 || group[tx][ty] != 0 || mat[tx][ty] == 1) continue;
				group[tx][ty] = group_num;
				q.push(make_pair(tx, ty));
			}
		}

		vector<pair<int, int>> edge;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					int cnt = 0;
					for (int k = 0; k < 4; k++) {
						int tx = i + dx[k];
						int ty = j + dy[k];
						if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
						if (mat[tx][ty] == 0 && group[tx][ty] == -1) cnt += 1;
					}
					if (cnt >= 2) {
						edge.push_back(make_pair(i, j));
						cheeze -= 1;
					}
				}
			}
		}

		for (int i = 0; i < edge.size(); i++) {
			mat[edge[i].first][edge[i].second] = 0;
		}

		tc += 1;
	}

	cout << tc << '\n';
	return 0;
}
