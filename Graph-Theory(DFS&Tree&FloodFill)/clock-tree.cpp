#include <iostream>
#include <vector>

using namespace std;

int clocks[2505];
int testClocks[2505];
vector<int> edges[2505];

void dfs(int cur, int parent) {
    int time = testClocks[cur];
    for (int children : edges[cur]) {
        if (children != parent) {
            dfs(children, cur);
            time += 12-testClocks[children];
        }
    }
    testClocks[cur] = time % 12;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("clocktree");
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> clocks[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    int ans = 0;
    for (int i=1; i<=n; i++) {
        for (int i=1; i<= n; i++) {
            testClocks[i] = clocks[i];
        }
        dfs(i, 0);
        if (testClocks[i] == 0 || testClocks[i] == 1) {
            ans++;
        }
    }
    
    cout << ans << endl;
    return 0;
}
