#include <string>
#include <iostream>

using namespace std;

int cnt[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cnt[s[i] - 'a'] += 1;
	}
	for (int i = 0; i < 26; i++) {
		cout << cnt[i] << ' ';
	}
	cout << '\n';
	return 0;
}
