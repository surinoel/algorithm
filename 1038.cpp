#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> v = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	vector<int> ans;
	for (int i = 1; i < (1 << 10); i++) {
		long long sum = 0;
		for (int j = 0; j < 10; j++) {
			if (i & (1 << j)) {
				sum = sum * 10 + v[j];
			}
		}
		ans.push_back(sum);
	}
	
	if (n >= ans.size()) {
		cout << -1 << '\n';
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans[n] << '\n';

	return 0;
}
