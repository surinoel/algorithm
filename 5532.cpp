#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("data.txt", "r", stdin);

    int day, a, b, c, d;
    cin >> day >> a >> b >> c >> d;
    double val = max((double)a/c, (double)b/d);
    if(val != (int)val) {
        cout << day - ((int)val + 1) << '\n';
    }
    else {
        cout << day - (int)val << '\n';
    }
}


