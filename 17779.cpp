#include <cmath>
#include <queue>
#include <tuple>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[21][21];
int group[21][21];
bool visit[21][21];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int sum[5];

void bfs(int reg, int n, int a, int b, int c, int d) {
	int x, y;
	if (reg == 0) { x = 1, y = 1; }
	else if (reg == 1) { x = 1, y = n; }
	else if (reg == 2) { x = n, y = 1; }
	else if (reg == 3) { x = n, y = n; }

	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	sum[reg] = mat[x][y];
	group[x][y] = reg;

	while (!q.empty()) {
		int tx, ty;
		tie(tx, ty) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ttx = tx + dx[k];
			int tty = ty + dy[k];

			if (ttx >= a && ttx <= b && tty >= c && tty <= d && group[ttx][tty] == -1) {
				group[ttx][tty] = reg;
				visit[ttx][tty] = true;
				sum[reg] += mat[ttx][tty];
				q.push(make_pair(ttx, tty));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int tsum = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			tsum += mat[i][j];
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i == 1 && j == 1) || (i == 1 && j == n)
				|| (i == n && j == 1) || (i == n && j == n)) continue;
			for (int d1 = 1; d1 <= n; d1++) {
				for (int d2 = 1; d2 <= n; d2++) {
					if (i + d1 > n || j - d1 < 1) continue;
					if (i + d2 > n || j + d2 > n) continue;
					if (i + d1 + d2 > n || j - d1 + d2 < 1 || j - d1 + d2 > n) continue;
					if (i + d1 + d2 > n || j + d2 - d1 < 1 || j + d2 - d1 > n) continue;
				
					memset(group, -1, sizeof(group));
					for (int b = 0; b <= d1; b++) {
						group[i + b][j - b] = 5;
						group[i + d2 + b][j + d2 - b] = 5;
					}
					for (int b = 0; b <= d2; b++) {
						group[i + b][j + b] = 5;
						group[i + d1 + b][j - d1 + b] = 5;
					}

					bfs(0, n, 1, i + d1 - 1, 1, j);
					bfs(1, n, 1, i + d2, j - 1, n);
					bfs(2, n, i + d1, n, 1, j - d1 + d2 - 1);
					bfs(3, n, i + d2 - 1, n, j - d1 + d2, n);
					
					sum[4] = tsum - sum[0] - sum[1] - sum[2] - sum[3];

					sort(sum, sum + 5);
					if (ans == -1 || ans > sum[4] - sum[0]) {
						ans = sum[4] - sum[0];
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
