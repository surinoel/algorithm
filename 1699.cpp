#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int d[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 1; ; i++) {
		if (i*i > 100000) {
			break;
		}
		d[i*i] = 1;
	}
	for (int i = 1; i <= 100000; i++) {
		if (d[i] != 0) continue;
		for (int j = 1; j*j < i; j++) {
			int val = d[j*j] + d[i - j*j];
			if (d[i] == 0 || d[i] > val) {
				d[i] = val;
			}
		}
	}

	int n;
	cin >> n;
	cout << d[n] << '\n';

	return 0;
}