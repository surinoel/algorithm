#include <string>
#include <vector>

using namespace std;

void go(int idx, int sum, const vector<int> &numbers, int &cnt, int target) {
    if(idx == numbers.size()) {
        if(sum == target) {
            cnt += 1;
        }
        return;
    }
    
    go(idx + 1, sum + numbers[idx], numbers, cnt, target);
    go(idx + 1, sum - numbers[idx], numbers, cnt, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    go(0, 0, numbers, answer, target);
    return answer;
}
