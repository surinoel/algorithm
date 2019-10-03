#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
	vector<int> answer;
	int b, r;
	b = brown, r = red;
	for (int i = 1; i*i <= r; i++) {
		if (r%i == 0) {
			int h, w;
			h = i, w = r / i;
			if (b == 4 + h * 2 + w * 2) {
				answer.push_back(w + 2);
				answer.push_back(h + 2);
				return answer;
			}
		}
	}
}
