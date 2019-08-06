#include <cstring>
#include <iostream>

using namespace std;

#define min(n, m) n > m ? m : n

int price[4];
int month[13];

void go(int idx, int sum, int &ans) {
	if (idx > 12) {
		ans = min(ans, sum);
		return;
	}

	if (month[idx] == 0) {
		go(idx + 1, sum, ans);
	}
	else {
		go(idx + 1, sum + price[0] * month[idx], ans);
		go(idx + 1, sum + price[1], ans);
		go(idx + 3, sum + price[2], ans);
	}
	
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		for (int i = 0; i < 4; i++) {
			cin >> price[i];
		}
		for (int i = 1; i <= 12; i++) {
			cin >> month[i];
		}

		int ans = 1e8;
		go(0, 0, ans);
		ans = min(ans, price[3]);

		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
