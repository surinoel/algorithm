#include <tuple>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	priority_queue<pair<int, int>, vector<pair<int,int>>> pq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x < 0) pq.push(make_pair(-x, x));
		else pq.push(make_pair(x, x));
	}
	
	vector<tuple<int, int, int>> ans;
	
	int a = pq.top().second;
	pq.pop();
	while (!pq.empty()) {
		int b = pq.top().second;
		if (a > b) {
			ans.push_back(make_tuple(b, a, abs(a + b)));
		}
		else {
			ans.push_back(make_tuple(a, b, abs(a + b)));
		}
		a = b;
		pq.pop();
	}

	sort(ans.begin(), ans.end(), [](auto &u, auto &v) {
		return get<2>(u) < get<2>(v);
	});

	cout << get<0>(ans[0]) << ' ' << get<1>(ans[0]) << '\n';

	return 0;
}
