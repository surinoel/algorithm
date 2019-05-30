#include <iostream>
#include <algorithm>

using namespace std;

int d[1000000];
int sleft[1000000];
int sright[1000000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	
	int mleft = d[0];
	sleft[0] = d[0];
	for (int i = 1; i < n - 1; i++) {
		if (d[i] > mleft) {
			sleft[i] = d[i];
			mleft = d[i];
		}
		else {
			sleft[i] = mleft;
		}
	}

	int mright = d[n - 1];
	sright[n - 1] = d[n - 1];
	for (int i = n - 1; i > 0; i--) {
		if (d[i] > mright) {
			sright[i] = d[i];
			mright = d[i];
		}
		else {
			sright[i] = mright;
		}
	}

	int rvic, bvic;
	rvic = bvic = 0;
	for (int i = 0; i < n - 1; i++) {
		if (sleft[i] > sright[i + 1]) {
			rvic += 1;
		}
		else if (sleft[i] < sright[i + 1]) {
			bvic += 1;
		}
	}

	if (rvic == bvic) {
		cout << "X\n";
	}
	else if (rvic > bvic) {
		cout << "R\n";
	}
	else {
		cout << "B\n";
	}

	return 0;
}
