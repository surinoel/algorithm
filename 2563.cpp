#include <iostream>

using namespace std;

bool check[100][100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	int ans = 0;
	while (tc--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (!check[i][j]) {
					check[i][j] = true;
					ans += 1;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
