#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; string s;
	cin >> n;
	getline(cin, s);
	while (n--) {
		getline(cin, s);
		if(s[0] >= 'a' && s[0] <= 'z') s[0] -= ('a' - 'A');
		cout << s << '\n';
	}

	return 0;
}
