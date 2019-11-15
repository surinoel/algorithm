#include <stack>
#include <utility>
#include <iostream>

using namespace std;

int arr[1000001];
int cnt[1000001];
int ans[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i]] += 1;
	}

	stack<pair<int, int>> st;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && cnt[arr[i]] >= st.top().first) {
			st.pop();
		}

		if (st.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = st.top().second;
		}

		st.push(make_pair(cnt[arr[i]], arr[i]));
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}

	cout << '\n';
	return 0;
}
