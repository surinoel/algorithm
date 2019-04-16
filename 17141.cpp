#include <queue>
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, m = 0;
	cin >> n >> k;
	vector<vector<int>> mat(n, vector<int>(n));
	vector<pair<int, int>> virus;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 2) {
				m += 1;
				mat[i][j] = 0;
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	vector<int> idx(m, 0);
	for (int i = m - k; i < m; i++) {
		idx[i] = 1;
	}

	int ans = -1;
	do {
		queue<pair<int, int>> q;
		vector<vector<int>> tmat(mat);
		vector<vector<int>> dist(n, vector<int>(n, -1));

		for (int i = 0; i < m; i++) {
			if (idx[i] == 1) {
				tmat[virus[i].first][virus[i].second] = 1;
				dist[virus[i].first][virus[i].second] = 0;
				q.push(make_pair(virus[i].first, virus[i].second));
			}
		}
		
		queue<pair<int, int>> nxt_q;
		while (!q.empty()) {
			int x, y;
			tie(x, y) = q.front();
			q.pop();

			for (int u = 0; u < 4; u++) {
				int tx = x + dx[u];
				int ty = y + dy[u];
				if (tx < 0 || ty < 0 || tx > n - 1 || ty > n - 1) continue;
				if (tmat[tx][ty] != 0 || dist[tx][ty] != -1) continue;
				dist[tx][ty] = dist[x][y] + 1;
				nxt_q.push(make_pair(tx, ty));
			}

			if (q.empty()) {
				q = nxt_q;
				nxt_q = queue<pair<int, int>>();
			}
		}

		bool ok = true;
		int time = -1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (tmat[i][j] == 0 && dist[i][j] == -1) {
					ok = false;
					break;
				}
				time = max(time, dist[i][j]);
			}
		}

		if (ok) {
			if (ans == -1 || ans > time) {
				ans = time;
			}
		}

	} while (next_permutation(idx.begin(), idx.end()));

	cout << ans << '\n';
	return 0;
}
