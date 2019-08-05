#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct __ms {
	int num, dir;
	__ms(int num, int dir) : num(num), dir(dir) {}
} ms;

typedef struct __MSinfo {
	int x, y, num, dir;
	__MSinfo(int x, int y, int num, int dir) : x(x), y(y), num(num), dir(dir) {}
} MSinfo;

bool cmp(const MSinfo& u, const MSinfo& v) {
	if (u.x == v.x) {
		if (u.y == v.y) {
			if (u.num == v.num) {
				return u.dir < v.dir;
			}
			return u.num > v.num;
		}
		return u.y < v.y;
	}
	return u.x < v.x;
}

int dx[5] = { 0, -1, 1, 0, 0 };
int dy[5] = { 0, 0, 0, -1, 1 };

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n, t, k;
		cin >> n >> t >> k;
		vector<MSinfo> msinfo;
		for (int i = 0; i < k; i++) {
			int x, y, num, dir;
			cin >> x >> y >> num >> dir;
			msinfo.push_back(MSinfo(x, y, num, dir));
		}

		for (int time = 1; time <= t; time++) {
			vector<MSinfo> tmpinfo = msinfo, allms;
			for (int i = 0; i < tmpinfo.size(); i++) {
				int x, y, num, dir;
				x = tmpinfo[i].x; y = tmpinfo[i].y;
				num = tmpinfo[i].num; dir = tmpinfo[i].dir;
				int tx = x + dx[dir];
				int ty = y + dy[dir];
				if (tx == 0 || tx == n - 1 || ty == 0 || ty == n - 1) {
					if (num / 2 > 0) {
						num = num / 2;
						if (dir == 1) dir = 2;
						else if (dir == 2) dir = 1;
						else if (dir == 3) dir = 4;
						else if (dir == 4) dir = 3;
						allms.push_back(MSinfo(tx, ty, num, dir));
					}
				}
				else {
					allms.push_back(MSinfo(tx, ty, num, dir));
				}
			}

			msinfo = vector<MSinfo>();
			sort(allms.begin(), allms.end(), cmp);

			for (int i = 0; i < allms.size(); i++) {
				msinfo.push_back(MSinfo(allms[i].x, allms[i].y, allms[i].num, allms[i].dir));
				int total = allms[i].num;
				for (int j = i + 1; j < allms.size(); j++) {
					if (!(allms[i].x == allms[j].x && allms[i].y == allms[j].y)) {
						i = j - 1;
						break;
					}
					else {
						if (j == allms.size() - 1) {
							i = j;
						}
						total += allms[j].num;
					}
				}
				msinfo[msinfo.size() - 1].num = total;
			}

			if (time == t) {
				int ans = 0;
				for (int i = 0; i < msinfo.size(); i++) {
					ans += msinfo[i].num;
				}
				cout << "#" << test_case << " " << ans << '\n';
			}
		}
	}

	return 0;
}
