#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

bool prime[1300001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(prime, true, sizeof(prime));
	int n = 1300000;
	int range = int(sqrt(n));
	prime[0] = prime[1] = false;
	for (int i = 2; i <= range; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			prime[j] = false;
		}
	}

	int tc;
	cin >> tc;
	while (tc--) {
		int x; cin >> x;
		if (prime[x]) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 1;
		for (int i = x - 1; i >= 1; i--) {
			if (prime[i]) break;
			ans += 1;
		}
		for (int i = x + 1; ; i++) {
			if (prime[i]) break;
			ans += 1;
		}
		cout << ans  + 1 << '\n';
	}

	return 0;
}
