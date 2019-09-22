#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check1[10], check2[10];

int solution(vector<vector<int>> baseball) {
	int answer = 0;
	for (int i = 100; i < 1000; i++) {
		memset(check1, false, sizeof(check1));

		string tmp = to_string(i);
		if (tmp.find('0') != -1) continue;

		bool ok = true;
		for (int j = 0; j < tmp.size(); j++) {
			if (!check1[tmp[j] - '0']) {
				check1[tmp[j] - '0'] = true;
			}
			else {
				ok = false;
				break;
			}
		}

		if (!ok) continue;
		for (int j = 0; j < baseball.size(); j++) {
			int num, s, b;
			num = baseball[j][0];
			s = baseball[j][1];
			b = baseball[j][2];

			int ts = 0;
			int tb = 0;
			string tnum = to_string(num);
			bool check3[10];
			memset(check2, false, sizeof(check2));
			memcpy(check3, check1, sizeof(check1));

			for (int k = 0; k < 3; k++) {
				if (tmp[k] == tnum[k]) {
					ts += 1;
					check3[tmp[k] - '0'] = false;
				}
				else {
					check2[tnum[k] - '0'] = true;
				}
			}

			for (int k = 0; k < 10; k++) {
				if (check3[k] == true && check2[k] == true) {
					tb += 1;
				}
			}

			if (s != ts || b != tb) {
				ok = false;
				break;
			}
		}
		if (ok) {
			answer += 1;
		}
	}

	return answer;
}
