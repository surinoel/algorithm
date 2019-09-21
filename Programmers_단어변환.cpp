#include <string>
#include <vector>

using namespace std;

vector<int> mat[51];
bool visit[51];
int wsize;
int idx;

void go(int cnt, int cur, int& ans) {
	if (cur == idx) {
		if (ans == 0 || ans > cnt) {
			ans = cnt;
		}
		return;
	}

	for (int i = 0; i < mat[cur].size(); i++) {
		int y = mat[cur][i];
		if (!visit[y]) {
			visit[y] = true;
			go(cnt + 1, y, ans);
			visit[y] = false;
		}
	}

	return;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	bool ok = false;
	words.insert(words.begin(), begin);
	for (int i = 0; i < words.size(); i++) {
		if (words[i] == target) {
			ok = true;
			idx = i;
			break;
		}
	}
	if (!ok) {
		return 0;
	}

	for (int i = 0; i < words.size() - 1; i++) {
		for (int j = i + 1; j < words.size(); j++) {
			int diff = 0;
			string a = words[i];
			string b = words[j];
			for (int k = 0; k < a.size(); k++) {
				if (a[k] != b[k]) {
					diff += 1;
				}
			}
			if (diff == 1) {
				mat[i].push_back(j);
				mat[j].push_back(i);
			}
		}
	}

	wsize = words.size();
	visit[0] = true;
	go(0, 0, answer);
	return answer;
}
