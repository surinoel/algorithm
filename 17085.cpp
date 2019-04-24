#include <vector>
#include <string>
#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '.') {
				mat[i][j] = -1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] != 0) continue;
			vector<vector<int>> tmat(mat);

			int x = i;
			int y = j;
			int area1 = 1;
			int len1 = 1;
			tmat[x][y] = 1;
			while (true) {
				bool ok = true;
				for (int k = 0; k < 4; k++) {
					int tx = x + dx[k] * len1;
					int ty = y + dy[k] * len1;
					if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || tmat[tx][ty] != 0) {
						ok = false;
						break;
					}
				}
				if (!ok) break;
				for (int k = 0; k < 4; k++) {
					tmat[x + dx[k] * len1][y + dy[k] * len1] = 1;
				}
				area1 += 4;
				len1 += 1;
			}

			for (int u = 0; u < n; u++) {
				for (int v = 0; v < m; v++) {
					if (tmat[u][v] != 0) continue;
					vector<vector<int>> ttmat(tmat);

					int x = u;
					int y = v;
					int area2 = 1;
					int len2 = 1;
					ttmat[x][y] = 2;
					while (true) {
						bool ok = true;
						for (int k = 0; k < 4; k++) {
							int tx = x + dx[k] * len2;
							int ty = y + dy[k] * len2;
							if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || ttmat[tx][ty] != 0) {
								ok = false;
								break;
							}
						}
						if (!ok) break;
						for (int k = 0; k < 4; k++) {
							ttmat[x + dx[k] * len2][y + dy[k] * len2] = 2;
						}
						area2 += 4;
						len2 += 1;
					}

					if (area1 * area2 > ans) {
						ans = area1 * area2;
					}
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
