#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int a[10];

void go(int idx, int cnt, int sum, vector<int> &v) {
	if (idx <= 9 && cnt == 7 && sum == 100) {
		for (auto x : v) {
			cout << x << '\n';
		}
		exit(0);
		return;
	}
	if (idx == 9) return;

	v.push_back(a[idx]);
	go(idx + 1, cnt + 1, sum + a[idx], v);
	v.pop_back();
	go(idx + 1, cnt, sum, v);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = 9;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<int> v;
	go(0, 0, 0, v);
	return 0;
}
