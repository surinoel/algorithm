#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

int mat[8][8];
int tmpmat[8][8];
int dist[8][8];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		memset(mat, 0, sizeof(mat));
		int n, m;
		int maxheight = -1;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
				maxheight = max(maxheight, mat[i][j]);
			}
		}

		vector<pair<int, int>> maxpos;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] == maxheight) {
					maxpos.push_back(make_pair(i, j));
				}
			}
		}
		
		int ans = 0;
		for (int k = 0; k < maxpos.size(); k++) {
			int x, y;
			x = maxpos[k].first, y = maxpos[k].second;
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (i == x && j == y) continue;
					for (int z = 1; z <= m; z++) {
						if (mat[i][j] - z < 0) break;
						memcpy(tmpmat, mat, sizeof(tmpmat));
						memset(dist, -1, sizeof(dist));
						tmpmat[i][j] -= z;
						
						int tmpmax = -1;
						queue<pair<int, int>> q;
						q.push(make_pair(x, y));
						dist[x][y] = 1;
						tmpmax = dist[x][y];

						while (!q.empty()) {
							int tx, ty;
							tie(tx, ty) = q.front();
							q.pop();

							for (int u = 0; u < 4; u++) {
								int ttx = tx + dx[u];
								int tty = ty + dy[u];
								if (ttx < 0 || tty < 0 || ttx > n - 1 || tty > n - 1) continue;
								if (tmpmat[ttx][tty] >= tmpmat[tx][ty]) continue;
								if (dist[ttx][tty] == -1 || dist[tx][ty] + 1 > dist[ttx][tty]) {
									dist[ttx][tty] = dist[tx][ty] + 1;
									q.push(make_pair(ttx, tty));
									tmpmax = max(tmpmax, dist[ttx][tty]);
								}
							}
						}

						ans = max(ans, tmpmax);
					}
				}
			}		
		}
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
