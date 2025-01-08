#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct event{
    int day, ID;
    bool positive;
    int change;
    
    bool operator < (const event& other) const {
        return day < other.day;
    }
};

map<int, int> cowsID;
event events[100005];
set<int> cowsNum;
multiset<int, greater<int>> cows;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("measurement");
    int n, g;
    cin >> n >> g;
    for (int i=0; i<n; i++) {
        cin >> events[i].day >> events[i].ID;
        cowsNum.insert(events[i].ID);
        cowsID[events[i].ID] = g;
        char c;
        cin >> c;
        if (c == '+') {
            events[i].positive = true;
        } else {
            events[i].positive = false;
        }
        cin >> events[i].change;
    }
    
    sort(events, events + n);
    
    for (int i=0; i<cowsNum.size(); i++) {
        cows.insert(g);
    }
    
    int ans = 0;
    for (int i=0; i<n; i++) {
        // States: 1=>Not greatest; 2=>Greatest alone; 3=>Greatest with others
        // State before event
        int preState = 0;
        if (cowsID[events[i].ID] != *cows.begin()) {
            preState = 1;
        } else {
            preState = 2;
            auto greatestCow = cows.begin();
            greatestCow ++;
            if (cowsID[events[i].ID] == *greatestCow){
                preState = 3;
            }
        }
        
        // State after event
        int currentState = 0;
        cows.erase(cows.lower_bound(cowsID[events[i].ID]));
        
        if (events[i].positive) {
            cowsID[events[i].ID] += events[i].change;
        } else {
            cowsID[events[i].ID] -= events[i].change;
        }
        
        cows.insert(cowsID[events[i].ID]);
        
        if (cowsID[events[i].ID] != *cows.begin()) {
            currentState = 1;
        } else {
            currentState = 2;
            auto greatestCow = cows.begin();
            greatestCow ++;
            if (cowsID[events[i].ID] == *greatestCow){
                currentState = 3;
            }
        }
        
        if (preState != currentState) {
            ans ++;
        }
    }
    
    cout << ans;
}
