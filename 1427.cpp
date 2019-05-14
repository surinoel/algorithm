#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	vector<char> v;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end(), [](char &a, char &b) {
		return a > b;
	});

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
	cout << '\n';

	return 0;
}
