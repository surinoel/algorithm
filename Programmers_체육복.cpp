#include <string>
#include <vector>
#include <cstring>

using namespace std;

bool check[31];
bool has[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    memset(check, true, sizeof(check));
    for(int i=0; i<lost.size(); i++) {
        check[lost[i]] = false;
    }
    for(int i=0; i<reserve.size(); i++) {
        if(!check[reserve[i]]) {
            check[reserve[i]] = true;
        }
        else {
            has[reserve[i]] = true;
        }
    }
     for(int i=1; i<=n; i++) {
        if(!check[i]) {
            if(i-1>=1 && has[i-1]) {
                has[i-1] = false;
                check[i] = true;
            }
        }
        if(!check[i]) {
            if(i+1<=n && has[i+1]) {
                has[i+1] = false;
                check[i] = true;
            }
        }
    }

    for(int i=1; i<=n; i++) {
        if(check[i]) answer += 1;
    }
    
    return answer;
}
