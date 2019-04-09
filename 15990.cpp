#include <iostream>

using namespace std;

// 합과 끝에 오는 수
long long d[100001][4];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int mod = 1000000009;
	
	d[1][1] = 1;
	d[2][2] = 1;
	d[3][3] = 1;

	for (int i = 1; i <= 100000; i++) {
		if (i - 1 >= 1) {
			d[i][1] = d[i - 1][2] + d[i - 1][3];
			d[i][1] %= mod;
		}
		if (i - 2 >= 1) {
			d[i][2] = d[i - 2][1] + d[i - 2][3];
			d[i][2] %= mod;
		}
		if (i - 3 >= 1) {
			d[i][3] = d[i - 3][1] + d[i - 3][2];
			d[i][3] %= mod;
		}
	}

	freopen("data.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
	}
	return 0;
}