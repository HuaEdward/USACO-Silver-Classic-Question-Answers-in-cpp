#include <iostream>

using namespace std;

int n, h, p, s;
char chars[100005];
int pH[100005];
int pP[100005];
int pS[100005];
int split;
int maxNum;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    baseIO("hps");
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> chars[i];
    }
    
    for (int i=1; i<=n; i++) {
        if (chars[i] == 'H') {
            h++;
            pH[i] = h;
            pP[i] = p;
            pS[i] = s;
        } else if (chars[i] == 'P') {
            p++;
            pH[i] = h;
            pP[i] = p;
            pS[i] = s;
        } else {
            s++;
            pH[i] = h;
            pP[i] = p;
            pS[i] = s;
        }
    }
    
    for (int split=0; split <= n; split ++) {
        int maxFirstHalf = max(pP[split]-pP[0],max(pH[split]-pH[0],pS[split]-pS[0]));
        int maxSecondHalf = max(pP[n]-pP[split],max(pH[n]-pH[split],pS[n]-pS[split]));
        maxNum = max(maxNum, maxFirstHalf + maxSecondHalf);
    }
    
    cout << maxNum;
}
