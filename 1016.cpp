#include <iostream>

using namespace std;

bool ok[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	for (long long i = 2; i*i <= m; i++) {
		long long st;
		if (n%(i*i) == 0) {
			st = n;
		}
		else {
			st = n - (n%(i*i)) + i*i;
		}
		for (long long j = st; j <= m; j += i*i) {
			ok[j - n] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i <= m - n; i++) {
		if (!ok[i]) ans += 1;
	}
	cout << ans << '\n';
	return 0;
}
