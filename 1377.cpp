#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end());
	int ans = -1;
	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i].second - i);
	}
	cout << ans + 1 << '\n';
	return 0;
}
