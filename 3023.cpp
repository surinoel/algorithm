#include <iostream>

using namespace std;

char mat[101][101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = n + 1; i <= 2 * n; i++) {
		for (int j = 1; j <= m; j++) {
			mat[i][j] = mat[2 * n - i + 1][j];
		}
	}

	for (int i = 1; i <= 2 * n; i++) {
		for (int j = m + 1; j <= 2 * m; j++) {
			mat[i][j] = mat[i][2 * m - j + 1];
		}
	}
	
	int a, b;
	cin >> a >> b;
	mat[a][b] = (mat[a][b] == '.') ? '#' : '.';

	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * m; j++) {
			cout << mat[i][j];
		}
		cout << '\n';
	}

	return 0;
}
