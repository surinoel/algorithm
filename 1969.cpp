#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

int cnt[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<string> vs(n);
	for (int i = 0; i < n; i++) {
		cin >> vs[i];
	}

	string ans1 = "";
	int ans2 = 0;

	for (int j = 0; j < m; j++) {
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			cnt[vs[i][j] - 'A'] += 1;
		}
		int maxcnt = 0;
		char maxchar;
		for (int i = 0; i < 26; i++) {
			if (cnt[i] > maxcnt) {
				maxchar = (char)('A' + i);
				maxcnt = cnt[i];
			}
		}
		ans1 += maxchar;
		ans2 += n - maxcnt;
	}

	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
