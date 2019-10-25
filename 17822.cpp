#include <tuple>
#include <queue>
#include <deque>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, t;
	cin >> n >> m >> t;
	vector<deque<int>> vq;
	double tsum = 0;
	int tnum = 0;
	for (int i = 0; i < n; i++) {
		deque<int> dq;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			tsum += x;
			tnum += 1;
			dq.push_back(x);
		}
		vq.push_back(dq);
	}
	
	while (t--) {
		int x, d, k;
		cin >> x >> d >> k;
		int st = x - 1;
		for (int i = st; i < n; i += x) {
			if (d == 0) {
				for (int j = 0; j < k; j++) {
					int b = vq[i].back();
					vq[i].pop_back();
					vq[i].push_front(b);
				}
			}
			else {
				for (int j = 0; j < k; j++) {
					int b = vq[i].front();
					vq[i].pop_front();
					vq[i].push_back(b);
				}
			}
		}

		vector<vector<int>> visit(n, vector<int>(m, false));
		bool tok = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visit[i][j] || vq[i][j] == 1e8) continue;
				
				bool ok = false;
				int base = vq[i][j];
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				visit[i][j] = true;

				while (!q.empty()) {
					int ti, tj;
					tie(ti, tj) = q.front();
					q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int u = ti + dx[dir];
						int v = tj + dy[dir];

						if (u == -1 || u == n) continue;
						if (v == m) v = 0;
						else if (v == -1) v = m - 1;

						if (vq[u][v] == 1e8 || visit[u][v]) continue;
						if (vq[u][v] == base) {
							vq[u][v] = 1e8;
							q.push(make_pair(u, v));
							visit[u][v] = true;
							tsum -= base;
							tnum -= 1;
							ok = true;
							tok = true;
						}
					}
				}
 			
				if (ok) {
					vq[i][j] = 1e8;
					tsum -= base;
					tnum -= 1;
				}
			}
		}
		
		if(!tok && tnum > 0) {
			double avg = tsum / tnum;
			for (int ti = 0; ti < n; ti++) {
				for (int tj = 0; tj < m; tj++) {
					if (vq[ti][tj] == 1e8) continue;
					if (avg > vq[ti][tj]) {
						vq[ti][tj] += 1;
						tsum += 1;
					}
					else if (avg < vq[ti][tj]) {
						vq[ti][tj] -= 1;
						tsum -= 1;
					}			
				}
			}
		}
	}

	cout << (int)tsum << '\n';
	return 0;
}
