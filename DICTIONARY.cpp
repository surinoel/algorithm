#include <queue>
#include <tuple>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

vector<string> vs[26];
int mat[26][26];
int indegree[26];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--) {
		memset(indegree, 0, sizeof(indegree));
		for (int i = 0; i < 26; i++) {
			vs[i].clear();
			for (int j = 0; j < 26; j++) {
				mat[i][j] = 0;
			}
		}

		int n;
		cin >> n;
		vector<string> arr;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			arr.push_back(s);
			vs[s.front() - 'a'].push_back(s);
		}

		int x = arr[0].front() - 'a';
		for (int i = 1; i < n; i++) {
			int y = arr[i].front() - 'a';
			if (x != y) {
				indegree[y] = 1;
				mat[x][y] = 1;
				x = y;
			}
		}

		for (int i = 0; i < 26; i++) {
			if (vs[i].size() > 1) {
				string s1 = vs[i][0];
				for (int v = 1; v < vs[i].size(); v++) {
					string s2 = vs[i][v];
					int len = s1.size() > s2.size() ? s2.size() : s1.size();
					for (int k = 1; k < len; k++) {
						if (s1[k] != s2[k]) {
							int x = s1[k] - 'a';
							int y = s2[k] - 'a';
							if (mat[x][y] == 0) {
								mat[x][y] = 1;
								indegree[y] += 1;
							}
							break;
						}
					}
					s1 = s2;
				}
			}
		}

		vector<char> ans;
		queue<int> q;
		for (int i = 0; i < 26; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				ans.push_back('a' + i);
			}
		}

		bool ok = true;
		for (int i = 0; i < 26; i++) {
			if (q.empty()) {
				ok = false;
				break;
			}
			
			int ch = q.front();
			q.pop();

			for (int i = 0; i < 26; i++) {
				if (mat[ch][i]) {
					int y = i;
					if (--indegree[y] == 0) {
						q.push(y);
						ans.push_back(y + 'a');
					}
				}
			}
		}
	
		for (int i = 0; i < 26; i++) {
			if (indegree[i] > 0) {
				ok = false;
				break;
			}
		}
		if (!ok) {
			cout << "INVALID HYPOTHESIS\n";
		}
		else {
			for (int i = 0; i < ans.size(); i++) {
				cout << ans[i];
			}
			cout << '\n';
		}
	}

	return 0;
}
