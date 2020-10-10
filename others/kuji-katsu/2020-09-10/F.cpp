#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/templates/print.hpp"
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<ll> X(n), Y(m);
  rep(i, n) cin >> X[i];
  rep(i, m) cin >> Y[i];
  ll s = 0, t = 0;
  rep(i, n-1) (s += (X[i+1]-X[i]) * (n-1-i) * (i+1)) %= mod;
  rep(j, m-1) (t += (Y[j+1]-Y[j]) *  (m-1-j) * (j+1)) %= mod;
  cout << s*t%mod << endk;
  return 0;
}
