#include <iostream>

using namespace std;

int dist[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n, m;
	cin >> n >> m;
	int inf = 10000001;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		if (dist[x][y] > d) {
			dist[x][y] = d;
		}
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == inf) {
				cout << dist[i][j] << ' ';
			}
			else {
				cout << dist[i][j] << ' ';
			}
		}
		cout << '\n';
	}
	cout << '\n';

	return 0;
}
