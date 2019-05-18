#include <iostream>

using namespace std;

int a[2000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	while (n--) {
		int x; cin >> x;
		a[x] += 1;
	}
	long long ans = 0;
	int sum; cin >> sum;
	for (int i = 1; i < sum; i++) {
		if (i >= sum - i) break;
		if (a[i] > 0 && a[sum - i] > 0) {
			ans += a[i] * a[sum - i];
		}
	}

	cout << ans << '\n';
	return 0;
}
