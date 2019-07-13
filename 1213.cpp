#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int cnt[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'A'] += 1;
	}
	bool ok = true;
	int countOdd = 0;
	string odd = "";
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2) {
			countOdd += 1;
			odd = 'A' + i;
		}
	}

	if (countOdd > 1) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}
	
	string ans = "";
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < cnt[i] / 2; j++) {
			ans += 'A' + i;
		}
	}

	string retmp = ans;
	reverse(retmp.begin(), retmp.end());

	cout << ans + odd + retmp << '\n';
	return 0;
}
