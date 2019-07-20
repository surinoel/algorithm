#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n;
	cin >> n;
	vector<string> vs(n);
	int base = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vs[i] = s;
		for (int j = 0; j < s.size() - 1; j++) {
			if (s[j] != s[j + 1]) {
				base += 1;
			}
		}
	}
	vector<int> idx(n);
	for (int i = 0; i < n; i++) {
		idx[i] = i;
	}
	int ans = -1;
	do {
		int cnt = 0;
		for (int i = 0; i < n - 1; i++) {
			if (vs[idx[i]][vs[idx[i]].size() - 1] != vs[idx[i + 1]][0]) {
				cnt += 1;
			}
		}
		if (ans == -1 || ans > cnt) {
			ans = cnt;
		}
	} while (next_permutation(idx.begin(), idx.end()));

	cout << base + ans << '\n';
	return 0;
}
