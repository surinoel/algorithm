#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

typedef struct __ball {
	int bx1, by1, bx2, by2;
	__ball(int _bx1, int _by1, int _bx2, int _by2) : bx1(_bx1), by1(_by1), bx2(_bx2), by2(_by2) {}
} ball;

int n, m;
int mat[20][20];
int dist[20][20][20][20];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool out(int x, int y) {
	if (x < 0 || y < 0 || x > n - 1 || y > m - 1) return true;
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(dist, -1, sizeof(dist));

	cin >> n >> m;
	int bx1, by1, bx2, by2;
	bx1 = by1 = bx2 = by2 = -1;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '#') {
				mat[i][j] = -1;
			}
			else if (s[j] == 'o') {
				if (bx1 == -1 && by1 == -1) {
					bx1 = i;
					by1 = j;
				}
				else {
					bx2 = i;
					by2 = j;
				}
			}
		}
	}

	queue<ball> q;
	dist[bx1][by1][bx2][by2] = 0;
	q.push(ball(bx1, by1, bx2, by2));

	int ans = -1;
	while (!q.empty()) {
		ball b = q.front();
		q.pop();

		int x1, y1, x2, y2;
		x1 = b.bx1; y1 = b.by1; x2 = b.bx2; y2 = b.by2;
		
		if (dist[x1][y1][x2][y2] == 10) {
			break;
		}

		for (int k = 0; k < 4; k++) {
			int tx1, ty1, tx2, ty2;
			tx1 = x1 + dx[k];
			ty1 = y1 + dy[k];
			tx2 = x2 + dx[k];
			ty2 = y2 + dy[k];
			
			bool ook1 = false, ook2 = false;
			if (out(tx1, ty1) && out(tx2, ty2)) continue;
			
			if (out(tx1, ty1) ^ out(tx2, ty2)) {
				cout << dist[x1][y1][x2][y2] + 1 << '\n';
				return 0;
			}

			if (!out(tx1, ty1)) {
				if (mat[tx1][ty1] == -1) {
					tx1 -= dx[k];
					ty1 -= dy[k];
				}
			}
			if (!out(tx2, ty2)) {
				if (mat[tx2][ty2] == -1) {
					tx2 -= dx[k];
					ty2 -= dy[k];
				}
			}
			
			if (dist[tx1][ty1][tx2][ty2] == -1) {
				dist[tx1][ty1][tx2][ty2] = dist[x1][y1][x2][y2] + 1;
				q.push(ball(tx1, ty1, tx2, ty2));
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
