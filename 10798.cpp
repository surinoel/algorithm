#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int max_size = 0;
	vector<string> vstring;
	while (1) {
		string s; cin >> s;
		if (s == "") break;
		if (s.size() > max_size) {
			max_size = s.size();
		}
		vstring.push_back(s);
	}

	for (int i = 0; i < vstring.size(); i++) {
		for (int j = vstring[i].size(); j < max_size; j++) {
			vstring[i].push_back('+');
		}
	}

	for (int j = 0; j < max_size; j++) {
		for (int i = 0; i < vstring.size(); i++) {
			if (vstring[i][j] == '+') continue;
			cout << vstring[i][j];
		}
	}
	cout << '\n';

	return 0;
}
