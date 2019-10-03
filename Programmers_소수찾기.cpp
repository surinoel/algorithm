#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

bool check[10000000];
vector<int> totalset;

void go(int cnt, int num, const vector<int> &idx) {
	if (cnt == idx.size()) {
		if (num != 0) {
			totalset.push_back(num);
		}
		return;
	}

	go(cnt + 1, num, idx);
	if (!(num == 0 && idx[cnt] == 0)) {
		go(cnt + 1, num * 10 + idx[cnt], idx);
	}
	return;
}

int solution(string numbers) {
    string s = numbers; 
    vector<int> idx;
	for (int i = 0; i < s.size(); i++) {
		int num = s[i] - '0';
		idx.push_back(num);
	}

	sort(idx.begin(), idx.end());
	do {
		go(0, 0, idx);
	} while (next_permutation(idx.begin(), idx.end()));

	sort(totalset.begin(), totalset.end());
	totalset.erase(unique(totalset.begin(), totalset.end()), totalset.end());
	
	memset(check, true, sizeof(check));
	check[1] = false;
	for (int i = 2; i * i < 10000000; i++) {
		if (!check[i]) continue;
		for (int j = i + i; j < 10000000; j += i) {
			check[j] = false;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < totalset.size(); i++) {
		if (check[totalset[i]]) {
			ans += 1;
		}
	}
    
    return ans;
}
