#include <string>
#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull involution(int a, int b) {
	if (b == 0) {
		return 1;
	}
	else if (b == 1) {
		return a;
	}
	ull tmp = involution(a, b / 2);
	if (b % 2) {
		return tmp * tmp * a;
	}
	else {
		return tmp * tmp;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	ull n;
	cin >> n;
	ull sum = 0;
	for (ull i = 0; i < 40ULL; i++) {
		if (n & (1ULL << i)) {
			sum += (ull)involution(3ULL, i);
		}
	}
	cout << sum << '\n';
	return 0;
}
