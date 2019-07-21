#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (1) {
		string s;
		cin >> s;
		if (s == "end") break;
		bool ok1 = false;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
				|| s[i] == 'o' || s[i] == 'u') {
				ok1 = true;
				break;
			}
		}
		if (ok1) {
			bool ok2 = true;
			char c = s[0];
			int jaeum = 0, moeum = 0;
			if (c == 'a' || c == 'e' || c == 'i'
				|| c == 'o' || c == 'u') {
				moeum += 1;
			}
			else {
				jaeum += 1;
			}
			for (int i = 1; i < s.size(); i++) {
				if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i'
					|| s[i] == 'o' || s[i] == 'u') {
					jaeum = 0;
					if (++moeum == 3) {
						ok2 = false;
						break;
					}
				}
				else {
					moeum = 0;
					if (++jaeum == 3) {
						ok2 = false;
						break;
					}
				}
			}
			if (ok2) {
				bool ok3 = true;
				char c = s[0];
				for (int i = 1; i < s.size(); i++) {
					if (s[i] == c && c != 'e' && c != 'o') {
						ok3 = false;
					}
					c = s[i];
				}
				if (ok3) {
					cout << "<" << s << "> is acceptable.\n";
				}
				else {
					cout << "<" << s << "> is not acceptable.\n";
				}
			}
			else {
				cout << "<" << s << "> is not acceptable.\n";
			}
		}
		else {
			cout << "<" << s << "> is not acceptable.\n";
		}
	}
	return 0;
}
