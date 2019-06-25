#include <vector>
#include <iostream>

using namespace std;

vector<int> a[51];
int dist[51][51];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; 
	cin >> n;
	int inf = 100;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) dist[i][j] = inf;
		}
	}
	while (1) {
		int x, y;
		cin >> x >> y;
		if (x == -1 && y == -1) break;
		a[x].push_back(y);
		a[y].push_back(x);
		dist[x][y] = 1;
		dist[y][x] = 1;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	
	int minval = -1;
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		int maxval = -1;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] > maxval) {
				maxval = dist[i][j];
			}
		}
		if (maxval == inf) continue;
		if (minval == -1 || minval > maxval) {
			minval = maxval;
			ans = vector<int>();
			ans.push_back(i);
		}
		else if(minval == maxval) {
			ans.push_back(i);
		}
	}
	cout << minval << ' ' << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';

	return 0;
}
