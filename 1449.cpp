#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(check, true, sizeof(check));
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check[a[i]] = false;
	}
	sort(a.begin(), a.end());

	int ans = 0;
	for (;;) {
		for (int i = 0; i < a.size(); i++) {
			int y = a[i];
			if (!check[y]) {
				ans += 1;
				for (int j = y; j <= y + m - 1; j++) {
					check[j] = true;
				}
			}
		}

		bool ok = true;
		for (int i = 0; i < a.size(); i++) {
			if (!check[a[i]]) {
				ok = false;
			}
		}
		if (ok) break;
	}

	cout << ans << '\n';
	return 0;
}
