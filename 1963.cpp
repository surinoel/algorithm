#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int dist[10000];
bool prime[10000];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	fill(prime, prime + 10000, true);
	prime[1] = false;
	for (int i = 2; i <= 9999; i++) {
		if (!prime[i]) continue;
		for (int j = i + i; j <= 9999; j += i) {
			prime[j] = false;
		}
	}
	
	int tc;
	cin >> tc;
	while (tc--) {
		memset(dist, -1, sizeof(dist));
		int st, ans;
		cin >> st >> ans;
	
		queue<int> q;
		dist[st] = 0;
		q.push(st);
		while (!q.empty()) {
			int x; x = q.front();
			q.pop();
			int n1 = (x / 1000) % 10;
			int n2 = (x / 100) % 10;
			int n3 = (x / 10) % 10;
			int n4 = (x / 1) % 10;
			
			for (int i = 1; i < 10; i++) {
				int val = i * 1000 + n2 * 100 + n3 * 10 + n4;
				if (prime[val] && dist[val] == -1) {
					dist[val] = dist[x] + 1;
					q.push(val);
				}
			}

			for (int i = 0; i < 10; i++) {
				int val = n1 * 1000 + i * 100 + n3 * 10 + n4;
				if (prime[val] && dist[val] == -1) {
					dist[val] = dist[x] + 1;
					q.push(val);
				}
			}

			for (int i = 0; i < 10; i++) {
				int val = n1 * 1000 + n2 * 100 + i * 10 + n4;
				if (prime[val] && dist[val] == -1) {
					dist[val] = dist[x] + 1;
					q.push(val);
				}
			}

			for (int i = 0; i < 10; i++) {
				int val = n1 * 1000 + n2 * 100 + n3 * 10 + i;
				if (prime[val] && dist[val] == -1) {
					dist[val] = dist[x] + 1;
					q.push(val);
				}
			}
 		}

		if (dist[ans] == -1) {
			cout << "Impossible\n";
		}
		else {
			cout << dist[ans] << '\n';
		}
	}
}
