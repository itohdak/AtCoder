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
  int N, Q;
  cin >> N >> Q;
  vector<ll> A(N), sum(N+1), odd(N+1), even(N+1);
  rep(i, N) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
    odd[i+1] = odd[i] + (i%2 ? A[i] : 0);
    even[i+1] = even[i] + (i%2 ? 0 : A[i]);
  }
  auto bsearch = [&](ll x) {
    auto test = [&](ll k) {
      int ub = upper_bound(all(A), x+k-1) - A.begin();
      int lb = lower_bound(all(A), x-k) - A.begin();
      int cnt = ub - lb;
      int ub2 = N - cnt;
      return ub <= ub2;
    };

    ll ok = 0, ng = longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  // cout << A << endl;
  rep(q, Q) {
    ll x;
    cin >> x;
    ll k = bsearch(x);
    int ub = upper_bound(all(A), x+k-1) - A.begin();
    int lb = lower_bound(all(A), x-k) - A.begin();
    int cnt = ub - lb;
    int ub2 = N - cnt;
    ll ans = 0;
    ans += sum[N] - sum[ub2];
    if(ub != ub2) ans += sum[ub2] - sum[ub+(ub2-ub)/2];
    // cout << k << ' ' << cnt << ' ' << ans << ' ' << lb << endl;
    ans += (N%2 ? even : odd)[lb];
    cout << ans << endl;
  }
  return 0;
}
