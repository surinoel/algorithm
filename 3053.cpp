#define _USE_MATH_DEFINES

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int r;
	cin >> r;

	cout << fixed << setprecision(6) << M_PI*r*r << '\n';
	cout << fixed << setprecision(6) << sqrt(2)*r*sqrt(2)*r << '\n';

	return 0;
}
