#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;
	
	cout << abs(n - m) << '\n';
	return 0;
}
