#include <string>
#include <sstream>
#include <iostream>

using namespace std;

char change_alpha(char c) {
	if (c >= 'a' && c <= 'z') {
		c -= 32;
	}
	return c;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; 
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		bool ok = true;
		int left = 0, right = s.length() - 1;
		while (left <= right) {
			if (s[left] == ' ' || s[right] == ' ') {
				if (s[left] != s[right]) {
					ok = false;
				}
			}
			else {
				char a = change_alpha(s[left]);
				char b = change_alpha(s[right]);
				if (a != b) {
					ok = false;
				}
			}

			left++;
			right--;
		}
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}
