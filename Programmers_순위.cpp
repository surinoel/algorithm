#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int d[101][101];

int solution(int n, vector<vector<int>> results) {
	int answer = 0;

	fill(&d[0][0], &d[n][n + 1], 1e6);
	for (int i = 0; i < results.size(); i++) {
		int x = results[i][0];
		int y = results[i][1];
		d[x][y] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		bool ok = true;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (d[i][j] == 1e6 && d[j][i] == 1e6) {
				ok = false;
				break;
			}
		}
		if (ok) answer += 1;
	}

	return answer;
}
