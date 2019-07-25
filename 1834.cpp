#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n;
	cin >> n;
	long long sum = 0;
	for (int i = 1; i < n; i++) {
		sum += i * n + i;
	}
	cout << sum << '\n';
	return 0;
}
