#include <iostream>
#include <vector>

using namespace std;

const int MAX_MN = 3005;

int n, m;
vector<int> edges[MAX_MN];
bool closed[MAX_MN];
bool visited[MAX_MN];
int closes[MAX_MN];

void dfs(int cur) {
    visited[cur] = true;
    for (int nxt : edges[cur]) {
        if (!visited[nxt] && !closed[nxt]) {
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

int main() {
    baseIO("closing");
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> closes[i];
    }

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            sum++;
        }
    }
    
    if (sum == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    for (int j = 1; j <= n; j++) {
        visited[j] = false;
    }

    for (int i = 1; i < n; i++) {
        closed[closes[i]] = true;

        int sum = 0;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && !closed[j]) {
                dfs(j);
                sum++;
            }
        }
        if (sum == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

        for (int j = 1; j <= n; j++) {
            visited[j] = false;
        }
    }

    return 0;
}
