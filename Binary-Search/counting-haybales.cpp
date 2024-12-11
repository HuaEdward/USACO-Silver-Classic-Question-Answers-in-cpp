#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> qs;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("haybales");
    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        qs.push_back(num);
    }
    
    sort(qs.begin(), qs.end());
    
    for (int i=0; i<q; i++) {
        int f, s;
        cin >> f >> s;
        
        auto l = lower_bound(qs.begin(), qs.end(), f);
        auto r = upper_bound(qs.begin(), qs.end(), s);
        cout << r-l << endl;
    }
}
