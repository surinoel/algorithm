#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s; cin >> s;
	if (s.size() == 1) {
		cout << s << '\n';
	}
	else {
		for (int i = s.size() - 1; i >= 1; i--) {
			string tmp = "";
			int a = s[i - 1] - '0';
			int b = s[i] - '0';
			int val = stoi(s.substr(0, i));
			if (b >= 5 && b <= 9) {
				tmp = to_string(val + 1);
			}
			else {
				tmp = to_string(val);
			}
			for (int j = i; j < s.size(); j++) {
				tmp += '0';
			}
			s = tmp;
		}
		cout << s << '\n';
	}
	return 0;
}
