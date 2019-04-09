#include <iostream>

using namespace std;

long long d[201][201];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	int mod = 1000000000;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		d[i][1] = 1;
	}

	for (int u = 2; u <= k; u++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				d[i][u] += d[i - j][u - 1];
				d[i][u] %= mod;
			}
		}
	}
	cout << d[n][k] << '\n';

	return 0;
}