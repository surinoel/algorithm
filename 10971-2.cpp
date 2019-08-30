#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[10][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}

	vector<int> idx;
	for (int i = 1; i < n; i++) {
		idx.push_back(i);
	}

	int ans = -1;
	do {
		bool ok = true;
		int tsum = 0;
		int st = 0;
		for (int i = 0; i < idx.size(); i++) {
			if (mat[st][idx[i]] == 0) {
				ok = false;
				break;
			}
			tsum += mat[st][idx[i]];
			st = idx[i];
		}
		if (mat[st][0] != 0 && ok) {
			tsum += mat[st][0];

			if (ans == -1 || ans > tsum) {
				ans = tsum;
			}
		}
		
	} while (next_permutation(idx.begin(), idx.end()));

	cout << ans << '\n';
	return 0;
}
