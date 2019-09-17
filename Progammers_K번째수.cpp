#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int size = commands.size();

	for (int test_case = 0; test_case < size; test_case++) {
		int i, j, k;
		i = commands[test_case][0];
		j = commands[test_case][1];
		k = commands[test_case][2];

		vector<int> subarray(array.begin() + i - 1, array.begin() + j);
		sort(subarray.begin(), subarray.end());
		answer.push_back(subarray[k - 1]);
	}
	
	return answer;
}
