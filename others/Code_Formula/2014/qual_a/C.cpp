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
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<vector<ll>> A(N, vector<ll>(K));
  vector<int> id(K);
  set<int> se;
  rep(i, N) rep(j, K) cin >> A[i][j];
  rep(i, N) {
    set<int> tmpSe;
    rep(j, K) {
      while(id[j] <= i && (int)se.size() + (N-1-i)*j < K) {
        if(!se.count(A[id[j]][j])) {
          se.insert(A[id[j]][j]);
          tmpSe.insert(A[id[j]][j]);
        }
        id[j]++;
      }
    }
    for(int s: tmpSe) cout << s << ' ';
    cout << endl;
  }
  return 0;
}
