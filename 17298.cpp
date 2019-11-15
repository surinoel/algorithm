#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> arr(n + 1);
	vector<int> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	stack<int> st;
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && arr[i] >= st.top()) {
			st.pop();
		}

		if (st.empty()) {
			ans[i] = -1;
		}
		else {
			ans[i] = st.top();
		}

		st.push(arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}
