#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<int, int>> food(n);

	for (int i = 0; i < n; i++) {
		cin >> food[i].first >> food[i].second;
	}

	int ans = -1;
	for (int i = 0; i < (1 << n); i++) {
		int a = 1, b = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				a *= food[j].first;
				b += food[j].second;
			}
		}
		if (!(a == 1 && b == 0)) {
			int tmp = a - b;
			if (tmp < 0) tmp = -tmp;
			if (ans == -1 || ans > tmp) {
				ans = tmp;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}
