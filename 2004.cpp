#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
ll ans[3][2];

void calc(ll idx, ll k) {
	for (ll i = 2; i <= k; i *= 2) {
		ans[idx][0] += k / i;
	}
	for (ll i = 5; i <= k; i *= 5) {
		ans[idx][1] += k / i;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ll n, m;
	cin >> n >> m;

	calc(0, n);
	calc(1, m);
	calc(2, n - m);

	cout << min(ans[0][0] - ans[1][0] - ans[2][0],
		ans[0][1] - ans[1][1] - ans[2][1]) << '\n';

	return 0;
}
