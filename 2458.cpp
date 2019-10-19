#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int d[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	fill(&d[0][0], &d[n][n + 1], 1e5);

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		d[x][y] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool ok = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] == 1e5 && d[j][i] == 1e5) {
				ok = false;
				break;
			}
		}
		if (ok) ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
