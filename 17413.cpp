#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	getline(cin, s);
	string tmp = "";
	bool ok = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '<') {
			if (tmp != "") {
				reverse(tmp.begin(), tmp.end());
				cout << tmp;
			}
			ok = true;
			tmp = s[i];
		}
		else if (s[i] == '>') {
			ok = false;
			tmp += s[i];
			cout << tmp;
			tmp = "";
		}
		else if (!ok && s[i] == ' ') {
			reverse(tmp.begin(), tmp.end());
			cout << tmp << ' ';
			tmp = "";
		}
		else {
			tmp += s[i];
		}

		if (i == s.size() - 1 && tmp != "") {
			reverse(tmp.begin(), tmp.end());
			cout << tmp;
		}
	}

	cout << '\n';
	return 0;
}
