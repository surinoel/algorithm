#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<char> op;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			if (i == 0) op.push_back('+');
			else if (i == 1) op.push_back('-');
			else if (i == 2) op.push_back('*');
			else if (i == 3) op.push_back('/');
		}
	}

	int minval = INT_MAX, maxval = INT_MIN;
	sort(op.begin(), op.end());
	do {
		int start = a[0];
		for (int i = 0; i < n - 1; i++) {
			if (op[i] == '+') start += a[i + 1];
			else if (op[i] == '-') start -= a[i + 1];
			else if (op[i] == '*') start *= a[i + 1];
			else if (op[i] == '/') start /= a[i + 1];
		}

		minval = min(minval, start);
		maxval = max(maxval, start);
	} while (next_permutation(op.begin(), op.end()));

	cout << maxval << '\n' << minval << '\n';
	return 0;
}
