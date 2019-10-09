#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; ; i++) {
		int n, m, k;
		cin >> n >> m >> k;
		if (n == 0 && m == 0 && k == 0) {
			break;
		}

		long long ans = 0;
		int d1 = k / m;
		int d2 = k % m;

		ans += d1 * n;
		if (d2 >= n) {
			ans += n;
		}
		else {
			ans += d2;
		}

		cout << "Case " << i << ": " << ans << '\n';
	}

	return 0;
}
