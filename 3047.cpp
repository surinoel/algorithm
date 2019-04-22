#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> num(3);
	for (int i = 0; i < 3; i++) {
		cin >> num[i];
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (num[j] > num[j + 1]) {
				int tmp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = tmp;
			}
		}
	}

	map<char, int> m;
	for (int i = 0; i < 3; i++) {
		m['A' + i] = num[i];
	}
	
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		cout << m[s[i]] << ' ';
	}
	cout << '\n';

	return 0;
}
