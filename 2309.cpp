#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int a[9];

void go(int cnt, int sum, int select) {
	if (cnt == 7) {
		if (sum == 100) {
			vector<int> ans;
			for (int i = 0; i < 9; i++) {
				if (select & (1 << i)) {
					ans.push_back(a[i]);
				}
			}
			sort(ans.begin(), ans.end());
			for (int i = 0; i < 7; i++) {
				cout << ans[i] << '\n';
			}
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (!(select & (1 << i))) {
			go(cnt + 1, sum + a[i], select | (1 << i));
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie();

	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}

	go(0, 0, 0);
	return 0;
}
