#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, n;
	int time = 210;
	cin >> k >> n;
	vector<int> a = { 1, 2, 3, 4, 5, 6, 7, 8 };
	k -= 1;
	for (int i = 0; i < n; i++) {
		int t; 
		char c;
		cin >> t >> c;
		if (time - t <= 0) {
			cout << a[k] << '\n';
			break;
		}
		time -= t; 
		if (c == 'T') {
			if (++k == 8) k = 0;
		}
	}
	return 0;
}
