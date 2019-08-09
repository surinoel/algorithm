#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { 1, 0, -1, 0 };
int mat[101][101];
int ans = 0;

void go(int x, int y, int clevel, int level, vector<int>& dir) {
	if (clevel > level) {
		return;
	}

	int nx, ny;
	nx = x, ny = y;
	vector<int> ndir = dir;
	for (int i = dir.size() - 1; i >= 0; i--) {
		int d = dir[i];
		if (--d == -1) d = 3;
		if (d == 0) d = 2;
		else if (d == 1) d = 3;
		else if (d == 2) d = 0;
		else if (d == 3) d = 1;
		ndir.push_back(d);
		nx += dx[d];
		ny += dy[d];
		mat[nx][ny] = 1;
	}
	go(nx, ny, clevel + 1, level, ndir);
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> y >> x >> d >> g;
		mat[x][y] = 1;
		int nx, ny;
		vector<int> dir;
		nx = x + dx[d]; 
		ny = y + dy[d];
		mat[nx][ny] = 1;
		dir.push_back(d);
		go(nx, ny, 1, g, dir);
	}

	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			bool ok = true;
			if (mat[i][j] != 1) ok = false;
			if (mat[i + 1][j] != 1) ok = false;
			if (mat[i][j + 1] != 1) ok = false;
			if (mat[i + 1][j + 1] != 1) ok = false;
			if (ok) ans += 1;
		}
	}
	
	cout << ans << '\n';
	return 0;
}
