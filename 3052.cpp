#include <iostream>

using namespace std;

int a[42];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 10;
	while (n--) {
		int x; cin >> x;
		a[x % 42] += 1;
	}

	int ans = 0;
	for (int i = 0; i < 42; i++) {
		if (a[i] > 0) ans += 1;
	}
	cout << ans << '\n';
	return 0;
}
