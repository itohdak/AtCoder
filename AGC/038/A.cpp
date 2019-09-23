#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int H, W, A, B;
  cin >> H >> W >> A >> B;
  rep(i, B) {
    rep(j, A) cout << 1;
    rep(j, W-A) cout << 0;
    cout << endl;
  }
  rep(i, H-B) {
    rep(j, A) cout << 0;
    rep(j, W-A) cout << 1;
    cout << endl;
  }
  return 0;
}

