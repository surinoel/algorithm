#include <cmath>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define RANGE	4000001

unsigned char prime[(RANGE + 7) / 8];

inline bool isprime(int k) {
	return prime[k >> 3] & (1 << (k & 7));
}

inline void clear(int k) {
	prime[k >> 3] &= ~(1 << (k & 7));
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	memset(prime, 255, sizeof(prime));
	int range = int(sqrt(m));
	clear(0); clear(1);

	for (int i = 2; i <= range; i++) {
		if (!isprime(i)) continue;
		for (int j = i + i; j <= m; j += i) {
			clear(j);
		}
	}

	int ans = 0;
	for (int i = n; i <= m; i++) {
		if (!isprime(i)) continue;
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
