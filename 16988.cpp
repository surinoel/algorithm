#include <queue>
#include <vector>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

int n, m;
int mat[20][20];
int check[20][20][20][20];

int group[20][20];
int group_size[20 * 20 + 1];

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

	int ans = 0;
	for (int u1 = 0; u1 < n; u1++) {
		for (int v1 = 0; v1 < m; v1++) {
			if (mat[u1][v1] != 0) continue;
			for (int u2 = 0; u2 < n; u2++) {
				for (int v2 = 0; v2 < m; v2++) {
					if (mat[u2][v2] != 0) continue;
					if (u1 == u2 && v1 == v2) continue;
					if (check[u1][v1][u2][v2] || check[u2][v2][u1][v1]) continue;
					check[u1][v1][u2][v2] = check[u2][v2][u1][v1] = true;

					int tmat[20][20];
					for (int i = 0; i < 20; i++) {
						for (int j = 0; j < 20; j++) {
							tmat[i][j] = mat[i][j];
						}
					}
					tmat[u1][v1] = tmat[u2][v2] = 1;
					
					int tsum = 0;
					int group_num = 0;
					memset(group, 0, sizeof(group));
					memset(group_size, 0, sizeof(group_size));
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < m; j++) {
							if (tmat[i][j] == 2 && group[i][j] == 0) {
								
								group[i][j] = ++group_num;
								queue<pair<int, int>> q;
								q.push(make_pair(i, j));
								group_size[group_num] = 1;
								bool ok = true;
								while (!q.empty()) {
									int x, y;
									x = q.front().first;
									y = q.front().second;
									q.pop();

									for (int k = 0; k < 4; k++) {
										int tx = x + dx[k];
										int ty = y + dy[k];

										if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || tmat[tx][ty] == 1 || group[tx][ty] != 0) continue;
										if (tmat[tx][ty] == 0) {
											
											ok = false;
										}
										group[tx][ty] = group_num;
										group_size[group_num] += 1;
										q.push(make_pair(tx, ty));
									}
								}
								if (ok) {
									tsum += group_size[group_num];
								}
							}
						}
					}
					if (tsum > ans) {
						ans = tsum;
					}
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
