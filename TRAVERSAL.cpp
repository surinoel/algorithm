#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> cut(const vector<int>& base, int a, int b) {
	return vector<int>(base.begin() + a, base.begin() + b);
}

void find_postod(const vector<int>& preod, const vector<int>& inod) {
	if (preod.empty()) return;
	int root = preod[0];
	
	int size = preod.size();
	int range = find(inod.begin(), inod.end(), root) - inod.begin();
	find_postod(cut(preod, 1, range + 1), cut(inod, 0, range));
	find_postod(cut(preod, range + 1, size), cut(inod, range + 1, size));
	cout << root << ' ';
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		int n;
		cin >> n;
		vector<int> preod(n), inod(n);
		for (int i = 0; i < n; i++) {
			cin >> preod[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> inod[i];
		}

		find_postod(preod, inod);
		cout << '\n';
	}

	return 0;
}
