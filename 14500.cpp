#include <cstring>
#include <iostream>

using namespace std;

int n, m;
int ans = -1;
int mat[500][500];

int dir[19][4][2] = {
	{{0, 0}, {0, 1}, {0, 2}, {0, 3}},
	{{0, 0}, {1, 0}, {2, 0}, {3, 0}},
	{{0, 0}, {0, 1}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {2, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {2, 1}},
	{{0, 0}, {1, 0}, {0, 1}, {0, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {1, 2}},
	{{0, 0}, {0, 1}, {-1, 1}, {-2, 1}},
	{{0, 0}, {1, 0}, {2, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 2}},
	{{0, 0}, {1, 0}, {1, 1}, {2, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {1, 2}},
	{{0, 0}, {1, 0}, {0, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {0, 2}, {1, 1}},
	{{0, 0}, {0, 1}, {-1, 1}, {0, 2}},
	{{0, 0}, {0, 1}, {1, 1}, {-1, 1}},
	{{0, 0}, {0, 1}, {-1, 0}, {1, 0}}
};

void go(int x, int y) {
	if (x == n) {
		return;
	}

	for (int i = 0; i < 19; i++) {
		bool ok = true;
		int tsum = 0;

		for (int k = 0; k < 4; k++) {
			int tx = x + dir[i][k][0];
			int ty = y + dir[i][k][1];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) {
				ok = false;
				break;
			}
			tsum += mat[tx][ty];
		}

		if (ok) {
			if (tsum > ans) {
				ans = tsum;
			}
		}
	}

	if (++y == m) {
		y = 0;
		x += 1;
	}

	go(x, y);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	go(0, 0);
	cout << ans << '\n';
	return 0;
}
