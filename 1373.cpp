#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int len = s.length();

	if (len % 3 == 1) s = "00" + s;
	else if (len % 3 == 2) s = "0" + s;
	
	for (int i = 0; i < s.length(); i += 3) {
		string tmp = s.substr(i, 3);
		if (tmp == "000") cout << 0;
		else if (tmp == "001") cout << 1;
		else if (tmp == "010") cout << 2;
		else if (tmp == "011") cout << 3;
		else if (tmp == "100") cout << 4;
		else if (tmp == "101") cout << 5;
		else if (tmp == "110") cout << 6;
		else if (tmp == "111") cout << 7;
	}
	cout << '\n';

	return 0;
}
