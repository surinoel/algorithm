#include <string>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m
#define min(n, m) n > m ? m : n

int mat[2501][50][50];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			string s; cin >> s;
			for (int k = 0; k < s.size(); k++) {
				if (s[k] == 'X') mat[i][j][k] = -1;
			}
		}
	}

	int ans = -1;
	pair<int, int> p;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			int sum = 35;
			for (int u = 0; u < 5; u++) {
				for (int v = 0; v < 7; v++) {
					if (mat[i][u][v] != mat[j][u][v]) {
						sum -= 1;
					}
				}
			}
			if (ans == -1 || sum > ans) {
				p.first = min(i, j);
				p.second = max(i, j);
				ans = sum;
			}
		}
	}
	
	cout << p.first << ' ' << p.second << '\n';
	return 0;
}
