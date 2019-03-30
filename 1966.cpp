#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> p(n);
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
	
		deque<int> q;
		for (int i = 0; i < n; i++) {
			q.push_back(i);
		}

		vector<int> ans;
		while(!q.empty()) {
			int x;
			x = q.front();
			q.pop_front();
			bool ok = true;
			for (int i = 0; i < q.size(); i++) {
				if (p[x] < p[q[i]]) {
					ok = false;
					break;
				}
			}
			if (!ok) {
				q.push_back(x);
			}
			else {
				ans.push_back(x);
			}
		}

		for (int i = 0; i < n; i++) {
			if (ans[i] == m) {
				cout << i + 1 << '\n';
				break;
			}
		}
	}
	return 0;
}