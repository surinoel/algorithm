#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int left = a[0];
	int right = a[n - 1];
	int mid = (left + right) / 2;

	int ans = -1;
	while (left <= right) {
		int cnt = 1;
		int wifi = a[0];
		for (int i = 1; i < n; i++) {
			if (a[i] - wifi >= mid) {
				cnt += 1;
				wifi = a[i];
			}
		}

		if (cnt >= m) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}
	
	cout << ans << '\n';
	return 0;
}
