#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			s[i] = 'A' + ((s[i] + 13) - 'A') % 26;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			s[i] = 'a' + ((s[i] + 13) - 'a') % 26;
		}
	}

	cout << s << '\n';
	return 0;
}
