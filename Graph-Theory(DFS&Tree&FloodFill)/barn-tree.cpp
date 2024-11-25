#include <iostream>
#include <vector>
#define int long long

using namespace std;

const int max_n = 2e5+5;
int n;
int tot;
int ave;
int hays[max_n];
vector<int> edges[max_n];
bool flag[max_n];
vector<int> waited[max_n];
int ansNum, from[max_n], to[max_n], amount[max_n];

void dfs1 (int cur) {
    flag[cur] = true;
    for (int i : edges[cur]) {
        if (!flag[i]) {
            dfs1(i);
            hays[cur] += hays[i];
        }
    }
    flag[cur] = false;
}

void dfs2 (int cur) {
    flag[cur] = true;
    for (int i : edges[cur]) {
        if (!flag[i]) {
            if (hays[i] > 0) {
                dfs2(i);
                
                from[ansNum] = i;
                to[ansNum] = cur;
                amount[ansNum] = hays[i];
                ansNum ++;
            } else if (hays[i] == 0) {
                dfs2(i);
            } else {
                waited[cur].push_back(i);
            }
        }
    }
    for (int i : waited[cur]) {
        from[ansNum] = cur;
        to[ansNum] = i;
        amount[ansNum] = -hays[i];
        ansNum ++;
        dfs2(i);
    }
    flag[cur] = false;
}

signed main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> hays[i];
        tot += hays[i];
    }
    ave = tot / n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        hays[i] -= ave;
    }
    dfs1(1);
    
    dfs2(1);
    
    cout << ansNum << endl;
    for (int i=0; i<ansNum; i++) {
        cout << from[i] << " " << to[i] << " " << amount[i] << endl;
    }
}
