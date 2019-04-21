 #include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> top(n);
	for (int i = 0; i < n; i++) {
		cin >> top[i];
	}
	
	int cnt = -1;
	for (int i = 0; i < n; i++) {
		vector<int> ans(n);
		ans[i] = top[i];
		bool ok = true;
		for (int j = i - 1; j >= 0; j--) {
			ans[j] = ans[j + 1] - k;
			if (ans[j] < 1) {
				ok = false;
				break;
			}
		}
		for (int j = i + 1; j < n; j++) {
			ans[j] = ans[j - 1] + k;
			if (ans[j] < 1) {
				ok = false;
				break;
			}
		}

		if (!ok) continue;

		int ccnt = 0;
		for (int j = 0; j < n; j++) {
			if (ans[j] != top[j]) ccnt += 1;
		}
		if (cnt == -1 || cnt > ccnt) {
			cnt = ccnt;
		}
	}

	cout << cnt << '\n';
	return 0;
}
