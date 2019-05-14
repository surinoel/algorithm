#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	while (n--) {
		int x; cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(make_pair(abs(x), x));
		}
	}

	return 0;
}
