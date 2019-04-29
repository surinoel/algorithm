#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n), u(n*n), v(n*n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			u[i*n + j] = a[i] + b[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[i*n + j] = c[i] + d[j];
		}
	}

	sort(v.begin(), v.end());
	long long ans = 0;
	for (int i = 0; i < n*n; i++) {
		auto it1 = upper_bound(v.begin(), v.end(), -u[i]);
		auto it2 = lower_bound(v.begin(), v.end(), -u[i]);
		ans += it1 - it2;
	}

	cout << ans << '\n';
	return 0;
}
