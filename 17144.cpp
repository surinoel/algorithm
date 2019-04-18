#include <queue>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

typedef struct __dust {
	int x, y;
	bool up, down, left, right;
	int cnt;
	__dust(int _x, int _y, bool _up, bool _down, bool _left, bool _right, int _cnt) :
		x(_x), y(_y), up(_up), down(_down), left(_left), right(_right), cnt(_cnt) {}
} dust;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dx1[4] = { -1, 0, 1, 0 };
int dy1[4] = { 0, 1, 0, -1 };
int dx2[4] = { 1, 0, -1, 0 };
int dy2[4] = { 0, 1, 0, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;
	queue<dust> d;
	vector<pair<int, int>> air;
	vector<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == -1) {
				air.push_back(make_pair(i, j));
			}
			else if (mat[i][j] > 0) {
				d.push(dust(i, j, false, false, false, false, 0));
			}
		}
	}
	
	int blockx1 = air[0].first;
	int idx = 0;
	int sx1 = air[0].first, sy1 = air[0].second;
	vector<pair<int, int>> ulist;
	while (true) {
		if (sx1 + dx1[idx] < 0 || sy1 + dy1[idx] < 0 || sx1 + dx1[idx] > blockx1 || sy1 + dy1[idx] > m - 1) {
			idx++;
			continue;
		}
		sx1 += dx1[idx];
		sy1 += dy1[idx];
		if (mat[sx1][sy1] == -1) {
			break;
		}
		ulist.push_back(make_pair(sx1, sy1));
		
	}

	int blockx2 = air[1].first;
	idx = 0;
	int sx2 = air[1].first, sy2 = air[1].second;
	vector<pair<int, int>> dlist;
	while (true) {
		if (sx2 + dx2[idx] > n - 1 || sy2 + dy2[idx] < 0 || sx2 + dx2[idx] < blockx2 || sy2 + dy2[idx] > m - 1) {
			idx++;
			continue;
		}
		sx2 += dx2[idx];
		sy2 += dy2[idx];
		if (mat[sx2][sy2] == -1) {
			break;
		}
		dlist.push_back(make_pair(sx2, sy2));
	}

	while (t--) {
		vector<vector<int>> tmat(n, vector<int>(m));
		tmat[air[0].first][air[0].second] = -1;
		tmat[air[1].first][air[1].second] = -1;
		while (!d.empty()) {
			int x, y;
			x = d.front().x;
			y = d.front().y;

			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
				if (mat[tx][ty] == -1) continue;
				if (k == 0) d.front().up = true;
				else if (k == 1) d.front().down = true;
				else if (k == 2) d.front().left = true;
				else if (k == 3) d.front().right = true;

				d.front().cnt += 1;
			}
			int ssize = mat[x][y] / 5;
			tmat[x][y] += (mat[x][y] - ssize * d.front().cnt);
			if (d.front().up) tmat[x + dx[0]][y + dy[0]] += ssize;
			if (d.front().down) tmat[x + dx[1]][y + dy[1]] += ssize;
			if (d.front().left) tmat[x + dx[2]][y + dy[2]] += ssize;
			if (d.front().right) tmat[x + dx[3]][y + dy[3]] += ssize;

			d.pop();
		}

		mat = tmat;
		deque<int> dq1;
		for (int i = 0; i<ulist.size(); i++) {
			dq1.push_back(mat[ulist[i].first][ulist[i].second]);
		}
		dq1.pop_front();
		dq1.push_back(0);

		for (int i = 0; i<ulist.size(); i++) {
			mat[ulist[i].first][ulist[i].second] = dq1[i];
		}

		deque<int> dq2;
		for (int i = 0; i<dlist.size(); i++) {
			dq2.push_back(mat[dlist[i].first][dlist[i].second]);
		}
		dq2.pop_front();
		dq2.push_back(0);

		for (int i = 0; i<dlist.size(); i++) {
			mat[dlist[i].first][dlist[i].second] = dq2[i];
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j] > 0) {
					d.push(dust(i, j, false, false, false, false, 0));
				}
			}
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] > 0) {
				ans += mat[i][j];
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
