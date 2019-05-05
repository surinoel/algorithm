#include <iostream>

using namespace std;

int d[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	d[0] = d[1] = 1;
	for (int i = 2; i <= 50; i++) {
		d[i] = 1;
		d[i] += (d[i - 1] % 1000000007 + d[i - 2] % 1000000007) % 1000000007;
	}
	
	int n;
	cin >> n;
	cout << d[n] % 1000000007 << '\n';
	return 0;
}
