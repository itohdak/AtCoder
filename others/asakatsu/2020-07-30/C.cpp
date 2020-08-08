#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  vector<int> S(m), C(m), D(n, -1);
  rep(i, m) {
    cin >> S[i] >> C[i];
    S[i]--;
    if(D[S[i]] == -1) D[S[i]] = C[i];
    else if(D[S[i]] != C[i]) {
      cout << -1 << "\n";
      return 0;
    }
  }
  if(n != 1 && D[0] == 0) {
    cout << -1 << "\n";
    return 0;
  }
  ll ans = 0;
  rep(i, n) {
    if(D[i] == -1) {
      if(n == 1) D[i] = 0;
      else if(i == 0) D[i] = 1;
      else D[i] = 0;
    }
    ans += D[i] * pow(10, n-1-i);
  }
  cout << ans << "\n";
  return 0;
}
