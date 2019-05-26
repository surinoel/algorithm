#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long ans = -1;
	for (int i = 0; i < n; i++) {
		long long tmp = v[i] * (n - i);
		if (ans == -1 || tmp > ans) {
			ans = tmp;
		}
	}
	cout << ans << '\n';
	return 0;
}
