#include <deque>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n, k;
		cin >> n >> k;
		deque<char> dq(n);
		for (int i = 0; i < n; i++) {
			cin >> dq[i];
		}
		int rotate_cnt = n / 4;
		int u = 0;
		vector<int> ans;
		for (int u = 0; u < rotate_cnt; u++) {
			int idx = 0;
			for (int i = 0; i < 4; i++) {
				vector<char> value;
				for (int j = 0; j < rotate_cnt; j++) {
					value.push_back(dq[idx++]);
				}
				int sum = 0;
				for (int j = 0; j < rotate_cnt; j++) {
					char c = value[j];
					int num;
					if (c >= '0' && c <= '9') num = c - '0';
					else num = 10 + c - 'A';
					sum += num * int(pow(16, rotate_cnt - j - 1));
				}
				ans.push_back(sum);
			}
			char popchar = dq.back();
			dq.pop_back();
			dq.push_front(popchar);
		}

		sort(ans.begin(), ans.end(), greater<int>());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());
		cout << "#" << test_case << " " << ans[k - 1] << '\n';
	}

	return 0;
}
