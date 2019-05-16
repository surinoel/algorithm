#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int mat[10][10];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
  
	int n; cin >> n;
	vector<int> idx;
	for (int i = 0; i < n; i++) {
		idx.push_back(i);
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
		}
	}
	
	int ans = -1;
	do {
		int sum = 0;
		idx.push_back(idx[0]);
		for (int k = 0; k < idx.size() - 1; k++) {
			sum += mat[idx[k]][idx[k + 1]];
			if (mat[idx[k]][idx[k + 1]] == 0 || (ans != -1 && sum > ans)) {
				goto end;
			}
		}
		if (ans == -1 || ans > sum) {
			ans = sum;
		}
		
	end:;
		idx.pop_back();
	} while (next_permutation(idx.begin(), idx.end()));
	
	cout << ans << '\n';
	return 0;
}
