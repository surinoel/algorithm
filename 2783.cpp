#include <iomanip>
#include <iostream>

using namespace std;

#define min(n, m) n > m ? m : n

double gimbab[101];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	double x, y, minv;
	cin >> x >> y;
	gimbab[0] = x / y;

	int n;
	cin >> n;
	minv = gimbab[0];
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		gimbab[i] = x / y;
		minv = min(minv, gimbab[i]);
	}

	cout << fixed << setprecision(2) << minv * 1000 << '\n';

	return 0;
}
