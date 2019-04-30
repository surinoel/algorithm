#include <cstring>
#include <iostream>

using namespace std;

bool prime[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(prime, true, sizeof(prime));
	prime[1] = false;
	for (int i = 2; i <= 10000; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= 10000; j += i) {
			prime[j] = false;
		}
	}

	int tc; cin >> tc;
	while (tc--) {
		int n; cin >> n;
		int a, b;
		for (int i = n / 2; i >= 2; i--) {
			if (!prime[i] || !prime[n - i]) continue;
			a = i;
			b = n - i;
			break;
		}
		cout << a << ' ' << b << '\n';
	}

	return 0;
}
