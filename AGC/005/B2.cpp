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
  cin >> N;
  vector<int> A(N);
  vector<int> pos(N+1);
  rep(i, N) {
    cin >> A[i];
    pos[A[i]] = i;
  }
  vector<int> mxl(N), mxr(N);
  set<int> se;
  se.insert(-1);
  se.insert(N);
  for(int i=1; i<=N; i++) {
    int p = pos[i];
    se.insert(p);
    mxl[p] = *(--se.upper_bound(p-1))+1;
    mxr[p] = *se.lower_bound(p+1)-1;
    // cout << se << endl;
  }
  // cout << mxl << "\n" << mxr << endl;
  ll ans = 0;
  rep(i, N) {
    ans += (ll)A[i] * (i-mxl[i]+1) * (mxr[i]-i+1);
  }
  cout << ans << endl;
  return 0;
}
