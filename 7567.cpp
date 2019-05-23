#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ans = 0;
	string s;
	cin >> s;
	ans += 10;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			ans += 5;
		}
		else {
			ans += 10;
		}
	}

	cout << ans << '\n';
	return 0;
}
