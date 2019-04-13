#include <tuple>
#include <queue>
#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int ans = -1;
int n, m, d;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void bfs(int j, deque<vector<int>> tmp, vector<pair<int, int>> &enamy) {
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int, int>> q;
	q.push(make_pair(n - 1, j));
	dist[n - 1][j] = 1;
	
	if (tmp[n - 1][j] == 1) {
		enamy.push_back(make_pair(n - 1, j));
		return;
	}

	vector<pair<int, int>> en;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int tx = x + dx[k];
			int ty = y + dy[k];
			if (dist[x][y] >= d) {
				break;
			}
			if (tx < 0 || ty < 0 || tx > n - 1 || ty > m - 1) continue;
			if (dist[tx][ty] != -1) continue;
			dist[tx][ty] = dist[x][y] + 1;
			if (tmp[tx][ty] == 1 && dist[tx][ty] <= d) {
				en.push_back(make_pair(tx, ty));
			}
			q.push(make_pair(tx, ty));
		}
	}

	if (!en.empty()) {
		sort(en.begin(), en.end(), [&](auto &u, auto &v) {
			if (dist[u.first][u.second] == dist[v.first][v.second]) {
				return u.second < v.second;
			}
			return dist[u.first][u.second] < dist[v.first][v.second];
		});
		enamy.push_back(en[0]);
	}
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> d;
	deque<vector<int>> mat(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> arch(m);
	for (int i = m - 3; i < m; i++) {
		arch[i] = 1;
	}
	do {
		int cnt = 0;
		deque<vector<int>> tmp(mat);
		for (int k = 0; k < n; k++) {
			vector<pair<int, int>> enamy;
			for (int i = 0; i < m; i++) {
				if (arch[i] == 0) continue;
				bfs(i, tmp, enamy);
			}
			for (auto &t : enamy) {
				if (tmp[t.first][t.second] == 1) {
					tmp[t.first][t.second] = 0;
					cnt += 1;
				}
			}
			tmp.push_front(vector<int>(m));
			tmp.pop_back();
		}
		if(ans == -1 || cnt > ans) {
			ans = cnt;
		}

	} while (next_permutation(arch.begin(), arch.end()));
	
	cout << ans << '\n';

	return 0;
}
