#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

int a[501][501];
int d[501][501];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	int ans = a[1][1];
	d[1][1] = a[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i][j] = d[i - 1][j] + a[i][j];
			if (j - 1 >= 1) {
				d[i][j] = max(d[i][j], d[i - 1][j - 1] + a[i][j]);
			}
			ans = max(ans, d[i][j]);
		}
	}

	cout << ans << '\n';
	return 0;
}
