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

#define MAX_N 40
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N), sum(N+1);
  rep(i, N) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  vector<ll> B;
  rep(l, N+1) REP(r, l+1, N+1) B.push_back(sum[r]-sum[l]);
  int M = B.size();
  vector<vector<int>> D(M, vector<int>(MAX_N));
  rep(k, MAX_N) {
    rep(i, M) {
      D[i][MAX_N-1-k] = (B[i]>>k)&1;
    }
  }
  vector<set<int>> vse(2);
  rep(i, M) vse[0].insert(i);
  ll ans = 0;
  ll pw = 1LL<<(MAX_N-1);
  int id = 1;
  rep(k, MAX_N) {
    vse[id].clear();
    for(int i: vse[1-id]) {
      if(D[i][k]) vse[id].insert(i);
    }
    if(vse[id].size() >= K) {
      ans += pw;
    } else {
      vse[id].clear();
      for(int i: vse[1-id]) vse[id].insert(i);
    }
    pw >>= 1;
    id = 1-id;
  }
  cout << ans << endl;
  return 0;
}
