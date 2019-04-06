#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<char> v;
void go(int idx, int cnt, vector<char> &c) {
	if (cnt == m) {
		int ja = 0, mo = 0;
		for (int k = 0; k < c.size(); k++) {
			if (c[k] == 'a' || c[k] == 'e' || c[k] == 'i' || c[k] == 'o' || c[k] == 'u') {
				mo += 1;
			}
			else {
				ja += 1;
			}
		}
		if (ja >= 2 && mo >= 1) {
			for (char &p : c) {
				cout << p;
			}
			cout << '\n';
		}
		return;
	}
	if (idx == n) {
		return;
	}

	c.push_back(v[idx]);
	go(idx + 1, cnt + 1, c);
	c.pop_back();
	go(idx + 1, cnt, c);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		v.push_back(c);
	}
	sort(v.begin(), v.end());
	vector<char> t;
	go(0, 0, t);
	return 0;
}