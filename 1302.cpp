#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	map<string, int> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (!m.count(s)) {
			m[s] = 1;
		}
		else {
			m[s] += 1;
		}
	}

	vector<pair<string, int>> v;
	for (auto it = m.begin(); it != m.end(); ++it) {
		v.push_back(make_pair(it->first, it->second));
	}

	sort(v.begin(), v.end(), [](const pair<string, int> &u, const pair<string, int> &v) {
		if (u.second == v.second) {
			return u.first < v.first;
		}
		return u.second > v.second;
	});

	cout << v[0].first << '\n';

	return 0;
}
