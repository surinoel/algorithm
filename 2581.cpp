#include <iostream>

using namespace std;

bool check[10001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	check[1] = true;
	for (int i = 2; i <= 10000; i++) {
		if (check[i]) continue;
		for (int j = i + i; j <= 10000; j += i) {
			check[j] = true;
		}
	}

	int n, m;
	cin >> n >> m;

	int ans;
	int sum = 0;
	bool ok = true;
	for (int i = n; i <= m; i++) {
		if (!check[i]) {
			if (ok) {
				ans = i;
				ok = false;
			}
			sum += i;
		}
	}
	if (ok) {
		cout << "-1\n";
		return 0;
	}
	cout << sum << '\n' << ans << '\n';
}