#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int len = s.length();

	if (s == "0") {
		cout << s << '\n';
	}
	else {
		string ans = "";
		for (int i = 0; i < len; i++) {
			if (s[i] == '0') ans += "000";
			else if (s[i] == '1') ans += "001";
			else if (s[i] == '2') ans += "010";
			else if (s[i] == '3') ans += "011";
			else if (s[i] == '4') ans += "100";
			else if (s[i] == '5') ans += "101";
			else if (s[i] == '6') ans += "110";
			else if (s[i] == '7') ans += "111";
		}

		for (int i = 0; ; i++) {
			if (ans[i] != '0') {
				cout << ans.substr(i, ans.length()) << '\n';
				break;
			}
		}
	}
	
	return 0;
}
