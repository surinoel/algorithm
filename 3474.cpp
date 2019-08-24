#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		ull n;
		cin >> n;

		ull cnt2 = 0, cnt5 = 0;
		for (ull i = 2; i <= n; i *= 2) {
			cnt2 += n / i;
		}
		for (ull i = 5; i <= n; i *= 5) {
			cnt5 += n / i;
		}
		cout << min(cnt2, cnt5) << '\n';
	}

	return 0;
}
