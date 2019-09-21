#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int tsize;
bool check[20000];
vector<pair<int, int>> mat[20000];

void go(int idx, int cnt, vector<int>& path, vector<int>& ans) {
	if (cnt == tsize) {
		if (ans.empty()) {
			ans = path;
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				if (path[i] < ans[i]) {
					ans = path;
					break;
				}
				else if (path[i] > ans[i]) {
					break;
				}
			}
		}
		return;
	}

	for (int i = 0; i < mat[idx].size(); i++) {
		int y = mat[idx][i].second;
		int node = mat[idx][i].first;
		if (!check[y]) {
			check[y] = true;
			path.push_back(node);
			go(node, cnt + 1, path, ans);
			path.pop_back();
			check[y] = false;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	for (int i = 0; i < tickets.size(); i++) {
		int a = (tickets[i][0][0] - 'A') * (int)pow(26, 2) + (tickets[i][0][1] - 'A') * (int)pow(26, 1) + (tickets[i][0][2] - 'A') * (int)pow(26, 0);
		int b = (tickets[i][1][0] - 'A') * (int)pow(26, 2) + (tickets[i][1][1] - 'A') * (int)pow(26, 1) + (tickets[i][1][2] - 'A') * (int)pow(26, 0);
		mat[a].push_back(make_pair(b, i));
	}

	int start = ('I' - 'A') * (int)pow(26, 2) + ('C' - 'A') * (int)pow(26, 1) + ('N' - 'A') * (int)pow(26, 0);
	vector<int> path, ans;
	tsize = tickets.size();
	path.push_back(start);
	go(start, 0, path, ans);
	for (int i = 0; i < ans.size(); i++) {
		string tmp = "";
		int n1 = ans[i] / (int)pow(26, 2);
		tmp.push_back((char)('A' + n1));
		ans[i] = ans[i] % (int)pow(26, 2);
		int n2 = ans[i] / (int)pow(26, 1);
		tmp.push_back((char)('A' + n2));
		ans[i] = ans[i] % (int)pow(26, 1);
		int n3 = ans[i];
		tmp.push_back((char)('A' + n3));

		answer.push_back(tmp);
	}

	return answer;
}
