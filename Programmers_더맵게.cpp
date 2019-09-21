#include <queue>
#include <iostream>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < scoville.size(); i++) {
		pq.push(scoville[i]);
	}
	while (1) {
		if (pq.size() <= 1) {
			return -1;
		}
		if (pq.top() >= K) {
			break;
		}
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		int c = a + b * 2;
		pq.push(c);
		answer += 1;
	}
	
	return answer;
}
