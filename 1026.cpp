#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}
	cout << ans << '\n';

	return 0;
}
