#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int tc;
	cin >> tc;
	int ans = 0;
	while (tc--) {
		vector<bool> alp(256, false);
		string s;
		cin >> s;
		bool ok = true;
		for (int i = 0; i < s.size(); i++) {
			if (i != 0 && s[i] == s[i - 1]) continue;
			if (alp[s[i]] == true) {
				ok = false;
				break;
			}
			alp[s[i]] = true;
		}
		if (ok) ans += 1;
	}

	cout << ans << '\n';
	return 0;
}
