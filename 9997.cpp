#include <vector>
#include <string>
#include <iostream>

using namespace std;

int n;
vector<int> sumstr;

void go(int idx, int sum, int &ans) {
	if (idx == n) {
		if (sum == (1 << 26) - 1) {
			ans += 1;
		}
		return;
	}

	go(idx + 1, sum | sumstr[idx], ans);
	go(idx + 1, sum, ans);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	cin >> n;
	vector<string> vs(n);
	sumstr.resize(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		vs[i] = s;
		for (int j = 0; j < s.size(); j++) {
			sumstr[i] |= (1 << (s[j] - 'a'));
		}
	}

	int ans = 0;
	go(0, 0, ans);

	cout << ans << '\n';
	return 0;
}
