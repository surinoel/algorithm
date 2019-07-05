#include <vector>
#include <iostream>

using namespace std;

vector<int> inod, postod;

void find_preod(int a, int b, int c, int d) {
	if (b - a <= 0 || d - c <= 0) return;
	
	int root = postod[d - 1];
	int range = a;
	for (int i = a; i < b; i++) {
		if (inod[i] == root) { 
			range = i;
		}
	}
	
	cout << root << ' ';
	find_preod(a, range, c, c + range - a);
	find_preod(range + 1, b, c + range - a, d - 1);
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	inod.resize(n), postod.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> inod[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postod[i];
	}

	find_preod(0, n, 0, n);
	return 0;
}
