#include <iostream>
#include <algorithm>

using namespace std;

int x,y,k,m;
bool tried[101][101][101];
int minNum = 100000;

void baseIO(string s) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

void recursion(int f, int s, int left){
    if (left == 0) {
        minNum = min(minNum, abs(f+s-m));
        return;
    }
    if (tried[f][s][left]) {
        return;
    } else {
        tried[f][s][left] = true;
        
        recursion(x, s, left-1);
        
        recursion(f, y, left-1);
        
        recursion(0, s, left-1);
        
        recursion(f, 0, left-1);
        
        if (x-f>=s) {
            recursion(f+s, 0, left-1);
        } else {
            recursion(x, s-x+f, left-1);
        }
        
        if (y-s>=f) {
            recursion(0, s+f, left-1);
        } else {
            recursion(f-y+s, y, left-1);
        }
        
    }
}

int main() {
    baseIO("pails");
    cin >> x >> y >> k >> m;
    recursion(0, 0, k);
    cout << minNum;
}
