#include <iostream>
#include <vector>
#include <set>
#include <cstring>

#define int long long

using namespace std;

const int MAX_MN = 1e5+5;
vector<int> edges[MAX_MN];
bool visited[MAX_MN];
int cmps[MAX_MN];
set<int> cmpNums[MAX_MN];
int dis1[MAX_MN];
int disN[MAX_MN];

int n, m;
int cmp = 0;
int Ncmp = 0;
void dfs(int cur) {
    visited[cur] = true;
    cmps[cur] = cmp;
    cmpNums[cmp].insert(cur);
    if (cur == n) {
        Ncmp = cmp;
    }

    for (int nxt : edges[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

void process() {
    memset(visited, false, sizeof(visited));
    
    cin >> n >> m;
    
    for (int i=0; i<=n; i++) {
        dis1[i] = disN[i] = n*n+5;
        cmpNums[i].clear();
        edges[i].clear();
    }
    cmp = 0;
    Ncmp = 0;
    
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            dfs(i);
            cmp++;
        }
    }
    
    if (Ncmp == 0) {
        cout << 0 << endl;
        return;
    }
    
    int l=0;
    int r=0;
    for (int i=1; i<=n; i++) {
        if (cmps[i] != 0) {
            auto it = cmpNums[0].upper_bound(i);
            if (it == cmpNums[0].end()) {
                it--;
                l = *it;
                dis1[cmps[i]] = min(dis1[cmps[i]], (l-i)*(l-i));
            } else {
                r = *it;
                it--;
                l = *it;
                int curDis = min((r-i)*(r-i), (l-i)*(l-i));
                dis1[cmps[i]] = min(dis1[cmps[i]], curDis);
            }
        }
        
        if (cmps[i] != Ncmp) {
            auto it = cmpNums[Ncmp].upper_bound(i);
            if (it == cmpNums[Ncmp].begin()) {
                r = *it;
                disN[cmps[i]] = min(disN[cmps[i]], (r-i)*(r-i));
            } else {
                r = *it;
                it--;
                l = *it;
                int curDis = min((r-i)*(r-i), (l-i)*(l-i));
                disN[cmps[i]] = min(disN[cmps[i]], curDis);
            }
        }
    }
    
    int ans = disN[0];
    for (int i=1; i<cmp; i++) {
        if (i != Ncmp) {
            ans = min(ans, dis1[i]+disN[i]);
        } else {
            ans = min(ans, dis1[i]);
        }
    }
    
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        process();
    }
    
}
