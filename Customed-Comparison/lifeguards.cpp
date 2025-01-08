#include <iostream>
#include <algorithm>

using namespace std;

struct guard{
    int l, r;
    
    bool operator < (const guard &other) const {
        return l < other.l;
    }
};

const int maxN = 1e5+5;
guard guards[maxN];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("lifeguards");
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> guards[i].l >> guards[i].r;
    }
    sort(guards, guards+n);
    
    int totalTime = 0;
    int rightMax = 0;
    for (int i=0; i<n; i++) {
        totalTime += max(0, guards[i].r - max(guards[i].l, rightMax));
        rightMax = max(guards[i].r, rightMax);
    }
    
    int minLoss = 1e10;
    guards[n].l = 1e10;
    rightMax = 0;
    for (int i=0; i<n; i++) {
        int loss = max(0, min(guards[i].r, guards[i+1].l) - max(guards[i].l, rightMax));
        rightMax = max(guards[i].r, rightMax);
        minLoss = min(minLoss, loss);
    }
    
    cout << totalTime - minLoss;
}
