#include <iostream>
#include <algorithm>

#define int long long

using namespace std;

int n, m, c;
int cows[123456];

bool check(int x) {
    int cnt=1,lst=cows[1],cntcow=1;
        for(int i=1; i<n; i++)
        {
            cntcow++;
            if(cows[i]-lst>x||cntcow>c)
            {
                cnt++;
                cntcow=1;
                lst=cows[i];
                if(cnt>m) {
                    return false;
                }
            }
        }
    return true;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
    baseIO("convention");
    cin >> n >> m >> c;
    for (int i=0; i<n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+n);
    
    int lo=0;
    int hi=cows[n-1];
    while (lo<hi) {
        int mid = (lo+hi)/2;
        if (check(mid)) {
            hi = mid;
        }else{
            lo = mid+1;
        }
    }
    
    cout << lo;
}
