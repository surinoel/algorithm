#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) % 3 == 0) printf("..*.");
		else printf("..#.");
		if (i == s.size() - 1) printf(".\n");
	}
	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) % 3 == 0) printf(".*.*");
		else printf(".#.#");
		if (i == s.size() - 1) printf(".\n");
	}
	for (int i = 0; i < s.size(); i++) {
		if (i > 0 && i % 3 == 0 || (i + 1) % 3 == 0) printf("*");
		else printf("#");
		if ((i + 1) % 3 == 0) printf(".%c.", s[i]);
		else printf(".%c.", s[i]);
		if (i == s.size() - 1) {
			if ((i + 1) % 3 == 0) printf("*\n");
			else printf("#\n");
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) % 3 == 0) printf(".*.*");
		else printf(".#.#");
		if (i == s.size() - 1) printf(".\n");
	}
	for (int i = 0; i < s.size(); i++) {
		if ((i + 1) % 3 == 0) printf("..*.");
		else printf("..#.");
		if (i == s.size() - 1) printf(".\n");
	}

	return 0;
}
