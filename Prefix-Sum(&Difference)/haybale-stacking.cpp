#include <iostream>

using namespace std;

const int maxN = 1e6+5;
int dif[maxN];
int hay[maxN];

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("stacking");
    int n, k;
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        int start;
        int end;
        cin >> start;
        cin >> end;
        dif[start]++;
        dif[end+1]--;
    }
    
    for (int i=1; i<=n; i++) {
        hay[i] = hay[i-1] + dif[i];
    }
    
    sort(hay, hay+n+1);
    
    cout << hay[(n+1)/2];
}
