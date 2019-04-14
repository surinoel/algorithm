#include <iostream>
#include <algorithm>

using namespace std;

long long d[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i - 3 >= 1) {
			for (int j = 1; j <= i - 3; j++) {
				d[i] = max(d[i], d[j] * ((i - 3) - j + 2));
			}
		}
	}
	cout << d[n] << '\n';
	return 0;
}
