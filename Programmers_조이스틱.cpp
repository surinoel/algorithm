#include <queue>
#include <string>
#include <vector>

using namespace std;

struct tp {
	int idx;
	int sum;
	string s;
	tp(int idx = 0, int sum = 0, string s = "") :
		idx(idx), sum(sum), s(s) {
	}
};

int ap[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
bool check[21];

int solution(string name) {
	int answer = 0;

	int len = name.size();
	queue<tp> q;
	q.push(tp(0, 0, name));

	while (!q.empty()) {
		tp t = q.front();
		q.pop();

		int idx = t.idx;
		int sum = t.sum;
		string s = t.s;

		bool ok = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != 'A') ok = false;
		}
		if (ok) {
			answer = sum - 1;
      if(answer == -1) answer = 0;
			break;
		}

		int tsum = 0;
		tsum += ap[s[idx] - 'A'];
		string ts = s;
		ts[idx] = 'A';
		if (idx - 1 == -1) {
			q.push(tp(len - 1, sum + tsum + 1, ts));
		}
		else {
			q.push(tp(idx - 1, sum + tsum + 1, ts));
		}

		if (idx + 1 == len) {
			q.push(tp(0, sum + tsum + 1, ts));
		}
		else {
			q.push(tp(idx + 1, sum + tsum + 1, ts));
		}
	}

	return answer;
}
