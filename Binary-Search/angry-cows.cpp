#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int n, k;
const int maxN = 5e4+5;
int cows[maxN];

bool check(int mid) {
    int current = cows[0] + mid;
    int cnt = 0;
    while (cnt < k) {
        int t = upper_bound(cows, cows+n, current + mid) - cows;
        if (t>n-1) {
            return true;
        }
        cnt ++;
        current = cows[t] + mid;
    }
    return false;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
    baseIO("angry");
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+n);
    
    int lo=0;
    int hi=cows[n-1];
    while (lo<hi) {
        int mid = lo + (hi-lo)/2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo;
}
