#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<int> mat[51];
int dist[51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == 'Y') {
				mat[i].push_back(j + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		memset(dist, -1, sizeof(dist));
		queue<int> q;
		q.push(i);
		dist[i] = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			if (dist[x] == 2) break;
			for (int k = 0; k < mat[x].size(); k++) {
				int y = mat[x][k];
				if (dist[y] != -1) continue;
				dist[y] = dist[x] + 1;
				tmp += 1;
				q.push(y);
			}
		}
		ans = max(tmp, ans);
	}

	cout << ans << '\n';
	return 0;
}
