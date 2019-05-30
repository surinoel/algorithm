#include <map>
#include <cmath>
#include <climits>
#include <iostream>

using namespace std;

map<int, int> m;

void go(int p, int sum) {
	if ((uint32_t)pow(3, p) > INT_MAX) {
		return;
	}

	m[sum + (int)pow(3, p)] = 1;
	go(p + 1, sum + (int)pow(3, p));
	go(p + 1, sum);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	go(0, 0);
	int n;
	cin >> n;
	if (!m.count(n)) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	return 0;
}
