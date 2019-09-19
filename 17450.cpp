#include <vector>
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	vector<double> gz(3);
	for (int i = 0; i < 3; i++) {
		double n, m;
		cin >> n >> m;
		if (n * 10 >= 5000) {
			n = n * 10 - 500;
		}
		else {
			n = n * 10;
		}
		double tmp = (10.0 * m) / n;
		gz[i] = tmp;
	}

	int idx;
	double tmax = -1;
	for (int i = 0; i < 3; i++) {
		if (tmax == -1 || gz[i] > tmax) {
			tmax = gz[i];
			idx = i;
		}
	}

	if (idx == 0) cout << "S\n";
	else if (idx == 1) cout << "N\n";
	else cout << "U\n";

	return 0;
}
