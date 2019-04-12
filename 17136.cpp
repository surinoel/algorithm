#include <iostream>
#include <vector>

using namespace std;

int ans = -1;

bool checkmat(vector<vector<int>> &mat) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (mat[i][j] == 1) return false;
		}
	}
	return true;
}

void go(int idx, int m1, int m2, int m3, int m4, int m5, vector<vector<int>> &mat) {
	if (idx == 100) {
		if (checkmat(mat)) {
			if (ans == -1 || ans > m1 + m2 + m3 + m4 + m5) {
				ans = m1 + m2 + m3 + m4 + m5;
			}
		}
		return;
	}
	if ((ans != -1 && m1 + m2 + m3 + m4 + m5 >= ans) || (m1 == 5 && m2 == 5 && m3 == 5 && m4 == 5 && m5 == 5)) {
		return;
	}

	int n = 10;
	int x = idx / 10;
	int y = idx % 10;
	if (mat[x][y] == 0) {
		go(idx + 1, m1, m2, m3, m4, m5, mat);
	}
	else {
		if (m5 < 5) {
			vector<vector<int>> tmp(mat);
			int tx = x + 4;
			int ty = y + 4;
			if (tx < n && ty < n) {
				bool ok = true;
				for (int i = x; i <= x + 4; i++) {
					for (int j = y; j <= y + 4; j++) {
						if (tmp[i][j] == 0) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					for (int i = x; i <= x + 4; i++) {
						for (int j = y; j <= y + 4; j++) {
							tmp[i][j] = 0;
						}
					}
					go(idx + 1, m1, m2, m3, m4, m5 + 1, tmp);
				}
			}
		}
        if (m4 < 5) {
			vector<vector<int>> tmp(mat);
			int tx = x + 3;
			int ty = y + 3;
			if (tx < n && ty < n) {
				bool ok = true;
				for (int i = x; i <= x + 3; i++) {
					for (int j = y; j <= y + 3; j++) {
						if (tmp[i][j] == 0) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					for (int i = x; i <= x + 3; i++) {
						for (int j = y; j <= y + 3; j++) {
							tmp[i][j] = 0;
						}
					}
					go(idx + 1, m1, m2, m3, m4 + 1, m5, tmp);
				}
			}
		}
         if (m3 < 5) {
			vector<vector<int>> tmp(mat);
			int tx = x + 2;
			int ty = y + 2;
			if (tx < n && ty < n) {
				bool ok = true;
				for (int i = x; i <= x + 2; i++) {
					for (int j = y; j <= y + 2; j++) {
						if (tmp[i][j] == 0) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					for (int i = x; i <= x + 2; i++) {
						for (int j = y; j <= y + 2; j++) {
							tmp[i][j] = 0;
						}
					}
					go(idx + 1, m1, m2, m3 + 1, m4, m5, tmp);
				}
			}
		}
        if (m2 < 5) {
			vector<vector<int>> tmp(mat);
			int tx = x + 1;
			int ty = y + 1;
			if (tx < n && ty < n) {
				bool ok = true;
				for (int i = x; i <= x + 1; i++) {
					for (int j = y; j <= y + 1; j++) {
						if (tmp[i][j] == 0) {
							ok = false;
							break;
						}
					}
				}
				if (ok) {
					for (int i = x; i <= x + 1; i++) {
						for (int j = y; j <= y + 1; j++) {
							tmp[i][j] = 0;
						}
					}
					go(idx + 1, m1, m2 + 1, m3, m4, m5, tmp);
				}
			}
		}
        if (m1 < 5) {
			vector<vector<int>> tmp(mat);
			int tx = x;
			int ty = y;
			tmp[tx][ty] = 0;
			go(idx + 1, m1 + 1, m2, m3, m4, m5, tmp);
		}
	}
	
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> mat(10, vector<int>(10));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> mat[i][j];
		}
	}

	go(0, 0, 0, 0, 0, 0, mat);
	cout << ans << '\n';
	return 0;
}
