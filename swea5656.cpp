#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n, w, h;
int ans = -1;
vector<vector<int>> anstmp;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void destroy(int x, int y, vector<vector<int>> &mat, vector<vector<bool>> &check) {
	if (check[x][y] || mat[x][y] == 0) {
		return;
	}
	
	check[x][y] = true;
	int range = mat[x][y];
	mat[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= range - 1; j++) {
			int tx = x + j * dx[i];
			int ty = y + j * dy[i];
			if (tx < 0 || ty < 0 || tx > h - 1 || ty > w - 1) {
				break;
			}
			destroy(tx, ty, mat, check);
		}
	}

	return;
}

void move(vector<vector<int>>& mat) {
	for (int j = 0; j < w; j++) {
		for (int i = h - 1; i >= 0; i--) {
			if (mat[i][j] == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (mat[k][j] > 0) {
						mat[i][j] = mat[k][j];
						mat[k][j] = 0;
						break;
					}
				}
			}
		}
	}
	return;
}

void go(int ball, vector<vector<int>> &mat) {
	if (ball == n) {
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (mat[i][j] > 0) cnt += 1;
			}
		}
		if (ans == -1 || ans > cnt) {
			ans = cnt;
			anstmp = mat;
		}
		return;
	}

	for (int j = 0; j < w; j++) {
		for (int i = 0; i < h; i++) {
			if (mat[i][j] >= 1) {
				vector<vector<bool>> check(h, vector<bool>(w));
				vector<vector<int>> tmpmat(mat);
				destroy(i, j, tmpmat, check);
				move(tmpmat);
				go(ball + 1, tmpmat);
				break;
			}
		}
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		cin >> n >> w >> h;
		ans = -1;
		vector<vector<int>> mat(h, vector<int>(w));
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> mat[i][j];
			}
		}
		go(0, mat);
		if (ans == -1) ans = 0;
		cout << "#" << test_case << ' ' << ans << '\n';
	}

	return 0;
}
