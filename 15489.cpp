#include <iostream>

using namespace std;

int d[31][31];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n, m, k;
	cin >> n >> m >> k;
	d[1][1] = 1;
	for (int i = 2; i <= 30; i++) {
		d[i][1] = 1;
		for (int j = 2; j <= i - 1; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
		d[i][i] = 1;
	}
	
	long long sum = 0;
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i; j++) {
			sum += d[n + i - 1][m + j - 1];
		}
	}

	cout << sum << '\n';
	return 0;
}
