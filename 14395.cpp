#include <map>
#include <tuple>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	if (n == m) {
		cout << 0 << '\n';
	}
	else if (m == 0) {
		cout << "-\n";
	}
	else if (m == 1) {
		cout << "/\n";
	}
	else {
		queue<pair<long long, string>> q;
		map<long long, int> mp; string ans;
		mp[n] = 1;
		q.push(make_pair(n, ""));
		while (!q.empty()) {
			long long x; string s;
			tie(x, s) = q.front();
			q.pop();

			if (x == m) {
				if (ans.empty()) {
					ans = s;
				}
				else {
					if (ans.size() > s.size()) {
						ans = s;
					}
					else if (ans.size() == s.size()) {
						for (int i = 0; i < ans.size(); i++) {
							if (ans[i] == s[i]) continue;
							else if (ans[i] > s[i]) {
								ans = s;
								break;
							}
						}
					}
				}
			}
			else {
				if (!ans.empty() && s.size() > ans.size()) continue;
				if (x*x <= m && !mp.count(x*x)) {
					string ts = s;
					ts += '*';
					mp[x*x] = 1;
					q.push(make_pair(x*x, ts));
				}
				if (x + x <= m && !mp.count(x + x)) {
					string ts = s;
					ts += '+';
					mp[x + x] = 1;
					q.push(make_pair(x + x, ts));
				}
				if (x == n && !mp.count(x / x)) {
					string ts = s;
					ts += '/';
					mp[x / x] = 1;
					q.push(make_pair(x / x, ts));
				}
			}
		}
		if (ans.empty()) {
			cout << -1 << '\n';
		}
		else {
			for (char p : ans) {
				cout << p;
			}
			cout << '\n';
		}
	}
	return 0;
}
