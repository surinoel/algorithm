#include <queue>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

int mat[50][50];
int group[50][50];

int dx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[8] = { 1, 0, -1, 1, -1, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true) {
		int n, m;
		cin >> m >> n;
		if (m == 0 && n == 0) break;

		memset(mat, 0, sizeof(mat));
		memset(group, 0, sizeof(group));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}

		int group_num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1 && group[i][j] == 0) {
					group[i][j] = ++group_num;
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));

					while (!q.empty()) {
						int x, y;
						tie(x, y) = q.front();
						q.pop();

						for (int k = 0; k < 8; k++) {
							int tx = x + dx[k];
							int ty = y + dy[k];

							if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 0 || group[tx][ty] != 0) continue;
							group[tx][ty] = group_num;
							q.push(make_pair(tx, ty));
						}
					}
				}
			}
		}

		cout << group_num << '\n';
	}

	return 0;
}
