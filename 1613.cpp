#include <iostream>

using namespace std;

int dist[401][401];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n, k;
	cin >> n >> k;
	int inf = 100000000;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i != j) dist[i][j] = inf;
		}
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		dist[x][y] = 1;
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

	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (dist[x][y] != inf) {
			cout << -1 << '\n';
		}
		else if (dist[y][x] != inf) {
			cout << 1 << '\n';
		}
		else {
			cout << 0 << '\n';
		}
	}

	return 0;
}
