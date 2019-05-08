#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const pair<char, int> &u, const pair<char, int> &v) {
	if (u.first == v.first) {
		return u.second < v.second;
	}
	return u.first < v.first;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<char, int>> v, cmp;
	stack<pair<char, int>> st;
	for (int i = 0; i < 5 * n; i++) {
		char c, blank; int x;
		cin >> c >> blank >> x;
		v.push_back(make_pair(c, x));
	}
	cmp = v;
	sort(cmp.begin(), cmp.end(), comp);
	int cmpidx = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == cmp[cmpidx]) {
			cmpidx++;
		}
		else if (!st.empty()) {
			if (st.top() == cmp[cmpidx]) {
				i--;
				cmpidx++;
				st.pop();
			}
			else {
				st.push(v[i]);
			}
		}
		else {
			st.push(v[i]);
		}
	}

	if (st.empty()) {
		cout << "GOOD\n";
	}
	else {
		while (!st.empty()) {
			if (st.top() == cmp[cmpidx++]) {
				st.pop();
			}
			else {
				cout << "BAD\n";
				return 0;
			}
		}
		cout << "GOOD\n";
	}

	return 0;
}
