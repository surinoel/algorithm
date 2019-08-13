#include <queue>
#include <tuple>
#include <string>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int mat[100][100];
int dist[100][100];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, ex, ey;
	cin >> m >> n;
	queue<tuple<int, int, int>> q;
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'C') {
				if (q.empty()) {
					dist[i][j] = 0;
					q.push(make_tuple(i, j, 0));
				}
				else {
					ex = i;
					ey = j;
				}
				mat[i][j] = 2;
			}
			else if (s[j] == '*') {
				mat[i][j] = -1;
 			}
		}
	}

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];

			while (!(tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == -1)) {
				if (dist[tx][ty] == -1 || dist[tx][ty] > dist[x][y]) {
					dist[tx][ty] = z;
					q.push(make_tuple(tx, ty, z + 1));
					tx += dx[k];
					ty += dy[k];
				}
				else {
					break;
				}
			}
		}
	}
	
	cout << dist[ex][ey] << '\n';
	return 0;
}
