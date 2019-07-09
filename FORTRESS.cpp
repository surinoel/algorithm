#include <queue>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

struct circle {
	int x, y, r;
	circle() {}
	circle(int x, int y, int r) : x(x), y(y), r(r) {

	}
};

vector<circle> a;		
vector<int> tree[101];	
vector<pair<int, int>> p;
int dist[101];				
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("data.txt", "r", stdin);
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dist, -1, sizeof(dist));
		int n;
		cin >> n;
		a = vector<circle>(n + 1);
		p = vector<pair<int, int>>(n + 1);
		for (int i = 1; i <= n; i++) {
			int x, y, r;
			cin >> x >> y >> r;
			a[i] = circle(x, y, r);
			tree[i] = vector<int>();
		}

		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int x1, y1, r1, x2, y2, r2;
				x1 = a[i].x, y1 = a[i].y, r1 = a[i].r;
				x2 = a[j].x, y2 = a[j].y, r2 = a[j].r;

				int d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
				if (d > ((r1 + r2) * (r1 + r2))) continue;
				if (!(d < ((r1 - r2) * (r1 - r2)))) continue;

				if (r1 > r2) {
					if (p[j].second != 0) {
						if (p[j].second > r1) {
							p[j] = make_pair(i, r1);
						}
					}
					else {
						p[j] = make_pair(i, r1);
					}
				}
				else {
					if (p[i].second != 0) {
						if (p[i].second > r2) {
							p[i] = make_pair(j, r2);
						}
					}
					else {
						p[i] = make_pair(j, r2);
					}
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (p[i].first == 0) {
				tree[0].push_back(i);
				tree[i].push_back(0);
			}
			else {
				tree[p[i].first].push_back(i);
				tree[i].push_back(p[i].first);
			}
		}

		queue<int> q;
		q.push(0);
		dist[0] = 0;
		int node = 0, mdist = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (int k = 0; k < tree[x].size(); k++) {
				int y = tree[x][k];
				if (dist[y] != -1) continue;
				dist[y] = dist[x] + 1;
				if ((mdist == 0 || dist[y] > mdist) && y != 0) {
					mdist = dist[y];
					node = y;
				}
				q.push(y);
			}
		}

		memset(dist, -1, sizeof(dist));
		dist[node] = 0;
		q = queue<int>();
		q.push(node);
		mdist = 0;
		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int k = 0; k < tree[x].size(); k++) {
				int y = tree[x][k];
				if (dist[y] != -1) continue;
				dist[y] = dist[x] + 1;
				if ((mdist == 0 || dist[y] > mdist) && y != 0) {
					mdist = dist[y];
				}
				q.push(y);
			}
		}

		cout << mdist << '\n';
	}

	return 0;
}
