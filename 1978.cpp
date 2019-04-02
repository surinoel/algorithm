#include <iostream>

using namespace std;

bool prime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i*i <= x; i++) {
		if (x%i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (prime(x)) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}