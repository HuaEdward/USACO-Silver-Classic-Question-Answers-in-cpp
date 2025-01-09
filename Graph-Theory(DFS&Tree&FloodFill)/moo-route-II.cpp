#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

struct edge {
    int r, d, s;
    bool deleted;
    
    bool operator < (const edge other) const {
        return r > other.r;
    }
};

const int MAX_MN = 2e5+5;
vector<edge> edges[MAX_MN];
int restr[MAX_MN];
int ans[MAX_MN];

int n, m;
bool first;

void dfs(int cur, int time) {
    ans[cur] = min(ans[cur], time);
    
    if (first) {
        first = false;
        for (auto &it : edges[cur]) {
            if (it.deleted == false) {
                it.deleted = true;
                dfs(it.d, it.s);
            }
        }
    }
    
    for (auto &it : edges[cur]) {
        if (it.r >= time+restr[cur]) {
            if (it.deleted == false && it.s < ans[it.d]){
                it.deleted = true;
                dfs(it.d, it.s);
            }
        } else {
            break;
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, R, D, S;
        cin >> a >> R >> D >> S;
        edges[a].push_back({R, D, S, false});
    }
    for (int i=1; i<=n; i++) {
        cin >> restr[i];
        ans[i] = 2e9;
        sort(edges[i].begin(), edges[i].end());
    }
    
    first = true;
    dfs(1, 0);
    
    for (int i=1; i<=n; i++) {
        if (ans[i] != 2e9) {
            cout << ans[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
