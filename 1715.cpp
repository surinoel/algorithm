#include <queue>
#include <vector>
#include <iostream>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pq;
	int tc;
	cin >> tc;
	while (tc--) {
		int x;
		cin >> x;
		pq.push(x);
	}

	int ans = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}
	
	cout << ans << '\n';
	return 0;
}
