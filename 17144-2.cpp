#include <tuple>
#include <deque>
#include <queue>
#include <iostream>

using namespace std;

int mat[50][50];
int tmat[50][50];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;
	vector<pair<int, int>> airfresh;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == -1) {
				airfresh.push_back(make_pair(i, j));
			}
		}
	}

	vector<pair<int, int>> airfresh_locate1, airfresh_locate2;
	int sx = airfresh[0].first, sy = airfresh[0].second;
	int dir = 1;
	while (1) {
		if (mat[sx + dx[dir]][sy + dy[dir]] == -1) {
			break;
		}
		if (sx + dx[dir] < 0 || sy + dy[dir] < 0 || sx + dx[dir] > airfresh[0].first || sy + dy[dir] > m - 1) {
			if (dir == 1) dir = 2;
			else if (dir == 2) dir = 0;
			else if (dir == 0) dir = 3;
		}
		else {
			sx += dx[dir];
			sy += dy[dir];
			airfresh_locate1.push_back(make_pair(sx, sy));
		}
	}
	
	sx = airfresh[1].first, sy = airfresh[1].second;
	dir = 0;
	while (1) {
		if (mat[sx + dx[dir]][sy + dy[dir]] == -1) {
			break;
		}
		if (sx + dx[dir] < airfresh[1].first || sy + dy[dir] < 0 || sx + dx[dir] > n - 1 || sy + dy[dir] > m - 1) {
			if (dir == 0) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 1) dir = 3;
		}
		else {
			sx += dx[dir];
			sy += dy[dir];
			airfresh_locate2.push_back(make_pair(sx, sy));
		}
	}

	for (int time = 1; time <= t; time++) {
		memcpy(tmat, mat, sizeof(tmat));
		memset(mat, 0, sizeof(mat));
		mat[airfresh[0].first][airfresh[0].second] = -1;
		mat[airfresh[1].first][airfresh[1].second] = -1;

		vector<pair<int, int>> dust;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (tmat[i][j] > 0) {
					dust.push_back(make_pair(i, j));
				}
			}
		}
		for (int i = 0; i < dust.size(); i++) {
			int x, y;
			x = dust[i].first;
			y = dust[i].second;
			int dircnt = 0;
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || tmat[tx][ty] == -1) continue;
				dircnt += 1;
			}
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[j];
				int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || tmat[tx][ty] == -1) continue;
				mat[tx][ty] += tmat[x][y] / 5;
			}
			mat[x][y] += (tmat[x][y] - (tmat[x][y] / 5) * dircnt);
		}
		
		deque<int> dq1, dq2;
		for (int i = 0; i < airfresh_locate1.size(); i++) {
			dq1.push_back(mat[airfresh_locate1[i].first][airfresh_locate1[i].second]);
		}
		dq1.pop_front();
		dq1.push_back(0);
		for (int i = 0; i < dq1.size(); i++) {
			mat[airfresh_locate1[i].first][airfresh_locate1[i].second] = dq1[i];
		}

		for (int i = 0; i < airfresh_locate2.size(); i++) {
			dq2.push_back(mat[airfresh_locate2[i].first][airfresh_locate2[i].second]);
		}
		dq2.pop_front();
		dq2.push_back(0);
		for (int i = 0; i < dq2.size(); i++) {
			mat[airfresh_locate2[i].first][airfresh_locate2[i].second] = dq2[i];
		}
	}

	int ans = 0;
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
