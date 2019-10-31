#include <bits/stdc++.h>
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
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  int sum = accumulate(all(A), 0);
  ll ans = longinf;
  int cand[] = {sum/N-1, sum/N, sum/N+1};
  for(int c: cand) {
    ll tmp = 0;
    rep(i, N) tmp += (A[i] - c) * (A[i] - c);
    ans = min(tmp, ans);
  }
  cout << ans << endl;
  return 0;
}

