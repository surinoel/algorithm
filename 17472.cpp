#include <queue>
#include <tuple>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct bridge {
	int x, y;
	int dist;
	bridge(int x = 0, int y = 0, int dist = 0) :
		x(x), y(y), dist(dist) {}
};

bool visit[10];
int mat[10][10];
int group[10][10];
int group_dist[10][10];
vector<int> graph[10];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}
	
	int group_num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1 && group[i][j] == 0) {
				++group_num;
				group[i][j] = group_num;
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					int x, y;
					tie(x, y) = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1 || mat[tx][ty] == 0 || group[tx][ty] != 0) continue;
						group[tx][ty] = group_num;
						q.push(make_pair(tx, ty));
					}
				}
			}
		}
	}
	
	memset(group_dist, -1, sizeof(group_dist));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == 1) {
				for (int k = 0; k < 4; k++) {
					int x = i, y = j;
					int dist = 0;
					for (;;) {
						int tx = x + dx[k];
						int ty = y + dy[k];
						if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) break;
						if (group[tx][ty] == group[i][j]) break;
						if (mat[tx][ty] == 1) {
							int gnum1 = group[i][j];
							int gnum2 = group[tx][ty];
							if (dist >= 2 && (group_dist[gnum1][gnum2] == -1 || group_dist[gnum1][gnum2] > dist)) {
								group_dist[gnum1][gnum2] = dist;
								group_dist[gnum2][gnum1] = dist;
							}
							break;
						}
						else {
							dist += 1;
							x = tx;
							y = ty;
						}
					}
				}
			}
		}
	}

	vector<bridge> vb;
	for (int i = 1; i < group_num; i++) {
		for (int j = i + 1; j <= group_num; j++) {
			if (group_dist[i][j] != -1) {
				vb.push_back(bridge(i, j, group_dist[i][j]));
			}
		}
	}

	int ans = -1;
	int vb_size = vb.size();
	for (int i = 1; i < (1 << vb_size); i++) {
		int sum = 0;
		for (int j = 1; j <= group_num; j++) {
			graph[j].clear();
			visit[j] = false;
		}
		for (int j = 0; j < vb_size; j++) {
			if (i & (1 << j)) {
				sum += vb[j].dist;
				graph[vb[j].x].push_back(vb[j].y);
				graph[vb[j].y].push_back(vb[j].x);
			}
		}

		queue<int> q;
		q.push(1);
		visit[1] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int k = 0; k < graph[x].size(); k++) {
				int y = graph[x][k];
				if (!visit[y]) {
					visit[y] = true;
					q.push(y);
				}
			}
		}

		bool ok = true;
		for (int j = 1; j <= group_num; j++) {
			if (!visit[j]) {
				ok = false;
				break;
			}
		}
		if (ok) {
			if (ans == -1 || ans > sum) {
				ans = sum;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
