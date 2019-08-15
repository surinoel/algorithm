#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

bool visit[12][6];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int val, int cnt, int mat[12][6], vector<pair<int,int>> &v) {
	for (int k = 0; k < 4; k++) {
		int tx = x + dx[k];
		int ty = y + dy[k];
		if (tx < 0 || ty < 0 || tx > 11 || ty > 5 || visit[tx][ty] || mat[tx][ty] != val) continue;
		visit[tx][ty] = true;
		v.push_back(make_pair(tx, ty));
		dfs(tx, ty, val, cnt + 1, mat, v);
	}
}

void pull(int mat[12][6]) {
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			int start = mat[i][j];
			if (start == 0) {
				for (int k = i - 1; k >= 0; k--) {
					if (mat[k][j] != 0) {
						mat[i][j] = mat[k][j];
						mat[k][j] = 0;
						break;
					}
				}
			}
		}
	}
}

int stage(int level, int mat[12][6]) {
	memset(visit, false, sizeof(visit));
	vector<vector<pair<int, int>>> v;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visit[i][j] == false && mat[i][j] != 0) {
				vector<pair<int, int>> tv;
				visit[i][j] = true;
				tv.push_back(make_pair(i, j));
				dfs(i, j, mat[i][j], 1, mat, tv);
				if (tv.size() >= 4) {
					v.push_back(tv);
				}
			}
		}
	}

	if (v.empty()) {
		return level;
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < v[i].size(); j++) {
				mat[v[i][j].first][v[i][j].second] = 0;
			}
		}
		pull(mat);
		return stage(level + 1, mat);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int mat[12][6];
	memset(mat, 0, sizeof(mat));
	int n, m;
	n = 12, m = 6;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'R') {
				mat[i][j] = 1;
			}
			else if (s[j] == 'G') {
				mat[i][j] = 2;
			}
			else if (s[j] == 'B') {
				mat[i][j] = 3;
			}
			else if (s[j] == 'P') {
				mat[i][j] = 4;
			}
			else if (s[j] == 'Y') {
				mat[i][j] = 5;
			}
		}
	}

	cout << stage(0, mat) << '\n';
	return 0;
}
