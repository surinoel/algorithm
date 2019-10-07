#include <map>
#include <string>
#include <iostream>

using namespace std;

map<string, int> m1;
map<string, string> m2;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		m1[s] = i + 1;
		m2[to_string(i + 1)] = s;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if (m1.count(s)) {
			cout << m1[s] << '\n';
		}
		else if (m2.count(s)) {
			cout << m2[s] << '\n';
		}
	}

	return 0;
}
