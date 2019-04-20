#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s1; int s2;
	cin >> s1 >> s2;
	vector<int> v1(s1.size());
	for (int i = 0; i < s1.size(); i++) {
		v1[i] = s1[i] - '0';
	}
	
	sort(v1.begin(), v1.end());
	int ans = -1;

	do {
		if (v1[0] == 0) continue;
		int val = 0;
		for (int i = 0; i < v1.size(); i++) {
			val = val * 10 + v1[i];
		}

		if (val <= s2) {
			ans = val;
		}
		else {
			break;
		}

	} while (next_permutation(v1.begin(), v1.end()));

	cout << ans << '\n';

	return 0;
}
