#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, r;
int mat[300][300];

void rotate() {
	for (int k = 0; k < min(n, m) / 2; k++) {
		deque<int> dq;
		int sx, sy;
		sx = sy = k;
		int cnt = 0;
		for (int j = sy; j < sy + (m - (k * 2)); j++) {
			dq.push_back(mat[sx][j]);
			cnt += 1;
		}
		for (int i = sx + 1; i < sx + 1 + (n - 2) - k * 2; i++) {
			dq.push_back(mat[i][m - 1 - k]);
			cnt += 1;
		}
		for (int j = sy + (m - (k * 2)) - 1; j >= sy; j--) {
			dq.push_back(mat[n - k - 1][j]);
			cnt += 1;
		}
		for (int i = sx + (n - 2) - k * 2; i >= sx + 1; i--) {
			dq.push_back(mat[i][sy]);
			cnt += 1;
		}

		for (int i = 0; i < r%cnt; i++) {
			int val = dq.front();
			dq.pop_front();
			dq.push_back(val);
		}

		for (int j = sy; j < sy + (m - (k * 2)); j++) {
			mat[sx][j] = dq.front();
			dq.pop_front();
		}
		for (int i = sx + 1; i < sx + 1 + (n - 2) - k * 2; i++) {
			mat[i][m - 1 - k] = dq.front();
			dq.pop_front();
		}
		for (int j = sy + (m - (k * 2)) - 1; j >= sy; j--) {
			mat[n - k - 1][j] = dq.front();
			dq.pop_front();
		}
		for (int i = sx + (n - 2) - k * 2; i >= sx + 1; i--) {
			mat[i][sy] = dq.front();
			dq.pop_front();
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	rotate();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
