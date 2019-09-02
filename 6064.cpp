#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		int limit = (n * m) / gcd(max(n, m), min(n, m));
		int target = max(x, y);
		int ans;
		bool ok = false;
		
		int inc;
		if (target == x) inc = n;
		else inc = m;

		if (x == n) x = 0;
		if (y == m) y = 0;
		for (int i = target; i <= limit; i += inc) {
			if (i % n == x && i % m == y) {
				ok = true;
				ans = i;
				break;
			}
		}
		
		if (!ok) {
			cout << -1 << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}

	return 0;
}
