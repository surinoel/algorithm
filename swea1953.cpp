#include <queue>
#include <tuple>
#include <cstring>
#include <iostream>

using namespace std;

const int inf = 1e8;

int mat[50][50];
int dist[50][50];

int dir[8][4][2];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	dir[2][2][0] = inf;
	dir[2][2][1] = inf;
	dir[2][3][0] = inf;
	dir[2][3][1] = inf;

	dir[3][0][0] = inf;
	dir[3][0][1] = inf;
	dir[3][1][0] = inf;
	dir[3][1][1] = inf;

	dir[4][0][0] = inf;
	dir[4][0][1] = inf;
	dir[4][3][0] = inf;
	dir[4][3][1] = inf;

	dir[5][1][0] = inf;
	dir[5][1][1] = inf;
	dir[5][3][0] = inf;
	dir[5][3][1] = inf;

	dir[6][1][0] = inf;
	dir[6][1][1] = inf;
	dir[6][2][0] = inf;
	dir[6][2][1] = inf;

	dir[7][0][0] = inf;
	dir[7][0][1] = inf;
	dir[7][2][0] = inf;
	dir[7][2][1] = inf;

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n, m, mx, my, t;
		cin >> n >> m >> mx >> my >> t;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> mat[i][j];
			}
		}
	
		memset(dist, -1, sizeof(dist));
		queue<pair<int, int>> q;
		q.push(make_pair(mx, my));
		dist[mx][my] = 1;

		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			
			int mdir = mat[x][y];
			for (int k = 0; k < 4; k++) {
				if (dir[mdir][k][0] == inf) continue;
				int tx = x + dx[k];
				int ty = y + dy[k];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || dist[tx][ty] != -1 || mat[tx][ty] == 0) continue;
				int odir;
				if (k == 0) odir = 1;
				else if (k == 1) odir = 0;
				else if (k == 2) odir = 3;
				else odir = 2;
				
				if (dir[mat[tx][ty]][odir][0] != inf) {
					dist[tx][ty] = dist[x][y] + 1;
					q.push(make_pair(tx, ty));
				}
			}
 		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dist[i][j] > 0 && dist[i][j] <= t) {
					ans += 1;
				}
			}
		}
		
		cout << "#" << test_case << " " << ans << '\n';
	}
	
	return 0;
}
