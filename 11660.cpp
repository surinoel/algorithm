#include <iostream>

using namespace std;

int mat[1024][1024];
long long d[1024][1024];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, tc;
	cin >> n >> tc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if (i - 1 < 0) {
			d[i][0] = mat[i][0];
		}
		else {
			d[i][0] = d[i - 1][0] + mat[i][0];
		}
	}

	for (int j = 0; j < n; j++) {
		if (j - 1 < 0) {
			d[0][j] = mat[0][j];
		}
		else {
			d[0][j] = d[0][j - 1] + mat[0][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			d[i][j] = d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1] + mat[i][j];
		}
	}

	while (tc--) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		sx -= 1, sy -= 1, ex -= 1, ey -= 1;
		long long ans = d[ex][ey];
		if (sx - 1 >= 0) {
			ans -= d[sx - 1][ey];
		}
		if (sy - 1 >= 0) {
			ans -= d[ex][sy - 1];
		}
		if (sx - 1 >= 0 && sy - 1 >= 0) {
			ans += d[sx - 1][sy - 1];
		}
		cout << ans << '\n';
	}

	return 0;
}
