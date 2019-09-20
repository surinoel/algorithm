#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

map<string, string> m;

vector<string> solution(vector<string> record) {
	vector<string> ret;
	for (int i = 0; i < record.size(); i++) {
		istringstream f(record[i]);
		string s;
		vector<string> tokens;

		while (getline(f, s, ' ')) {
			tokens.push_back(s);
		}

		if (tokens[0] == "Enter") {
			m[tokens[1]] = tokens[2];
			string tans = tokens[1] + ",님이 들어왔습니다.";
			ret.push_back(tans);
		}
		else if (tokens[0] == "Leave") {
			string tans = tokens[1] + ",님이 나갔습니다.";
			ret.push_back(tans);
		}
		else {
			m[tokens[1]] = tokens[2];
		}
	}

	vector<string> ans;
	for (int i = 0; i < ret.size(); i++) {
		istringstream f(ret[i]);
		vector<string> tokens;
		string s;

		while (getline(f, s, ',')) {
			tokens.push_back(s);
		}

		ans.push_back(m[tokens[0]] + tokens[1]);
	}

	return ans;
}
