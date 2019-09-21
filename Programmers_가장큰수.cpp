#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const string& u, const string& v) {
	if (u == v) return false;

	string a = u + v;
	string b = v + u;
	if (a > b) return true;
	else return false;
}

string solution(vector<int> numbers) {
	string answer = "";
	vector<string> ns;
	int zerocount = 0;
	for (int i = 0; i < numbers.size(); i++) {
		string tmp = to_string(numbers[i]);
		ns.push_back(tmp);
		if (tmp.front() == '0' && tmp.back() == '0') {
			zerocount += 1;
		}
	}

	if (zerocount == numbers.size()) {
		return "0";
	}

	sort(ns.begin(), ns.end(), cmp);
	for (int i = 0; i < ns.size(); i++) {
		answer += ns[i];
	}
	return answer;
}
