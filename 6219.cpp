#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

bool prime[4000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	memset(prime, true, sizeof(prime));
	int range = int(sqrt(m));
	prime[0] = prime[1] = false;

	for (int i = 2; i <= range; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= m; j += i) {
			prime[j] = false;
		}
	}

	int ans = 0;
	for (int i = n; i <= m; i++) {
		if (!prime[i]) continue;
		string s = to_string(i);
		for (int j = 0; j < s.size(); j++) {
			if (s[j] - '0' == k) {
				ans += 1;
				break;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
