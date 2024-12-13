#include <iostream>
#include <map>

#define int long long

using namespace std;

const int maxN = 5e5+5;
int firstArr[maxN];
int secondArr[maxN];
int secondArrR[maxN];
int exist[maxN];
map<int, int> numMap;
map<int, int> numMapR;
map<int, int> firstMap;
map<int, int> secondMap;
map<int, int> secondMapR;

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<k; i++) {
        cin >> firstArr[i];
        exist[firstArr[i]] ++;
        firstMap[firstArr[i]] = i;
    }
    for (int i=0; i<k; i++) {
        cin >> secondArr[i];
        exist[secondArr[i]] ++;
        secondMap[secondArr[i]] = i;
    }
    
    // Normal sequence
    for (int i=0; i<k; i++) {
        if (exist[secondArr[i]] == 2) {
            int a = firstMap[secondArr[i]];
            int b = i;
            
            if (a-b >= 0) {
                numMap[a-b] ++;
            } else {
                numMap[a-b+k] ++;
            }
        }
    }
    
    int ansF = 0;
    for (auto i : numMap) {
        ansF = max(ansF, i.second);
    }
    
    // Reverse
    for (int i=0; i<k; i++) {
        secondArrR[k-i-1] = secondArr[i];
        secondMapR[secondArrR[k-i-1]] = k-i-1;
    }
    
    for (int i=0; i<k; i++) {
        if (exist[secondArrR[i]] == 2) {
            int a = firstMap[secondArrR[i]];
            int b = i;
            
            if (a-b >= 0) {
                numMapR[a-b] ++;
            } else {
                numMapR[a-b+k] ++;
            }
        }
    }
    
    int ansS = 0;
    for (auto i : numMapR) {
        ansS = max(ansS, i.second);
    }
    
    int ans = max(ansF, ansS);
    
    for (int i=1; i<=n; i++) {
        if (exist[i] == 0) {
            ans ++;
        }
    }
    cout << ans;
}
