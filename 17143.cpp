#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct _shark {
	int dir, vc, size;
	_shark() : dir(0), vc(0), size(0) {}
	_shark(int dir, int vc, int size) :
		dir(dir), vc(vc), size(size) {}
} Shark;

typedef struct _sharkinfo {
	int x, y, dir, vc, size;
	_sharkinfo() : x(0), y(0), dir(0), vc(0), size(0) {}
	_sharkinfo(int x, int y, int dir, int vc, int size) :
		x(x), y(y), dir(dir), vc(vc), size(size) {}
} Sharkinfo;

vector<Shark> mat[100][100];
vector<Shark> tmat[100][100];

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	vector<Sharkinfo> si;
	for (int i = 0; i < k; i++) {
		int x, y, s, d, z;
		cin >> x >> y >> s >> d >> z;
		x -= 1, y -= 1;
		si.push_back(Sharkinfo(x, y, d, s, z));
		mat[x][y].push_back(Shark(d, s, z));
	}

	int ans = 0;
	for (int col = 0; col < m; col++) {
		for (int i = 0; i < n; i++) {
			if (mat[i][col].size() > 0) {
				ans += mat[i][col].front().size;
				mat[i][col].clear();
				break;
			}
		}

		for (int i = 0; i < si.size(); i++) {
			int x, y, s, d, z;
			x = si[i].x;
			y = si[i].y;
			s = si[i].vc;
			d = si[i].dir;
			z = si[i].size;

			if (mat[x][y].size() == 0) continue;

			int tx = x, ty = y;
			int range;
			if (d == 1 || d == 2) range = s % (2 * (n - 1));
			else range = s % (2 * (m - 1));
			for (int j = 0; j < range; j++) {
				tx += dx[d];
				ty += dy[d];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) {
					if (d == 1) d = 2;
					else if (d == 2) d = 1;
					else if (d == 3) d = 4;
					else if (d == 4) d = 3;
					j -= 1;
					tx += dx[d];
					ty += dy[d];
					continue;
				}
			}
			if (tmat[tx][ty].empty()) {
				tmat[tx][ty].push_back(Shark(d, s, z));
			}
			else {
				if (tmat[tx][ty].front().size < z) {
					tmat[tx][ty].clear();
					tmat[tx][ty].push_back(Shark(d, s, z));
				}
			}
		}

		si = vector<Sharkinfo>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				mat[i][j].clear();
				mat[i][j] = tmat[i][j];
				tmat[i][j].clear();

				if (!mat[i][j].empty()) {
					si.push_back(Sharkinfo(i, j, mat[i][j].front().dir, mat[i][j].front().vc, mat[i][j].front().size));
				}
			}
		}

	}

	cout << ans << '\n';
	return 0;
}
