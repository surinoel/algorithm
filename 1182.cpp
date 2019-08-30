#include <vector>
#include <iostream>

using namespace std;

int n, s;
int ans;
vector<int> a;

void go(int idx, int pick, int sum) {
	if (idx == n) {
		if (sum == s && pick > 0) {
			ans += 1;
		}
		return;
	}
	go(idx + 1, pick + 1, sum + a[idx]);
	go(idx + 1, pick, sum);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> s;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	go(0, 0, 0);
	cout << ans << '\n';
	return 0;
}
