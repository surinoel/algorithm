#include <map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    
	map<string, int> ans;
	for (int i = 1; i < (1 << col); i++) {
		vector<int> tmp;
		for (int j = 0; j < col; j++) {
			if (i & (1 << j)) {
				tmp.push_back(j);
			}
		}

		map<string, int> m;
		bool ok = true;
		for (int j = 0; j < row; j++) {
			string series = "";
			for (int k = 0; k < tmp.size(); k++) {
				series += relation[j][tmp[k]] + ",";
			}
			if (m.count(series)) {
				ok = false;
				break;
			}
			else {
				m[series] = 1;
			}
		}
		
		if (ok) {
			bool ok2 = true;
			for (int j = 1; j < (1 << tmp.size()); j++) {
				string comb = "";
				for (int k = 0; k < tmp.size(); k++) {
					if (j & (1 << k)) {
						comb += to_string(tmp[k]);
					}
				}
				if (ans.count(comb)) {
					ok2 = false;
					break;
				}
			}
			if (ok2) {
				string stmp = "";
				for (int k = 0; k < tmp.size(); k++) {
					stmp += to_string(tmp[k]);
				}
				ans[stmp] = 1;
			}
		}
	}

    answer = ans.size();
    return answer;
}
