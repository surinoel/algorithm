#include <cmath>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	string s = to_string(n);
	int len = s.size();

	int ans = 0;
	ans = len * (n - (int)pow(10, len - 1) + 1);
	for (int i = len - 1; i >= 1; i--) {
		ans += 9 * (int)pow(10, i - 1) * i;
	}

	cout << ans << '\n';
	return 0;
}
