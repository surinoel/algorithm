#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, double> &u, const pair<int, double> &v) {
	if (u.second == v.second) {
		return u.first < v.first;
	}
	return u.second < v.second;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> ans;
	vector<pair<double, double>> score(N + 1, make_pair(0, 0));
	
	for (int i = 0; i < stages.size(); i++) {
		int p = stages[i];
		if (p != N + 1) {
			score[p].second += 1;
		}
		for (int j = p - 1; j >= 1; j--) {
			score[j].first += 1;
			score[j].second += 1;
		}
	}

	vector<pair<int, double>> tmp(N + 1, make_pair(0, 0));
	for (int i = 1; i <= N; i++) {
		tmp[i].first = i;
		if(score[i].second != 0) {
		    tmp[i].second = score[i].first / score[i].second;
		}
		else {
		    tmp[i].second = 1;
		}
	}

	sort(tmp.begin() + 1, tmp.end(), cmp);
	for (int i = 1; i <= N; i++) {
		ans.push_back(tmp[i].first);
	}
	return ans;
}
