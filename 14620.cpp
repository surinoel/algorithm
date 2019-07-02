#include <cstring>
#include <iostream>

using namespace std;

#define min(n, m) n > m ? m : n

int n;
int mat[10][10];
bool visit[10][10];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x, int y, int cnt, int sum, int& ans) {
	if (cnt == 3) {
		ans = min(ans, sum);
		return;
	}
	if (x > n - 1) {
		return;
	}

	if (y == n - 1) dfs(x + 1, 0, cnt, sum, ans);
	else dfs(x, y + 1, cnt, sum, ans);

	if (!visit[x][y]) {
		visit[x][y] = true;
		int tmp = mat[x][y];
		bool ok = true;
		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1 || visit[tx][ty]) {
				ok = false;
				break;
			}
			tmp += mat[tx][ty];
		}
		if (ok) {
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];	int ty = y + dy[k];
				visit[tx][ty] = true;
			}
			if (y == n - 1) dfs(x + 1, 0, cnt + 1, sum + tmp, ans);
			else dfs(x, y + 1, cnt + 1, sum + tmp, ans);
			for (int k = 0; k < 4; k++) {
				int tx = x + dx[k];	int ty = y + dy[k];
				visit[tx][ty] = false;
			}
		}
		visit[x][y] = false;
	}

	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	int ans = 1e6;
	dfs(0, 0, 0, 0, ans);
	cout << ans << '\n';
	return 0;
}
