#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        int mid = n/2;
        int left = 0, right = n - 1;
        bool ok = false;
        while(left <= right) {
            if(a[mid] == x) {
                ok = true;
                break;
            }
            else if(a[mid] > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }

            mid = (left + right) / 2;
        }
        if(ok) {
            cout << 1 << '\n';
        }   
        else {
            cout << 0 << '\n';
        }    
    }

    return 0;
}
