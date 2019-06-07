#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	priority_queue<long long, vector<long long>, greater<long long>> q;	
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		q.push(x);
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		x = q.top();
		q.pop();
		y = q.top();
		q.pop();
		q.push(x + y);
		q.push(x + y);
	}

	long long ans = 0;
	while (!q.empty()) {
		ans += q.top();
		q.pop();
	}

	cout << ans << '\n';
	return 0;
}
