#include <iostream>
#include <algorithm>
#include <cmath>

#define int long long

struct cow {
    int x, y, t;

    bool operator < (const cow& other) const {
        return t < other.t;
    }
};

using namespace std;

const int maxNG = 1e5+5;
cow ns[maxNG];
cow gs[maxNG];

signed main() {
    int g, n;
    cin >> g >> n;
    for (int i=0; i<g; i++) {
        cin >> gs[i].x >> gs[i].y >> gs[i].t;
    }
    for (int i=0; i<n; i++) {
        cin >> ns[i].x >> ns[i].y >> ns[i].t;
    }

    sort(gs, gs+g);

    int ans = 0;
    for (int i=0; i<n; i++) {
        int lb = lower_bound(gs, gs+g, ns[i]) - gs;
        if (lb == g || (ns[i].x - gs[lb].x)*(ns[i].x - gs[lb].x) + (ns[i].y - gs[lb].y)*(ns[i].y - gs[lb].y) <= (ns[i].t - gs[lb].t)*(ns[i].t - gs[lb].t)) {
            if (lb == 0 || (ns[i].x - gs[lb-1].x)*(ns[i].x - gs[lb-1].x) + (ns[i].y - gs[lb-1].y)*(ns[i].y - gs[lb-1].y) <= (ns[i].t - gs[lb-1].t)*(ns[i].t - gs[lb-1].t)) {
                ans ++;
            }
        }
    }

    cout << n-ans;
}
