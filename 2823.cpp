#include <string>
#include <iostream>

using namespace std;

int mat[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'X') {
				mat[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == -1) continue;
			int cnt = 0;
			int x = i, y = j;
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];

				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == -1) {
					cnt += 1;
				}
			}
			if (cnt >= 3) {
				cout << 1 << '\n';
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}
