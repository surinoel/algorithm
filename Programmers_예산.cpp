#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M) {
	int answer = -1;
	int tsum = -1;
	sort(budgets.begin(), budgets.end());
	int left = 0, right = budgets.back();
	int mid = (left + right) / 2;

	while (left <= right) {
		int sum = 0;
		for (int i = 0; i < budgets.size(); i++) {
			if (budgets[i] >= mid) {
				sum += mid;
			}
			else {
				sum += budgets[i];
			}
		}
		
		if (sum > M) {
			right = mid - 1;
		}
		else {
			if (tsum == -1 || sum > tsum) {
				tsum = sum;
				answer = mid;
			}
			left = mid + 1;
		}

		mid = (left + right) / 2;
	}

	return answer;
}
