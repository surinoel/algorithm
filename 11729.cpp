#include <cmath>
#include <iostream>

using namespace std;

void hanoi(int n, int start, int mid, int end) {
	if (n == 0) {
		return;
	}
	hanoi(n - 1, start, end, mid);
	cout << start << ' ' << end << '\n';
	hanoi(n - 1, mid, start, end);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << '\n';
	hanoi(n, 1, 2, 3);
	return 0;
}
