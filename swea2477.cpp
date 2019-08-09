#include <deque>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct __ct {
	int num, enter;
	int rooma, roomb, starta, enda, startb, endb;
	__ct() :
		num(0), enter(0), rooma(0), roomb(0), starta(0), enda(0), startb(0), endb(0) {}
	__ct(int num, int enter, int rooma, int roomb, int starta, int enda, int startb, int endb) :
		num(num), enter(enter), rooma(rooma), roomb(roomb), starta(starta), enda(enda), startb(startb), endb(endb) {}
} CT;

typedef struct __rminfo {
	int num, endtime;
	__rminfo() : num(0), endtime(0) {}
	__rminfo(int num, int endtime) : num(num), endtime(endtime) {}
} RMINFO;

bool cmpa(const CT& u, const CT& v) {
	return u.num < v.num;
}

bool cmpb(const CT& u, const CT& v) {
	if (u.enda == v.enda) {
		return u.rooma < v.rooma;
	}
	return u.enda < v.enda;
}

int atime[10], btime[10];
RMINFO aendtime[10], bendtime[10];
bool exitcheck[1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		memset(atime, 0, sizeof(atime));
		memset(btime, 0, sizeof(btime));
		memset(aendtime, 0, sizeof(aendtime));
		memset(bendtime, 0, sizeof(bendtime));
		memset(exitcheck, 0, sizeof(exitcheck));

		int n, m, k, a, b;
		cin >> n >> m >> k >> a >> b;
		for (int i = 1; i <= n; i++) {
			cin >> atime[i];
		}
		for (int i = 1; i <= m; i++) {
			cin >> btime[i];
		}

		vector<CT> custom(k + 1);
		for (int i = 1; i <= k; i++) {
			custom[i].num = i;
			cin >> custom[i].enter;
		}

		int idx = 1;
		deque<CT> waita, waitb;
		for (int t = 0; ; t++) {
			bool ok = true;
			for (int i = 1; i <= k; i++) {
				if (!exitcheck[i]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				break;
			}

			for (int i = 1; i <= m; i++) {
				if (t > 0 && bendtime[i].endtime == t) {
					exitcheck[bendtime[i].num] = true;
					bendtime[i].num = 0;
					bendtime[i].endtime = 0;
				}
			}
			for (int i = 1; i <= n; i++) {
				if (t > 0 && aendtime[i].endtime == t) {
					waitb.push_back(custom[aendtime[i].num]);
					aendtime[i].num = 0;
					aendtime[i].endtime = 0;
				}
			}
			
			for (int i = idx; i <= k; i++) {
				if (custom[i].enter == t) {
					waita.push_back(custom[i]);
					idx = i + 1;
				}
				else {
					break;
				}
			}
			
			sort(waita.begin(), waita.end(), cmpa);

			for (int i = 1; i <= n; i++) {
				if (waita.empty()) break;
				if (aendtime[i].endtime == 0) {
					custom[waita.front().num].rooma = i;
					custom[waita.front().num].starta = t;
					custom[waita.front().num].enda = t + atime[i];
					aendtime[i].num = waita.front().num;
					aendtime[i].endtime = t + atime[i];
					waita.pop_front();
				}
			}

			sort(waitb.begin(), waitb.end(), cmpb);

			for (int i = 1; i <= m; i++) {
				if (waitb.empty()) break;
				if (bendtime[i].endtime == 0) {
					custom[waitb.front().num].roomb = i;
					custom[waitb.front().num].startb = t;
					custom[waitb.front().num].endb = t + btime[i];
					bendtime[i].num = waitb.front().num;
					bendtime[i].endtime = t + btime[i];
					waitb.pop_front();
				}
			}
		}

		int ans = 0;
		for (int i = 1; i <= k; i++) {
			if (custom[i].rooma == a && custom[i].roomb == b) {
				ans += i;
			}
		}
		if (ans == 0) ans = -1;
		cout << "#" << test_case << " " << ans << '\n';
	}

	return 0;
}
