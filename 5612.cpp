#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	int ans = m;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (m + x - y < 0) {
			cout << 0 << '\n';
			return 0;
		}
		m += x - y;
		ans = max(ans, m);
	}

	cout << ans << '\n';
	return 0;
}
