#include <iostream>
#include <algorithm>

using namespace std;

int mat[1000][1000];
int d[1000][1000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) {
				d[i][j] = mat[i][j];
				continue;
			}
			int m1 = 0, m2 = 0, m3 = 0;
			if (i - 1 >= 0) {
				m1 = d[i - 1][j];
			}
			if (j - 1 >= 0) {
				m2 = d[i][j - 1];
			}
			if (i - 1 >= 0 && j - 1 >= 0) {
				m3 = d[i - 1][j - 1];
			}
			d[i][j] = mat[i][j] + max(max(m1, m2), m3);
		}
	}
	
	cout << d[n - 1][m - 1] << '\n';
	return 0;
}