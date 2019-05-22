#include <iostream>

using namespace std;

int a[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int b, c;
	cin >> b >> c;
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - b > 0) {
			a[i] -= b;
			ans += a[i] / c;
			if (a[i] % c > 0) {
				ans += 1;
			}
		}
		ans += 1;
	}
	cout << ans << '\n';
	return 0;
}
