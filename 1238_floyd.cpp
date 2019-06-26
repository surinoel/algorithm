#include <iostream>

using namespace std;

int dist[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, z;
	cin >> n >> m >> z;
	int inf = 100000000;
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
		if (i != z) {
			if (dist[i][z] + dist[z][i] > ans) {
				ans = dist[i][z] + dist[z][i];
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
