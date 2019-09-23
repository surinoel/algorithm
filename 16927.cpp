#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[300][300];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, r;
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	int tn, tm;
	tn = n, tm = m;
	int cnt = min(tn, tm) / 2;
	for (int i = 0; i < cnt; i++) {
		int x, y;
		x = y = i;
		deque<int> dq;
		int ssize = 0;
		for (int j = 0; j < tm - 1; j++) {
			dq.push_back(mat[x][y + j]);
			ssize += 1;
		}
		for (int j = 0; j < tn - 1; j++) {
			dq.push_back(mat[x + j][m - i - 1]);
			ssize += 1;
		}
		for (int j = tm - 1; j > 0; j--) {
			dq.push_back(mat[n - i - 1][y + j]);
			ssize += 1;
		}
		for (int j = tn - 1; j > 0; j--) {
			dq.push_back(mat[x + j][y]);
			ssize += 1;
		}
		
		for (int j = 0; j < r%ssize; j++) {
			int val = dq.front();
			dq.pop_front();
			dq.push_back(val);
		}
		
		for (int j = 0; j < tm - 1; j++) {
			mat[x][y + j] = dq.front();
			dq.pop_front();
		}
		for (int j = 0; j < tn - 1; j++) {
			mat[x + j][m - i - 1] = dq.front();
			dq.pop_front();
		}
		for (int j = tm - 1; j > 0; j--) {
			mat[n - i - 1][y + j] = dq.front();
			dq.pop_front();
		}
		for (int j = tn - 1; j > 0; j--) {
			mat[x + j][y] = dq.front();
			dq.pop_front();
		}
		
		tn -= 2, tm -= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	
	return 0;
}
