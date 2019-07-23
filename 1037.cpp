#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[0] * v[v.size()-1] << '\n';
    return 0;
}
