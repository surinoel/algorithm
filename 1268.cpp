#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<int> cls[6][10];
int mat[1001][6];
bool check[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> mat[i][j];
			cls[j][mat[i][j]].push_back(i);
		}
	}

	int ans = -1;
	int aidx = -1;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		memset(check, false, sizeof(check));
		for (int j = 1; j <= 5; j++) {
			int x = mat[i][j];
			for (int k = 0; k < cls[j][x].size(); k++) {
				if (!check[cls[j][x][k]]) {
					check[cls[j][x][k]] = true;
					cnt += 1;
				}
			}
		}
		if (ans == -1 || cnt > ans) {
			ans = cnt;
			aidx = i;
		}
	}

	cout << aidx << '\n';
	return 0;
}
