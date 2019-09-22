#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	int idx = 0;
	int rstock = stock;
	priority_queue<int, vector<int>> pq;
	for (int i = 0; i < k; i++) {
		if (dates[idx] == i) {
			pq.push(supplies[idx]);
			idx += 1;
		}

		if (rstock == 0) {
			answer += 1;
			rstock += pq.top();
			pq.pop();
		}

		rstock--;
	}

	return answer;
}
