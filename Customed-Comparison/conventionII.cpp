#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cow {
    int seniority, arrive, spent, begin, start;
    
    bool operator < (const cow& other) const {
        return seniority > other.seniority;
    }
};

const int maxN = 1e5+5;
cow cows[maxN];
priority_queue<cow> waiting;
int startTime;

bool cmp (const cow& f, const cow& s) {
    return f.arrive < s.arrive;
}

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("convention2");
    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> cows[i].arrive >> cows[i].spent;
        cows[i].seniority = i;
    }
    sort(cows, cows+n, cmp);
    
    startTime = cows[0].arrive;
    
    int ans = 0;
    for (int idx=0; idx<n; idx++) {
        if (cows[idx].arrive > startTime) {
            if (waiting.size() == 0) {
                startTime = cows[idx].arrive + cows[idx].spent;
            } else {
                ans = max(ans, startTime - waiting.top().arrive);
                startTime += waiting.top().spent;
                waiting.pop();
                if (startTime < cows[idx].arrive) {
                    idx --;
                } else {
                    waiting.push(cows[idx]);
                }
            }
        } else {
            waiting.push(cows[idx]);
        }
    }
    
    
    while (waiting.size() != 0) {
        ans = max(ans, startTime - waiting.top().arrive);
        startTime += waiting.top().spent;
        waiting.pop();
    }
    
    cout << ans;
}
