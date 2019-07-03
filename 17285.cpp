#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int a = s[0], b = 'C';
	a ^= b;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i];
		c ^= a;
		cout << (char)c;
	}
	cout << '\n';

	return 0;
}
