#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
bool check[20][20][20][20];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int ans = 0;
	for (int x1 = 0; x1 < n; x1++) {
		for (int y1 = 0; y1 < m; y1++) {
			if (mat[x1][y1] != 0) continue;
			for (int x2 = 0; x2 < n; x2++) {
				for (int y2 = 0; y2 < m; y2++) {
					if (mat[x2][y2] != 0 || (x1 == x2 && y1 == y2)) continue;
					if (check[x1][y1][x2][y2] || check[x2][y2][x1][y1]) continue;
					check[x1][y1][x2][y2] = true;
					check[x2][y2][x1][y1] = true;

					vector<vector<int>> tmp(mat);
					vector<vector<int>> group(n, vector<int>(m, -1));
					tmp[x1][y1] = tmp[x2][y2] = 1;

					int group_num = 0;
					int sum = 0;
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (mat[i][j] != 2 || group[i][j] != -1) continue;
							queue<pair<int, int>> q;
							int group_size = 0;
							bool ok = true;
							q.push(make_pair(i, j));
							group[i][j] = group_num;
							group_size++;

							while (!q.empty()) {
								int x, y;
								tie(x, y) = q.front();
								q.pop();

								for (int k = 0; k < 4; k++) {
									int tx = x + dx[k];
									int ty = y + dy[k];
									if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
									if (tmp[tx][ty] == 1 || group[tx][ty] != -1) continue;
									if (tmp[tx][ty] == 0) {					
										ok = false;
										continue;
									}
									group[tx][ty] = group_num;
									group_size++;
									q.push(make_pair(tx, ty));
								}
							}


							if (ok) {
								sum += group_size;
							}

							group_num++;
						}
					}
					if (sum > ans) {
						ans = sum;
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
