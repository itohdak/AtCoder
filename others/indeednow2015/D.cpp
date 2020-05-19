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
  ll N, C;
  cin >> N >> C;
  vector<int> A(N);
  rep(i, N) {
    cin >> A[i];
    A[i]--;
  }
  map<int, vector<int>> mp;
  rep(i, C) mp[i].push_back(-1);
  rep(i, N) mp[A[i]].push_back(i);
  rep(i, C) mp[i].push_back(N);
  // cout << mp << endl;
  vector<ll> ans(C, N*(N+1)/2);
  rep(i, N) {
    rep(j, mp[i].size()) {
      if(j) {
        ll n = mp[i][j]-mp[i][j-1];
        ans[i] -= (n-1)*n/2;
        // cout << n*(n+1)/2 << endl;
      }
    }
  }
  for(ll a: ans) cout << a << endl;
  return 0;
}
