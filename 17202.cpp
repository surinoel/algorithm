#include <string>
#include <iostream>

using namespace std;

string go(string s) {
	if (s.size() == 2) {
		return s;
	}

	string tmp = "";
	for (int i = 0; i < s.size() - 1; i++) {
		tmp += (((s[i] - '0') + (s[i + 1] - '0')) % 10) + '0';
	}

	return go(tmp);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1, s2;
	cin >> s1 >> s2;

	string s = "";
	for (int i = 0; i < 8; i++) {
		s += s1[i];
		s += s2[i];
	}

	cout << go(s) << '\n';
	return 0;
}
