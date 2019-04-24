#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc; cin >> tc;
	map<string, bool> m;
	while (tc--) {
		string name, work;
		cin >> name >> work;
		if (work == "enter") {
			m[name] = true;
		}
		else {
			m[name] = false;
		}
	}

	vector<string> person;
	for (auto it = m.begin(); it != m.end(); it++) {
		if (it->second == true) {
			person.push_back(it->first);
		}
	}
	
	sort(person.begin(), person.end(), greater<string>());
	for (auto x : person) {
		cout << x << '\n';
	}
	return 0;
}
