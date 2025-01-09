#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int point, relevence;
};

const int MAX_NQ = 5005;
vector<edge> edges[MAX_NQ];
int k[MAX_NQ];
int v[MAX_NQ];
vector<int> videos[MAX_NQ];
int rs[MAX_NQ];

int ans;
int minNum;
void dfs (int cur, int parent) {
    for (edge child : edges[cur]) {
        if (child.point != parent) {
            rs[child.point] = min(rs[cur], child.relevence);
            if (rs[child.point] >= minNum) {
                ans++;
            }
            dfs(child.point, cur);
        }
    }
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("mootube");
    int n, q;
    cin >> n >> q;
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b,c});
        edges[b].push_back({a,c});
    }
    for (int i=0; i<q; i++) {
        cin >> k[i] >> v[i];
    }
    
    for (int i=0; i<q; i++) {
        ans = 0;
        for (int i=1; i<=n; i++) {
            rs[i] = 2e9;
        }
        minNum = k[i];
        dfs(v[i], 0);
        cout << ans << endl;
    }
}
