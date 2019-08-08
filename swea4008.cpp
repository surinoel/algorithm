#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int tc;
	cin >> tc;
	for (int test_case = 1; test_case <= tc; test_case++) {
		int n;
		cin >> n;
		vector<int> num(n);
		vector<char> opvector;
		
		for (int i = 0; i < 4; i++) {
			int x; cin >> x;
			for (int j = 0; j < x; j++) {
				if (i == 0) opvector.push_back('+');
				else if (i == 1) opvector.push_back('-'); 
				else if (i == 2) opvector.push_back('*');
				else if (i == 3) opvector.push_back('/');
			}
		}
		for (int i = 0; i < n; i++) {
			cin >> num[i];
		}
		sort(opvector.begin(), opvector.end());
		int minval, maxval;
		minval = INT_MAX, maxval = INT_MIN;

		do {
			int start = num[0];
			for (int i = 0; i < opvector.size(); i++) {
				if (opvector[i] == '+') start += num[i + 1];
				else if (opvector[i] == '-') start -= num[i + 1];
				else if (opvector[i] == '*') start *= num[i + 1];
				else if (opvector[i] == '/') start /= num[i + 1];
			}

			minval = min(minval, start);
			maxval = max(maxval, start);
		} while (next_permutation(opvector.begin(), opvector.end()));
	
		cout << "#" << test_case << " " << maxval - minval << '\n';
	}

	return 0;
}
