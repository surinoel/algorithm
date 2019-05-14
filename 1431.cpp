#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	vector<pair<string,int>> st(n);
	for (int i = 0; i < n; i++) {
		cin >> st[i].first;
		int sum = 0;
		for (int j = 0; j < st[i].first.size(); j++) {
			if (st[i].first[j] >= '0' && st[i].first[j] <= '9') {
				sum += st[i].first[j] - '0';
			}
		}
		st[i].second = sum;
	}
	
	sort(st.begin(), st.end(), [](const pair<string, int> &u, const pair<string, int> &v) {
		if (u.first.length() != v.first.length()) {
			return u.first.length() < v.first.length();
		}
		else {
			if (u.second != v.second) {
				return u.second < v.second;
			}
			else {
				return u.first < v.first;
			}
		}
	});

	for (int i = 0; i < n; i++) {
		cout << st[i].first << '\n';
	}

	return 0;
}
