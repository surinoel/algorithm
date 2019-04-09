#include <iostream>

using namespace std;

long long d[101][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int mod = 1000000000;
	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1;
	}
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				d[i][j] = d[i - 1][j + 1];
			}
			else if (j == 9) {
				d[i][j] = d[i - 1][j - 1];
			}
			else {
				d[i][j] = d[i - 1][j + 1] + d[i - 1][j - 1];
			}
			d[i][j] %= mod;
		}
	}

	int n;
	cin >> n;
	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += d[n][i];
		sum %= mod;
	}
	cout << sum << '\n';
	return 0;
}