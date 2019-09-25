#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> makeTable(string pattern) {
    int strsize = pattern.size();
    vector<int> table(strsize);

    int j = 0;
    for(int i=1; i<strsize; i++) {
        while(j > 0 && pattern[i] != pattern[j]) {
            j = table[j-1];
        }
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
   }

    return table;
}

void KMP(string parent, string pattern) {
    int prsize = parent.size();
    int ptsize = pattern.size();
    int j = 0;
    vector<int> table = makeTable(pattern);
    vector<int> ans;
    for(int i=0; i<prsize; i++) {
        while(j > 0 && parent[i] != pattern[j]) {
            j = table[j-1];
        }
        if(parent[i] == pattern[j]) {
            if(j == ptsize-1) {
                ans.push_back(i-ptsize+2);
                j = table[j];
            }
            else {
                j++;
            }
        }
    }

    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string parent, pattern;
    getline(cin, parent);
    getline(cin, pattern);

    KMP(parent, pattern);

    return 0;
}
