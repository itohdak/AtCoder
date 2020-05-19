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
  ll K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  map<ll, vector<int>> mp;
  ll sum = 0;
  ll ans = 0;
  mp[1].push_back(-1);
  rep(i, N) {
    sum += A[i];
    if(mp.count((sum-i)%K)) ans += mp[(sum-i)%K].end() - lower_bound(all(mp[(sum-i)%K]), i-K+1);
    mp[(sum-i)%K].push_back(i);
  }
  cout << ans << endl;
  return 0;
}
