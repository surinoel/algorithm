#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<int>());
	int maxv = v[0] + 1;
	int ans = 1;
	for (int i = 1; i < v.size(); i++) {
		if (maxv > v[i] + n) {
			break;
		}
		maxv = max(maxv, v[i] + i + 1);
		ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
