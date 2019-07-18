#include <string>
#include <vector>
#include <iostream>

using namespace std;

int alpha[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	while (getline(cin, s)) {
		for (int i = 0; i < s.size(); i++) {
			alpha[s[i] - 'a'] += 1;
		}
	}

	vector<int> ans;
	int maxv = -1;
	for (int i = 0; i < 26; i++) {
		if (maxv < alpha[i]) {
			maxv = alpha[i];
			ans = vector<int>();
			ans.push_back(i);
		}
		else if (maxv == alpha[i]) {
			ans.push_back(i);
		}
	}

	for (auto c : ans) {
		cout << (char)('a' + c);
	}
	cout << '\n';

	return 0;
}
