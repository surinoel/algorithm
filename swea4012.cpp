#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[16][16];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> mat[i][j];
			}
		}

		vector<int> idx(n, 1);
		for (int i = 0; i < n / 2; i++) {
			idx[i] = 0;
		}
		
		int ans = -1;
		do {
			vector<int> food1, food2;
			for (int i = 0; i < n; i++) {
				if (idx[i] == 0) {
					food1.push_back(i);
				}
				else {
					food2.push_back(i);
				}
			}
			int sum1 = 0, sum2 = 0;
			for (int u = 0; u < food1.size(); u++) {
				for (int v = 0; v < food1.size(); v++) {
					sum1 += mat[food1[u]][food1[v]];
				}
			}
			for (int u = 0; u < food2.size(); u++) {
				for (int v = 0; v < food2.size(); v++) {
					sum2 += mat[food2[u]][food2[v]];
				}
			}
			
			int diff = abs(sum1 - sum2);
			if (ans == -1 || ans > diff) {
				ans = diff;
			}

		} while (next_permutation(idx.begin(), idx.end()));
		
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
