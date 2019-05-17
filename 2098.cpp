#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
int mat[16][16];
int d[16][(1 << 16)];

int tsp(int city, int visit) {
	if (visit == (1 << n) - 1) {
		if (mat[city][0] == 0) {
			return 1000001;
		}
		return mat[city][0];
	}

	if (d[city][visit] > -1) {
		return d[city][visit];
	}

	int ans = 2000000;
	for (int k = 1; k < n; k++) {
		if (mat[city][k] == 0 || (visit & (1 << k))) continue;
		ans = min(ans, tsp(k, visit | (1 << k)) + mat[city][k]);
	}

	return d[city][visit] = ans;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	memset(d, -1, sizeof(d));
	cout << tsp(0, 1) << '\n';

	return 0;
}
