#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		check[a[i]] = true;
	}
	int k;
	cin >> k;
	if (check[k]) {
		cout << 0 << '\n';
	}
	else {
		a.push_back(k);
		sort(a.begin(), a.end());
		int idx;
		for (int i = 0; i < n + 1; i++) {
			if (a[i] == k) {
				idx = i;
				break;
			}
		}
		int left, right;
		left = (k - 1) - a[idx - 1];
		if (left < 0) left = 0;
		right = (a[idx + 1] - 1) - k;
		if (right < 0) right = 0;
		int ans = left + right + left*right;
		cout << ans << '\n';
	}

	return 0;
}
