#include <iostream>

using namespace std;

int d[2000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = x; j <= m; j += x) {
			d[j] += 1;
		}
	}
	long long ans = 1;
	for (int i = 1; i <= m; i++) {
		if (d[i] >= 1) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}
