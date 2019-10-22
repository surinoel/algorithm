#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

int mat[1001][1001];
int d[1001][1001][11][2];

struct MAT {
	int x, y, k, b;
	MAT(int x = 0, int y = 0, int k = 0, int b = 0) :
		x(x), y(y), k(k), b(b) {}
};

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, tk;
	cin >> n >> m >> tk;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			mat[i][j] = s[j - 1] - '0';
		}
	}

	memset(d, -1, sizeof(d));
	queue<MAT> q;
	q.push(MAT(1, 1, 0, 0));
	d[1][1][0][0] = 1;

	while (!q.empty()) {
		int x, y, k, b;
		x = q.front().x;
		y = q.front().y;
		k = q.front().k;
		b = q.front().b;

		q.pop();
		for (int u = 0; u < 4; u++) {
			int tx = x + dx[u];
			int ty = y + dy[u];
			int tb = (b + 1) % 2;
			
			if (tx < 1 || ty < 1 || tx > n || ty > m) continue;
			if (d[x][y][k][tb] == -1) {
				d[x][y][k][tb] = d[x][y][k][b] + 1;
				q.push(MAT(x, y, k, tb));
			}
			if (mat[tx][ty] == 0 && d[tx][ty][k][tb] == -1) {
				d[tx][ty][k][tb] = d[x][y][k][b] + 1;
				q.push(MAT(tx, ty, k, tb));
			}
			else if (mat[tx][ty] == 1) {l 
				if (b == 0 && k + 1 <= tk && d[tx][ty][k + 1][tb] == -1) {
					d[tx][ty][k + 1][tb] = d[x][y][k][b] + 1;
					q.push(MAT(tx, ty, k + 1, tb));
				}
			}
		}
	}

	int ans = -1;
	for (int i = 0; i <= tk; i++) {
		for (int j = 0; j < 2; j++) {
			if (ans == -1 || (d[n][m][i][j] != -1 && ans > d[n][m][i][j])) {
				ans = d[n][m][i][j];
			}
		}
	}
	
	cout << ans << '\n';
	return 0;
}
