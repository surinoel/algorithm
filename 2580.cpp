#include <iostream>
#include <vector>

using namespace std;

int mat[9][9];
bool is_end = false;

bool check(int x, int y, int val) {
	for (int j = 0; j < 9; j++) {
		if (j == y) continue;
		if (mat[x][j] == val) {
			return false;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (i == x) continue;
		if (mat[i][y] == val) {
			return false;
		}
	}

	int grpx, grpy;
	grpx = x / 3;
	grpy = y / 3;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i / 3 == grpx && j / 3 == grpy) {
				if (i == x && j == y) continue;
				if (mat[i][j] == val) {
					return false;
				}
			}
		}
	}
	return true;
}

void go(int idx, vector<pair<int, int>> &v) {
	if (idx == v.size()) {
		is_end = true;
		return;
	}

	for (int k = 1; k <= 9; k++) {
		if (!check(v[idx].first, v[idx].second, k)) continue;
		mat[v[idx].first][v[idx].second] = k;
		go(idx + 1, v);
		if (is_end) {
			return;
		}
		mat[v[idx].first][v[idx].second] = 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> v;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	go(0, v);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << mat[i][j] << ' ';
		}
		cout << '\n';
	}
	
	return 0;
}