#include <cmath>
#include <tuple>
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int dist[102][102];
int bottle[102];
bool visit[102][102];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(dist, 0, sizeof(dist));
		memset(bottle, 0, sizeof(bottle));
		memset(visit, 0, sizeof(visit));

		queue<pair<int, int>> q;
		int n;
		cin >> n;
		vector<pair<int, int>> store(n + 2);
		int sx, sy, ex, ey;
		cin >> sx >> sy;
		store[0] = make_pair(sx, sy);
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			store[i] = make_pair(x, y);
		}
		cin >> ex >> ey;
		store[n + 1] = make_pair(ex, ey);

		for (int i = 0; i < n + 1; i++) {
			for (int j = i + 1; j < n + 2; j++) {
				int x1, y1, x2, y2;
				x1 = store[i].first, y1 = store[i].second;
				x2 = store[j].first, y2 = store[j].second;
				dist[i][j] = dist[j][i] = abs(x1 - x2) + abs(y1 - y2);
			}
		}

		q.push(make_pair(0, 20));
		while (!q.empty()) {
			int idx, b;
			tie(idx, b) = q.front();
			q.pop();

			for (int i = 1; i < n + 2; i++) {
				if (idx != i && !visit[idx][i] && (dist[idx][i] <= 1000)) {
					visit[idx][i] = true;
					q.push(make_pair(i, 20));
				}
			}
		}

		bool ok = false;
		for (int i = 0; i < n + 2; i++) {
			if (visit[i][n + 1] == true) {
				ok = true;
				break;
			}
		}

		if (!ok) cout << "sad\n";
		else cout << "happy\n";
	}

	return 0;
}
