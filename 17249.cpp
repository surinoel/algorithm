#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int pleft, pright;
	pleft = pright = 0;
	bool change = false;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			change = true;
		}
		else {
			if (!change && s[i] == '@') {
				pleft += 1;
			}
			else if (change && s[i] == '@') {
				pright += 1;
			}
		}
	}

	cout << pleft << ' ' << pright << '\n';
	return 0;
}
