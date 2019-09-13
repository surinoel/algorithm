#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

int a[5];
int tans;
void go(int idx, int cnt, int sum) {
	if (cnt == 3) {
		tans = max(tans, sum % 10);
		return;
	}
	if (idx == 5) {
		return;
	}

	go(idx + 1, cnt + 1, sum + a[idx]);
	go(idx + 1, cnt, sum);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n;
	cin >> n;
	int ans = -1;
	int aidx; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> a[j];
		}
		tans = -1;
		go(0, 0, 0);
		if (ans == -1 || tans >= ans) {
			ans = tans;
			aidx = i + 1;
		}
	}

	cout << aidx << '\n';
	return 0;
}
