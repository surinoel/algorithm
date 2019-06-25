#include <iostream>

using namespace std;

int dist[401][401];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	int inf = 1000000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = inf;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		dist[x][y] = d;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i][i] != inf) {
			if (ans == -1 || ans > dist[i][i]) {
				ans = dist[i][i];
			}
		}
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] != inf && dist[j][i] != inf) {
				if (ans == -1 || ans > dist[i][j] + dist[j][i]) {
					ans = dist[i][j] + dist[j][i];
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
