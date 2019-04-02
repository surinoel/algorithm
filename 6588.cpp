#include <iostream>

using namespace std;

bool check[1000001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	check[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (check[i] == false) {
			for (int j = i + i; j <= 1000000; j += i) {
				check[j] = true;
			}
		}
	}

	freopen("data.txt", "r", stdin);
	while (true) {
		int x;
		cin >> x;
		if (x == 0) {
			break;
		}
		bool ok = false;
		for (int i = 2; i <= x / 2; i++) {
			if (check[i]) continue;
			int diff = x - i;
			if (check[diff]) continue;
			cout << x << " = " << i << " + " << diff << '\n';
			ok = true;
			break;
		}

		if (!ok) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}