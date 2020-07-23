#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  rep(i, n) A.push_back(A[i]);
  int logK = log2(n*k);
  vector<vector<ll>> next(logK+1, vector<ll>(n));
  map<ll, vector<int>> pos;
  rep(i, 2*n) pos[A[i]].push_back(i);
  for(auto ele: pos) {
    int prev = -1;
    for(int p: ele.second) {
      if(prev >= n) break;
      if(prev != -1) next[0][prev] = (p+1)-prev;
      prev = p;
    }
  }
  rep(k, logK) rep(i, n) {
    if(LONG_LONG_MAX-next[k][(i+next[k][i])%n] > next[k][i]) {
      next[k+1][i] = next[k][i] + next[k][(i+next[k][i])%n];
    } else {
      next[k+1][i] = longinf;
    }
  }
  ll p = 0;
  while(1) {
    bool updated = false;
    rrep(i, logK) {
      if(p+next[i][p%n] < n*k) {
        p = p+next[i][p%n];
        updated = true;
        break;
      }
    }
    if(!updated) break;
  }
  vector<ll> ans;
  set<ll> se;
  for(ll i=p; i<n*k; i++) {
    if(se.count(A[i%n])) {
      while(se.count(A[i%n])) {
        se.erase(ans.back());
        ans.pop_back();
      }
    } else {
      ans.push_back(A[i%n]);
      se.insert(A[i%n]);
    }
  }
  for(ll a: ans) cout << a << ' ';
  cout << "\n";
  return 0;
}
