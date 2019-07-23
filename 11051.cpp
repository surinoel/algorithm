#include <iostream>

using namespace std;

int d[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0][0] = 1;
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			d[i][j] = ((d[i - 1][j] % 10007) + (d[i - 1][j - 1] % 10007)) % 10007;
		}
	}
	
	cout << d[n][k] << '\n';
	return 0;
}
