#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int n, m, h;
int ans = -1;

bool check(vector<vector<int>> &v) {
	for (int i = 1; i <= n; i++) {
		int pos = i;
		for (int j = 1; j <= h; j++) {
			if (pos < n && v[j][pos] == 1) {
				pos = pos + 1;
			}
			else if (pos > 1 && v[j][pos - 1] == 1) {
				pos = pos - 1;
			}
		}
		if (pos != i) {
			return false;
		}
	}

	return true;
}

void go(int cnt, int sero, int high, vector<vector<int>> &v) {
	if (cnt == 3) {
		return;
	}

	for (int i = sero; i <= n - 1; i++) {
		if (v[high][i] == 0) {
			v[high][i] = 1;
			if (check(v)) {
				if (ans == -1 || cnt + 1 < ans) {
					ans = cnt + 1;
				}
			}
			go(cnt + 1, i, high, v);
			v[high][i] = 0;
		}
	}

	for (int i = high + 1; i <= h; i++) {
		for (int j = 1; j <= n - 1; j++) {
			if (v[i][j] == 0) {
				v[i][j] = 1;
				if (check(v)) {
					if (ans == -1 || cnt + 1 < ans) {
						ans = cnt + 1;
					}
				}
				go(cnt + 1, j, i, v);
				v[i][j] = 0;
			}
		}
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> h;
	vector<vector<int>> mat(h + 1, vector<int>(n + 1));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		mat[x][y] = 1;
	}
	
	if (check(mat)) {
		cout << 0 << '\n';
		return 0;
	}

	go(0, 1, 1, mat);
	cout << ans << '\n';
	
	return 0;
}
