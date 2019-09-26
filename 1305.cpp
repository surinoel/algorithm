#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define min(n, m) n > m ? m : n

vector<int> makeTable(string pattern) {
    int strsize = pattern.size();
    vector<int> table(strsize);

    int j = 0;
    for(int i=1; i<strsize; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j - 1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }

    return table;
}

int main(void) {
    ios_base::sync_with_stdio(false);

    int n;
    string pattern;
    cin >> n >> pattern;

    vector<int> table = makeTable(pattern);
    cout << n - table[n-1] << '\n';

    return 0;
}
