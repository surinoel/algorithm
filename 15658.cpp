#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int n;
int ans1 = INT_MIN;
int ans2 = INT_MAX;
vector<int> num;

void go(int idx, int sum, int p, int mi, int mu, int d) {
	if (idx == n) {
		if (sum > ans1) {
			ans1 = sum;
		}
		if (ans2 > sum) {
			ans2 = sum;
		}
		return;
	}

	if (p > 0) {
		go(idx + 1, sum + num[idx], p - 1, mi, mu, d);
	}
	if (mi > 0) {
		go(idx + 1, sum - num[idx], p, mi - 1, mu, d);
	}
	if (mu > 0) {
		go(idx + 1, sum * num[idx], p, mi, mu - 1, d);
	}
	if (d > 0) {
		go(idx + 1, sum / num[idx], p, mi, mu, d - 1);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	num.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int p, mi, mu, d;
	cin >> p >> mi >> mu >> d;
	go(1, num[0], p, mi, mu, d);

	cout << ans1 << '\n' << ans2 << '\n';
	return 0;
}
