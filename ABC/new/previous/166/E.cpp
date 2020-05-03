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
  int N;
  cin >> N;
  vector<ll> A(N);
  map<ll, vector<int> > mp;
  rep(i, N) {
    cin >> A[i];
    mp[A[i]+(i+1)].push_back(i);
  }
  // cout << mp << endl;
  ll ans = 0;
  rep(i, N) {
    ll tmp = -A[i]+(i+1);
    if(mp.count(tmp)) {
      auto v = mp[tmp];
      ans += (upper_bound(all(v), i) - v.begin());
    }
  }
  cout << ans << endl;
  return 0;
}
