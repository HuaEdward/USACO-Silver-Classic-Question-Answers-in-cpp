#include <iostream>

#define int long long

using namespace std;

const int maxN = 2e5+5;
const int max2M = 10005;

int a[maxN];
int b[maxN];
int cnt_a[max2M];
int cnt_b[max2M];
int dif[max2M];
int ans[max2M];

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int i=0; i<n; i++) {
        cnt_a[a[i]]++;
        cnt_b[b[i]]++;
    }
    
    for (int i=0; i<=m; i++) {
        for (int j=0; j<=m; j++) {
            dif[i+j] += cnt_a[i]*cnt_a[j];
            dif[i+j+1] -= cnt_b[i]*cnt_b[j];
        }
    }
    
    ans[0] = dif[0];
    for (int i=1; i<=2*m; i++) {
        ans[i] = ans[i-1]+dif[i];
    }
    
    for (int i=0; i<=2*m; i++) {
        cout << ans[i] << endl;
    }
}
