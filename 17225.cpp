#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

priority_queue <pair<int, char>, vector <pair<int, char>>, greater<pair<int, char>>> pq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b, n;
	cin >> a >> b >> n;
	int maxr = -1, maxb = -1;
	for (int i = 0; i < n; i++) {
		int t, m; char c;
		cin >> t >> c >> m;
		int cnt = 0;
		if (c == 'B') {
			if (maxb > t) t = maxb;
			for (int j = t; cnt < m; j += a) {
				pq.push(make_pair(j, c));
				cnt += 1;
			}
			maxb = t + m*a;
		}
		else {
			if (maxr > t) t = maxr;
			for (int j = t; cnt < m; j += b) {
				pq.push(make_pair(j, c));
				cnt += 1;
			}
			maxr = t + m*b;
		}
	}

	vector<int> ans1, ans2;
	int idx = 1;
	while (!pq.empty()) {
		char c = pq.top().second;
		if (c == 'B') {
			ans1.push_back(idx++);
		}
		else {
			ans2.push_back(idx++);
		}
		pq.pop();
	}

	cout << ans1.size() << '\n';
	for (int i = 0; i < ans1.size(); i++) {
		cout << ans1[i] << ' ';
	}
	cout << '\n';

	cout << ans2.size() << '\n';
	for (int i = 0; i < ans2.size(); i++) {
		cout << ans2[i] << ' ';
	}
	cout << '\n';

	return 0;
}
