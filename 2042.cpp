#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;
int *arr;
ll *tree;

ll init(int idx, int start, int end) {
    if(start == end) {
        return tree[idx] = arr[start];
    }
    else {
        return tree[idx] = init(idx*2 + 1, start, (start + end)/2) +
            init(idx*2 + 2, (start+end)/2 + 1, end);
    }
}

ll sum(int idx, int start, int end, int left, int right) {
    if(start > right || left > end) return 0;
    else if(left <= start && end <= right) return tree[idx];
    else {
        int mid = (start + end) / 2;
        return sum(idx*2 + 1, start, mid, left, right) +
            sum(idx*2 + 2, mid + 1, end, left, right);
    }
}

void change(int idx, int start, int end, ll diff, int changeidx) {
    if(changeidx < start || changeidx > end) return;
    
    tree[idx] += diff;
    if(start < end) {
        int mid = (start + end) / 2;
        change(2*idx + 1, start, mid, diff, changeidx);
        change(2*idx + 2, mid + 1, end, diff, changeidx);
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int h = (int)ceil(log2(n));
    int tree_size = 1 << (h + 1);

    tree = new ll[tree_size];
    
    init(0, 0, n-1);
    for(int i=0; i<m+k; i++) {
        int a;
        ll b, c;
        cin >> a >> b;
        b -= 1;
        if(a==1) {
            cin >> c;
            ll diff = c - arr[b];
            change(0, 0, n-1, diff, b);
            arr[b] = c;
        } 
        else {
            cin >> c;
            c -= 1;
            cout << sum(0, 0, n-1, b, c) << '\n';
        }       
    }

    delete[] arr;
    delete[] tree;

    return 0;
}
