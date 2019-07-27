#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> a(5);
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}

	sort(a.begin(), a.end());
	for (int i = a[2]; ; i++) {
		int cnt = 0;
		for (int k = 0; k < 5; k++) {
			if (i%a[k] == 0) {
				cnt += 1;
			}
		}
		if (cnt >= 3) {
			cout << i << '\n';
			return 0;
		}
	}
}
