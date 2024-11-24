
#include <algorithm>
#include <iostream>
#include <queue>

#define int long long

using namespace std;

struct tower {
    int w, a;

    bool operator < (const tower& other) const {
        return w < other.w;
    }
};

bool cmp (const tower& f, const tower& s) {
    return f.w > s.w;
}

const int maxN = 2e5+5;
tower towers[maxN];
priority_queue<tower> pqTower;

int ans;

signed main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++) {
        cin >> towers[i].w >> towers[i].a;
    }
    sort(towers, towers+n, cmp);

    int maxNum = 2e9;
    pqTower.push({maxNum, m});

    for (int i=0; i<n; i++) {
        int cnt = 0;
        while (!pqTower.empty()) {
            tower t = pqTower.top();
            pqTower.pop();
            if (t.w - towers[i].w < k) {
                pqTower.push(t);
                break;
            } else {
                if (t.a > towers[i].a) {
                    cnt += towers[i].a;
                    pqTower.push({t.w, t.a - towers[i].a});
                    break;
                } else if (t.a == towers[i].a) {
                    cnt += towers[i].a;
                    break;
                } else {
                    cnt += t.a;
                    towers[i].a -= t.a;
                    continue;
                }
            }
        }
        pqTower.push({towers[i].w, cnt});
        ans += cnt;
    }

    cout << ans;
}
