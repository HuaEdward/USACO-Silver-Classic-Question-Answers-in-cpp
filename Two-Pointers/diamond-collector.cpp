#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 5e4+5;
int diamonds[maxN];
int sizes[maxN];
int maxSizes[maxN];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("diamond");
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> diamonds[i];
    }
    sort(diamonds, diamonds+n);
    
    for (int l=0; l<n; l++) {
        int r = l;
        while (diamonds[r]-diamonds[l] >= 0 && diamonds[r]-diamonds[l] <= k) {
            sizes[l]++;
            r++;
        }
    }
    
    int maxNum = 0;
    for (int i=n-1; i>=0; i--) {
        maxSizes[i] = max(sizes[i], maxNum);
        maxNum = maxSizes[i];
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        ans = max(ans, sizes[i] + maxSizes[i+sizes[i]]);
    }
    
    cout << ans;
}
