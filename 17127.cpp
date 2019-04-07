#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans = -1;
vector<int> v;

void go(int idx, int sum, vector<int> &c) {
	if (idx == 4) {
		if (sum != n) return;
		
		int ss = 0;
		int start = 0;
		int tmp = 1;
		for (int k = 0; k < 4; k++) {
			int tmp = 1;
			for (int i = start; i < start + c[k]; i++) {
				tmp *= v[i];
			}
			start += c[k];
			ss += tmp;
		}
		ans = max(ans, ss);
		return;
	}

	for (int i = 1; i <= n - 3; i++) {
		c.push_back(i);
		go(idx + 1, sum + i, c);
		c.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> c;
	go(0, 0, c);

	cout << ans << '\n';
	return 0;
}
