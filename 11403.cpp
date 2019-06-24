#include <iostream>

using namespace std;

int dist[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n; cin >> n;
	int inf = 1000000000;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int cost; cin >> cost;
			dist[i][j] = (cost == 1) ? 0 : inf;
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (dist[i][j] == 0) cout << 1 << ' ';
			else cout << 0 << ' ';
		}
		cout << '\n';
	}

	return 0;
}
