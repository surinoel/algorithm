#include <iostream>

using namespace std;

long long d[1000001][2];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	d[1][1] = 1;
	d[2][0] = 1;
	d[2][1] = d[1][1];

	for (int i = 3; i <= n; i++) {
		d[i][0] = (d[i - 2][1] + d[i - 2][0]) % 15746;
		d[i][1] = (d[i - 1][1] + d[i - 1][0]) % 15746;
	}

	cout << (d[n][0] + d[n][1]) % 15746 << '\n';
	return 0;
}
