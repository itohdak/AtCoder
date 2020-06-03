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
  int N;
  ll X;
  cin >> N >> X;
  vector<ll> W(N);
  rep(i, N) cin >> W[i];
  vector<vector<map<ll, ll>>> vmp(2, vector<map<ll, ll>>(2));
  vector<map<ll, ll>> res(2);
  rep(n, 2) {
    vmp[n][0][0] = 1;
    vmp[n][1][0] = 1;
    int ib = (n==0 ? 0 : N/2);
    int ie = (n==0 ? N/2: N);
    REP(i, ib, ie) {
      int id = i%2;
      vmp[n][id].clear();
      for(auto m: vmp[n][1-id]) {
        vmp[n][id][m.first] += m.second;
        vmp[n][id][m.first+W[i]] += m.second;
      }
    }
    for(auto m: vmp[n][(ie+1)%2]) {
      res[n][m.first] = m.second;
    }
  }
  ll ans = 0;
  for(auto m: res[0]) {
    if(m.first > X) continue;
    ans += m.second * res[1][X-m.first];
  }
  cout << ans << endl;
  return 0;
}
