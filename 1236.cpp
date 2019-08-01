#include <queue>
#include <string>
#include <iostream>

using namespace std;

char mat[50][50];
bool row[50];
bool col[50];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			if (mat[i][j] == 'X') {
				row[i] = col[j] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!row[i] && !col[j]) {
				ans += 1;
				row[i] = col[j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!row[i] || !col[j]) {
				ans += 1;
				row[i] = col[j] = true;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
