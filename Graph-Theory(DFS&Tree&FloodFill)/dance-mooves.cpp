#include <iostream>
#include <vector>
#include <set>

#define int long long

using namespace std;

int n, k;
const int maxN = 1e5+5;
int cows[maxN];
set<int> pass[maxN];
int swaps[2*maxN][2];
vector<int> edges[maxN];

int cmp;
vector<int> cmps[maxN];
bool visited[maxN];
void dfs(int cur) {
    visited[cur] = true;
    cmps[cmp].push_back(cur);
    
    for (int nxt : edges[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

int ans[maxN];

signed main() {
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cows[i] = i;
    }
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        swaps[i][0] = a;
        swaps[i][1] = b;
    }
    
    for (int i=0; i<k; i++) {
        int orgA = cows[swaps[i][0]];
        int orgB = cows[swaps[i][1]];
        pass[orgA].insert(swaps[i][1]);
        pass[orgB].insert(swaps[i][0]);
        cows[swaps[i][0]] = orgB;
        cows[swaps[i][1]] = orgA;
    }
    
    for (int i=1; i<=n; i++) {
        pass[i].insert(i);
    }
    
    for (int i=1; i<=n; i++) {
        edges[i].push_back(cows[i]);
    }
    
    cmp = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
            cmp++;
        }
    }
    
    for (int i=0; i<=cmp; i++) {
        set<int> vst;
        for (int j : cmps[i]) {
            for (int num : pass[j]) {
                vst.insert(num);
            }
        }
        for (int j : cmps[i]) {
            ans[j] = vst.size();
        }
    }
    
    for (int i=1; i<=n; i++) {
        cout << ans[i] << endl;
    }
}
