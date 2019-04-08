#include <iostream>
#include <deque>

using namespace std;

int ans = -1;
int n, k;
int num[50];

void go(int idx, int cnt, deque<int> &d) {
	if (idx == k) {
		if (ans == -1 || ans > cnt) {
			ans = cnt;
		}
		return;
	}

	int val = num[idx];
	deque<int> left(d), right(d);
	// left
	int lcnt = 0;
	while (left.front() != val) {
		int x = left.front();
		left.pop_front();
		left.push_back(x);
		lcnt += 1;
	}
	left.pop_front();
	// right
	int rcnt = 0;
	while (right.front() != val) {
		int y = right.back();
		right.pop_back();
		right.push_front(y);
		rcnt += 1;
	}
	right.pop_front();

	if (lcnt > rcnt) {
		go(idx + 1, cnt + rcnt, right);
	}
	else {
		go(idx + 1, cnt + lcnt, left);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	deque<int> dq(n);
	for (int i = 0; i < n; i++) {
		dq[i] = i + 1;
	}
	for (int i = 0; i < k; i++) {
		cin >> num[i];
	}

	go(0, 0, dq);
	cout << ans << '\n';

	return 0;
}