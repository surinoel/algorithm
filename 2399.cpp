#include <cmath>
#include <vector>
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
	
	long long sum = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			sum += abs(a[i] - a[j]) * 2;
		}
	}

	cout << sum << '\n';
	return 0;
}
