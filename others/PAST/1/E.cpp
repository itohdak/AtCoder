#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N, Q;
  cin >> N >> Q;
  vector<vector<bool>> follow(N, vector<bool>(N));
  rep(q, Q) {
    int t;
    cin >> t;
    int a, b;
    set<int> se;
    switch(t) {
      case 1:
        cin >> a >> b;
        follow[--a][--b] = 1;
        break;
      case 2:
        cin >> a;
        --a;
        rep(i, N) if(follow[i][a]) follow[a][i] = 1;
        break;
      case 3:
        cin >> a;
        --a;
        rep(i, N) if(follow[a][i]) se.insert(i);
        for(int i: se) rep(j, N) if(follow[i][j]) follow[a][j] = 1;
        break;
    }
  }
  rep(i, N) {
    rep(j, N) {
      if(i == j) cout << "N";
      else cout << (follow[i][j] ? "Y" : "N");
    }
    cout << endl;
  }
  return 0;
}
