#include <queue>
#include <tuple>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int mat[50][50];
bool matopen[50][50][4];
int group[50][50];
int group_size[50 * 50 + 1];
int group_sum[50 * 50 + 1];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, L, R;
	cin >> n >> L >> R;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	int day;
	for (int date = 0;; date++) {
		day = date;
		memset(matopen, false, sizeof(matopen));
		memset(group, -1, sizeof(group));
		memset(group_size, 0, sizeof(group_size));
		memset(group_sum, 0, sizeof(group_sum));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = i, y = j;
				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k];
					int ty = y + dy[k];
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
					int diff = abs(mat[i][j] - mat[tx][ty]);
					if (diff >= L && diff <= R) {
						matopen[x][y][k] = 1;
					}
				}
			}
		}

		bool ok = false;
		int group_num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (group[i][j] == -1) {
					queue<pair<int, int>> q;
					q.push(make_pair(i, j));
					group[i][j] = ++group_num;
					group_size[group_num] = 1;
					group_sum[group_num] = mat[i][j];

					while (!q.empty()) {
						int x, y;
						tie(x, y) = q.front();
						q.pop();

						for (int k = 0; k < 4; k++) {
							int tx = x + dx[k];
							int ty = y + dy[k];

							if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || group[tx][ty] != -1) continue;
							if (matopen[x][y][k]) {
								group[tx][ty] = group_num;
								group_size[group_num] += 1;
								group_sum[group_num] += mat[tx][ty];
								q.push(make_pair(tx, ty));
								ok = true;
							}
						}
					}
				}
			}
		}

		if (!ok) {
			break;
		}

		for (int i = 1; i <= group_num; i++) {
			group_sum[i] = group_sum[i] / group_size[i];
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = group_sum[group[i][j]];
			}
		}
	}

	cout << day << '\n';
	return 0;
}
