#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

#define max(n, m) n > m ? n : m

vector<pair<int, int>> mat[100001];
bool visit[100001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k = -1;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, d;
		cin >> x >> y >> d;
		mat[x].push_back(make_pair(y, d));
		mat[y].push_back(make_pair(x, d));
		k = max(k, d);
	}
	int st, ex;
	cin >> st >> ex;

	int ans;
	int left, right, mid;
	left = 1, right = k;
	mid = (left + right) / 2;
	while (left <= right) {
		memset(visit, false, sizeof(visit));
		queue<int> q;
		q.push(st);
		visit[st] = true;

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < mat[x].size(); i++) {
				int node = mat[x][i].first;
				int dist = mat[x][i].second;
				if (!visit[node] && dist >= mid) {
					visit[node] = true;
					q.push(node);
				}
			}
		}

		if (visit[ex]) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}

		mid = (left + right) / 2;
	}
	
	cout << ans << '\n';
	return 0;
}
