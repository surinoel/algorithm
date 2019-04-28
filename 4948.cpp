#include <cstring>
#include <iostream>

using namespace std;

bool prime[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(prime, true, sizeof(prime));

	prime[1] = false;
	for (int i = 2; i < 1000000; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j < 1000000; j += i) {
			prime[j] = false;
		}
	}

	while (1) {
		int x; cin >> x;
		if (x == 0) break;
		int ans = 0;
		for (int i = x + 1; i <= 2 * x; i++) {
			if (prime[i]) ans += 1;
		}
		cout << ans << '\n';
	}
	return 0;
}
