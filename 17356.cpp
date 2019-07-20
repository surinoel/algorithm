#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double n, m;
	cin >> n >> m;
	double a = (m - n) / 400.0;

	cout << fixed << setprecision(10) << 1.0 / (1 + pow(10, a)) << '\n';
	return 0;
}
