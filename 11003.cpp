#include <deque>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, L;
	cin >> n >> L;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	deque<pair<int, int>> dq;
	for (int i = 0; i < n; i++) {
		if (dq.size() > 0 && i - dq[0].first > L - 1) {
			dq.pop_front();
		}

		for (int j = dq.size() - 1; j >= 0; j--) {
			if (dq[j].second < a[i]) {
				break;
			}
			dq.pop_back();
		}

		dq.push_back(make_pair(i, a[i]));
		cout << dq[0].second << ' ';
	}
	cout << '\n';
	return 0;
}
