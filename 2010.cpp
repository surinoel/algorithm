#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		ans += (m - 1);
	}

	cout << ans + 1 << '\n';
	return 0;
}
