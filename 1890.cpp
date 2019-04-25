#include <iostream>

using namespace std;

int mat[200][200];
long long d[200][200];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	d[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int p = mat[i][j];
			if (p == 0) continue;
			d[i + p][j] += d[i][j];
			d[i][j + p] += d[i][j];
		}
	}

	cout << d[n][n] << '\n';
	return 0;
}
