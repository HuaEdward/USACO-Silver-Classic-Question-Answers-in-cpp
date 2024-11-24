#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long

using namespace std;

struct customer {
    int a, b, c;
};

int n, c, m;
customer customers[105];

bool check(int mid) {
    int sum = c + m - mid;
    int l = max((int)1, sum-m);
    int r = min(c, sum-1);
    for (int i=0; i<n; i++) {
        int U = customers[i].c - customers[i].b * sum;
        int D = customers[i].a - customers[i].b;
        if (D > 0) {
            r = min(r, (int)(floor((double)U/D)));
        } else if (D < 0) {
            l = max(l, (int)(ceil((double)U/D)));
        } else {
            if (customers[i].b * sum > customers[i].c) {
                return false;
            }
            continue;
        }
    }
    return l<=r;
}

void process() {
    cin >> n >> c >> m;
    for (int i=0; i<n; i++) {
        cin >> customers[i].a >> customers[i].b >> customers[i].c;
    }
    
    int lo = 0;
    int hi = c+m;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        process();
    }
}
