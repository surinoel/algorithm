#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int mat[5][5][5];
int dist[5][5][5];

int dx[6] = { 1, -1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

void rotate(vector<vector<int>> &v) {
	vector<vector<int>> tmp(v);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			v[i][j] = tmp[j][5 - i - 1];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<vector<int>>> groups;
	for (int k = 0; k < 5; k++) {
		vector<vector<int>> group;
		for (int i = 0; i < 5; i++) {
			vector<int> row;
			for (int j = 0; j < 5; j++) {
				int x;
				cin >> x;
				row.push_back(x);
			}
			group.push_back(row);
		}
		groups.push_back(group);
	}

	int ans = -1;
	vector<int> idx = { 0, 1, 2, 3, 4 };
	do {
		vector<vector<vector<int>>> vtmp;
		for (int i = 0; i < 5; i++) {
			vtmp.push_back(groups[idx[i]]);
		}

		for (int r1 = 0; r1 < 4; r1++) {
			rotate(vtmp[0]);
			for (int r2 = 0; r2 < 4; r2++) {
				rotate(vtmp[1]);
				for (int r3 = 0; r3 < 4; r3++) {
					rotate(vtmp[2]);
					for (int r4 = 0; r4 < 4; r4++) {
						rotate(vtmp[3]);
						for (int r5 = 0; r5 < 4; r5++) {
							rotate(vtmp[4]);

							memset(dist, -1, sizeof(dist));
							queue<tuple<int, int, int>> q;
							if (vtmp[0][0][0] == 0) continue;
							q.push(make_tuple(0, 0, 0));
							dist[0][0][0] = 0;

							while (!q.empty()) {
								int z, x, y;
								tie(z, x, y) = q.front();
								q.pop();

								for (int k = 0; k < 6; k++) {
									int tz = z + dz[k];
									int tx = x + dx[k];
									int ty = y + dy[k];
									if (tx < 0 || ty < 0 || tz < 0 || tx > 4 || ty > 4 || tz > 4) continue;
									if (dist[tz][tx][ty] != -1 || vtmp[tz][tx][ty] == 0) continue;
									dist[tz][tx][ty] = dist[z][x][y] + 1;
									q.push(make_tuple(tz, tx, ty));
								}
							}

							if (dist[4][4][4] != -1) {
								if (ans == -1 || ans > dist[4][4][4]) {
									ans = dist[4][4][4];
								}
							}
						}
					}
				}
			}
		}
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ans << '\n';
}
