#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int maxNM = 1e5+5;

int n, m;
int cowX[maxNM];
int cowY[maxNM];
bool visited[maxNM];

vector<int> edges[maxNM];

int maxX;
int minX;
int maxY;
int minY;

int ans = 4e8+5;

void dfs (int cur) {
    visited[cur] = true;
    
    maxX = max(maxX, cowX[cur]);
    minX = min(minX, cowX[cur]);
    maxY = max(maxY, cowY[cur]);
    minY = min(minY, cowY[cur]);
    
    for (int nxt : edges[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

signed main() {
    baseIO("fenceplan");
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> cowX[i] >> cowY[i];
    }
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for (int i=1; i<=n; i++) {
        if (!visited[i]) {
            maxX = cowX[i];
            minX = cowX[i];
            maxY = cowY[i];
            minY = cowY[i];
            dfs(i);
            ans = min(ans, 2*(maxY-minY+maxX-minX));
        }
    }
    
    cout << ans << endl;
}
