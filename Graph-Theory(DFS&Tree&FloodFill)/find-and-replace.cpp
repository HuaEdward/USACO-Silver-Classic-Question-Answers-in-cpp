#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

string originStr;
string goalStr;

set<int> from[60];
bool to[60];

bool visited[60];

int GetInt(char c) {
    if (c >= 'a' && c <= 'z') {
        return c-'a';
    } else {
        return c-'A'+26;
    }
}

void dfs(int cur) {
    visited[cur] = true;
    
    for (int nxt : from[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
        }
    }
}

void process() {
    for (int i=0; i<52; i++) {
        from[i].clear();
        to[i] = 0;
    }
    cin >> originStr >> goalStr;
    if (originStr == goalStr) {
        cout << 0 << endl;
        return;
    }
    for (int i=0; i<originStr.length(); i++) {
        from[GetInt(originStr[i])].insert(GetInt(goalStr[i]));
        to[GetInt(goalStr[i])] = true;
    }
    
    bool pass = true;
    for (int i=0; i<52; i++) {
        if(from[i].size()>1) {
            pass = false;
            break;
        }
    }
    if (!pass) {
        cout << -1 << endl;
        return;
    }

    pass = false;
    for (int i=0; i<52; i++) {
        if (to[i] == false) {
            pass = true;
            break;
        }
    }
    if (!pass) {
        cout << -1 << endl;
        return;
    }

    int ans = 0;
    for (int i=0; i<52; i++) {
        if (from[i].size() > 0 && *(from[i].begin()) != i) {
            ans++;
        }
    }
    
    memset(visited, false, sizeof(visited));
    for (int i=0; i<52; i++) {
        if (to[i] == false && !visited[i]) {
            dfs(i);
        }
    }
    
    
    for (int i=0; i<52; i++) {
        if (from[i].size() > 0 && !visited[i] && *(from[i].begin()) != i) {
            ans ++;
            dfs(i);
        }
    }
    
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        process();
    }
}
