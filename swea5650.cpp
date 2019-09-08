#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int mat[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int block[6][4] = {
	{ 0, 0, 0, 0 },
	{ 2, 0, 3, 1 },
	{ 1, 2, 3, 0 },
	{ 1, 3, 0, 2 },
	{ 3, 0, 1, 2 },
	{ 1, 0, 3, 2 }
};

int n;
int ans;
int sx, sy;
vector<pair<int, int>> hole[11];

void go(int dir, int x, int y, int score) {
	int tx = x + dx[dir];
	int ty = y + dy[dir];

	if (tx < 0 || ty < 0 || tx >  n - 1 || ty > n - 1) {
		ans = max(ans, score * 2 + 1);
	}
	else if (tx == sx && ty == sy) {
		ans = max(ans, score);
	}
	else if (mat[tx][ty] == 0) {
		go(dir, tx, ty, score);
	}
	else if (mat[tx][ty] >= 1 && mat[tx][ty] <= 5) {
		int ddir = block[mat[tx][ty]][dir];
		go(ddir, tx, ty, score + 1);
	}
	else if (mat[tx][ty] >= 6 && mat[tx][ty] <= 10) {
		int h = mat[tx][ty];
		for (int i = 0; i < hole[h].size(); i++) {
			int hx = hole[h][i].first;
			int hy = hole[h][i].second;
			if (hx != tx && hy != ty) {
				go(dir, hx, hy, score);
				break;
			}
		}
	}
	else if (mat[tx][ty] == -1) {
		ans = max(ans, score);
	}
	
	return;
}

int main(void) {
	int tc;
	scanf("%d", &tc);
	for (int test_case = 1; test_case <= tc; test_case++) {
		memset(mat, 0, sizeof(mat));
		for (int i = 6; i <= 10; i++) {
			hole[i].clear();
		}

		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &mat[i][j]);
				if (mat[i][j] >= 6 && mat[i][j] <= 10) {
					hole[mat[i][j]].push_back(make_pair(i, j));
				}
			}
		}

		ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != 0) continue;
				sx = i, sy = j;
				for (int k = 0; k < 4; k++) {
					go(k, i, j, 0);
				}
			}
		}

		printf("#%d %d\n", test_case, ans);
	}

	return 0;
}
