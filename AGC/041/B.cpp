#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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
  int N, V, P;
  ll M;
  cin >> N >> M >> V >> P;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  vector<ll> sum(N+1);
  rep(i, N) sum[i+1] = sum[i] + A[i];
  int cnt = 0;
  rep(i, N) {
    ll val = A[i]+M;
    int j1 = upper_bound(all(A), A[i]) - A.begin();
    int j2 = upper_bound(all(A), val) - A.begin();
    int j3 = N-P+1;
    j1 = min(j3, j1);
    j2 = min(j3, j2);
    ll margin = M*j1 + (val*(j2-j1)-(sum[j2]-sum[j1])) + (N-j3)*M;
    int pos = N-j2+1;
    if(margin >= M*V && pos <= P) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
