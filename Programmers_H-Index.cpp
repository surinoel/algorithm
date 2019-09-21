#include <string>
#include <vector>

using namespace std;

int cnt[10001];

int solution(vector<int> citations) {
	int answer = 0;
	int size = citations.size();
	for (int i = 0; i < size; i++) {
		cnt[citations[i]] += 1;
	}

	int sum = 0;
	for (int i = 10000; i >= 0; i--) {
		sum += cnt[i];
		if (sum >= i) {
			answer = i;
			break;
		}
	}

	return answer;
}
