#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat(n, vector<int>(m));
	vector<vector<int>> d(n, vector<int>(m, -1));
	int sx, sy;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'R') {
				sx = i;
				sy = j;
			}
			else if (s[j] == 'C') {
				mat[i][j] = 1;
			}
			else if (s[j] == 'O') {
				mat[i][j] = 2;
			}
			else if (s[j] == '#') {
				mat[i][j] = -1;
			}
		}
	}

	int ans = -1;
	d[sx][sy] = 0;
	for (int j = sy + 1; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (mat[i][j] == -1) continue;
	
			if (i - 1 >= 0) {
				if (d[i - 1][j - 1] != -1) {
					if (mat[i][j] == 1) {
						d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
					}
					else {
						d[i][j] = max(d[i][j], d[i - 1][j - 1]);
					}
				}
			}
			if (i + 1 < n) {
				if (d[i + 1][j - 1] != -1) {
					if (mat[i][j] == 1) {
						d[i][j] = max(d[i][j], d[i + 1][j - 1] + 1);
					}
					else {
						d[i][j] = max(d[i][j], d[i + 1][j - 1]);
					}
				}
			}
			if (d[i][j - 1] != -1) {
				if (mat[i][j] == 1) {
					d[i][j] = max(d[i][j], d[i][j - 1] + 1);
					d[i][j] = max(d[i][j], 1);
				}
				else {
					d[i][j] = max(d[i][j], d[i][j - 1]);
				}
			}

			if (mat[i][j] == 2) {
				if (d[i][j] > ans) {
					ans = d[i][j];
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}