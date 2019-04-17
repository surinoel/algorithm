#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct __shark {
	int s, d, z;
	bool move;
	__shark(int _s, int _d, int _z, bool _move) : s(_s), d(_d), z(_z), move(_move) {}
} shark;

int n, m, k;
int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

void moving(int x, int y, shark sh, vector<vector<deque<shark>>> &mat) {
	int tmpx = x, tmpy = y;
	int dir = sh.d;
	int v = sh.s;
	int size = sh.z;
	for (int i = 0; i < v; i++) {
		if (tmpx + dx[dir] < 0 || tmpy + dy[dir] < 0 || tmpx + dx[dir] > n - 1 || tmpy + dy[dir] > m - 1) {
			if (dir == 1) dir = 2;
			else if (dir == 2) dir = 1;
			else if (dir == 3) dir = 4;
			else if (dir == 4) dir = 3;
			
			tmpx += dx[dir];
			tmpy += dy[dir];
		}
		else {
			tmpx += dx[dir];
			tmpy += dy[dir];
		}
	}
	mat[x][y].pop_front();
	mat[tmpx][tmpy].push_back(shark(v, dir, size, true));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> k;
	vector<vector<deque<shark>>> mat(n, vector<deque<shark>>(m, deque<shark>()));
	for (int i = 0; i < k; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		mat[r - 1][c - 1].push_back(shark(s, d, z, false));
	}

	long long ans = 0;
	int pos = -1;
	while (++pos < m) {
		for (int i = 0; i < n; i++) {
			if (!mat[i][pos].empty()) {
				ans += mat[i][pos][0].z;
				mat[i][pos].pop_front();
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j].empty()) continue;
				if (mat[i][j][0].move == true) continue;
				if (mat[i][j][0].s == 0) {
					mat[i][j][0].move = true;
				}
				else {
					moving(i, j, mat[i][j][0], mat);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j].size() > 1) {
					sort(mat[i][j].begin(), mat[i][j].end(), [&](auto &u, auto &v) {
						return u.z > v.z;
					});

					for (int p = 0; p < mat[i][j].size() - 1; p++) {
						mat[i][j].pop_back();
					}
				}
				if (mat[i][j].size() > 0) {
					mat[i][j][0].move = false;
				}
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
