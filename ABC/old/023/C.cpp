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
  int r, c, k; cin >> r >> c >> k;
  int n; cin >> n;
  vector<int> R(n), C(n);
  vector<int> cntr(c), cntc(r);
  rep(i, n) {
    cin >> R[i] >> C[i];
    R[i]--; C[i]--;
    cntr[C[i]]++; cntc[R[i]]++;
  }
  ll ans = 0;
  map<int, int> mpr, mpc;
  rep(i, c) mpr[cntr[i]]++;
  rep(i, r) mpc[cntc[i]]++;
  for(auto ele: mpr) {
    if(mpc.count(k-ele.first)) {
      ans += ele.second * mpc[k-ele.first];
    }
  }
  rep(i, n) if(cntr[C[i]]+cntc[R[i]]-1==k) ans++;
  rep(i, n) if(cntr[C[i]]+cntc[R[i]]-1==k-1) ans--;
  cout << ans << "\n";
  return 0;
}
