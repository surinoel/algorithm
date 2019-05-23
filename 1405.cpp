#include <vector>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

int n;
double ep, wp, sp, np;
double ans;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void go(int m, int x, int y, vector<vector<bool>> &visit, double tmp) {
	if (m == n) {
		ans += tmp;
		return;
	}
	
	if (!visit[x + dx[0]][y + dy[0]]) {
		visit[x + dx[0]][y + dy[0]] = true;
		go(m + 1, x + dx[0], y + dy[0], visit, tmp * (ep / 100));
		visit[x + dx[0]][y + dy[0]] = false;
	}
	if (!visit[x + dx[1]][y + dy[1]]) {
		visit[x + dx[1]][y + dy[1]] = true;
		go(m + 1, x + dx[1], y + dy[1], visit, tmp * (wp / 100));
		visit[x + dx[1]][y + dy[1]] = false;
	}
	if (!visit[x + dx[2]][y + dy[2]]) {
		visit[x + dx[2]][y + dy[2]] = true;
		go(m + 1, x + dx[2], y + dy[2], visit, tmp * (sp / 100));
		visit[x + dx[2]][y + dy[2]] = false;
	}
	if (!visit[x + dx[3]][y + dy[3]]) {
		visit[x + dx[3]][y + dy[3]] = true;
		go(m + 1, x + dx[3], y + dy[3], visit, tmp * (np / 100));
		visit[x + dx[3]][y + dy[3]] = false;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> ep >> wp >> sp >> np;

	vector<vector<bool>> visit(100, vector<bool>(100, false));
	visit[50][50] = true;
	go(0, 50, 50, visit, 1.0);

	cout << fixed << setprecision(10) << ans << '\n';
	
	return 0;
}
