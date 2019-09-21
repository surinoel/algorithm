#include <string>
#include <vector>

using namespace std;

vector<int> mat[200];
bool visit[200];

void go(int idx) {
	if (visit[idx]) {
		return;
	}
	visit[idx] = true;

	for (int i = 0; i < mat[idx].size(); i++) {
		int y = mat[idx][i];
		go(y);
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers[i].size(); j++) {
			if (computers[i][j] == 1) {
				mat[i].push_back(j);
			}
		}
	}

	int row = computers.size();
	for (int i = 0; i < row; i++) {
		if (!visit[i]) {
			answer += 1;
			go(i);
		}
	}
	
	return answer;
}
