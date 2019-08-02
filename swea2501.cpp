#include <vector>
#include <iostream>

using namespace std;

int n;
int mat[20][20];
bool visit[20][20];
bool desert[101];

int ans;
int dx[4] = { 1, 1, -1, -1 };
int dy[4] = { 1, -1, -1, 1 };

void go(int x, int y, int px, int py, int cnt, int dir) {
	if (visit[x][y] && px == x && py == y) {
		if (dir == 3 && (ans == -1 || cnt > ans)) {
			ans = cnt;
		}
		return;
	}
	if (visit[x][y] || desert[mat[x][y]]) {
		return;
	}

	visit[x][y] = desert[mat[x][y]] = true;
	if (dir == -1) {
		int tx = x + dx[0];
		int ty = y + dy[0];
		if (!(tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1)) {
			go(tx, ty, px, py, cnt + 1, 0);
		}
	}
	else {
		int tx = x + dx[dir];
		int ty = y + dy[dir];
		if (!(tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1)) {
			go(tx, ty, px, py, cnt + 1, dir);
		}
		tx = x + dx[dir + 1];
		ty = y + dy[dir + 1];
		if (!(tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1)) {
			go(tx, ty, px, py, cnt + 1, dir + 1);
		}
	}

	visit[x][y] = desert[mat[x][y]] = false;

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int k = 1; k <= tc; k++) {
		ans = -1;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				memset(visit, 0, sizeof(visit));
				memset(desert, 0, sizeof(desert));
				go(i, j, i, j, 0, -1);
			}
		}

		cout << "#" << k << " " << ans << '\n';
	}

	return 0;
}
