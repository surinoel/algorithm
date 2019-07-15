#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int money = 1;
	for (int i = 0; i < m; i++) {
		money *= 10;
	}

	int ans = n / money;
	if (n % money >= 5 * (money / 10)) {
		ans += 1;
	}
	cout << ans * money << '\n';
	return 0;
}
