#include <iostream>

using namespace std;

int n, k;
int mat[10][10];
int person[3][21];

int ans;
int p[3];
int cntp[3];
bool visit[11];

bool check_visit() {
	bool ok = true;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false) {
			ok = false;
			break;
		}
	}
	return ok;
}

void dfs(int u, int v) {
	if (p[0] == k && p[1] != k && p[2] != k) {
		ans = 1;
		return;
	}

	if (p[1] == k || p[2] == k) {
		return;
	}
	if (check_visit()) {
		return;
	}

	if (u != 0 && v != 0) {
		cntp[u]++; cntp[v]++;
		if (mat[person[u][cntp[u]]][person[v][cntp[v]]] == 2) {
			p[u] += 1;
			dfs(u, 0);
			p[u] -= 1;
		}
		else if (mat[person[u][cntp[u]]][person[v][cntp[v]]] == 1) {
			if (u == 1) {
				p[v] += 1;
				dfs(v, 0);
				p[v] -= 1;
			}
			else if (v == 1) {
				p[u] += 1;
				dfs(u, 0);
				p[u] -= 1;
			}
		}
		else {
			p[v] += 1;
			dfs(v, 0);
			p[v] -= 1;
		}
		cntp[u]--; cntp[v]--;
	}
	else { 
		if (u == 0)
			cntp[v]++;
		else
			cntp[u]++;

		for (int i = 1; i <= n; i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			if (u == 0) {
				if (mat[i][person[v][cntp[v]]] == 2) { 
					p[0] += 1;
					int tmp_you = (v == 1) ? 2 : 1;
					dfs(0, tmp_you);
					p[0] -= 1;
				}
				else { 
					int tmp_you = (v == 1) ? 2 : 1;
					p[v] += 1;
					dfs(v, tmp_you);
					p[v] -= 1;
				}
			}

			if (v == 0) {
				if (mat[person[u][cntp[u]]][i] == 0) { 
					p[0] += 1;
					int tmp_you = (u == 1) ? 2 : 1;
					dfs(0, tmp_you);
					p[0] -= 1;
				}
				else { 
					int tmp_you = (u == 1) ? 2 : 1;
					p[u] += 1;
					dfs(u, tmp_you);
					p[u] -= 1;
				}
			}
			visit[i] = false;
		}
		if (u == 0)
			cntp[v]--;
		else
			cntp[u]--;
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 20; j++) {
			cin >> person[i][j];
		}
	}

	ans = 0;
	dfs(0, 1);
	cout << ans << '\n';

	return 0;
}
