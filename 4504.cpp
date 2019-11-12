#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n;
	cin >> n;
	for (;;) {
		int x;
		cin >> x;
		if (x == 0) break;
		if (x / n > 0 && x % n == 0) {
			cout << x << " is a multiple of " << n << ".\n";
		}
		else {
			cout << x << " is NOT a multiple of " << n << ".\n";
		}
	}

	return 0;
}
