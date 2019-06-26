#include <iostream>

using namespace std;

int dist[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int inf = 100000000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dist[x][y] = 1;
		dist[y][x] = -1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][k] == 1 && dist[k][j] == 1) {
					dist[i][j] = 1;
				}
				if (dist[i][k] == -1 && dist[k][j] == -1) {
					dist[i][j] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == inf) cnt += 1;
		}
		cout << cnt << '\n';
	}

	return 0;
} 
