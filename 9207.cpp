#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int n = 5, m = 9;
int mat[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0 ,0, 1, -1 };
int ans1 = -1, ans2 = -1;
int tcnt;

void go(int x, int y, int cnt) {
	if (ans1 == -1 || ans1 > cnt) {
		ans1 = cnt;
		ans2 = tcnt - cnt;
	}

	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] != 1) continue;
		int ttx = tx + dx[k];
		int tty = ty + dy[k];
		if (tty < 0 || tty < 0 || ttx > n - 1 || tty > m - 1 || mat[ttx][tty] != 0) continue;

		mat[x][y] = 0;
		mat[tx][ty] = 0;
		mat[ttx][tty] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					go(i, j, cnt - 1);
				}
			}
		}
		mat[x][y] = 1;
		mat[tx][ty] = 1;
		mat[ttx][tty] = 0;
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while(tc--) {
		ans1 = ans2 = -1;
		memset(mat, 0, sizeof(mat));
		int cnt = 0;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == '#') {
					mat[i][j] = -1;
				}
				else if (s[j] == 'o') {
					mat[i][j] = 1;
					cnt += 1;
				}
			}
		}

		tcnt = cnt;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					go(i, j, cnt);
				}
			}
		}
		cout << ans1 << ' ' << ans2 << '\n';
	}

	return 0;
}
