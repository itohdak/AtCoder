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
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));

  auto bsearch = [&]() {
    auto test = [&](ll k) {
      auto boundary = [&](ll k, ll a) {
        ll tmp = k/a;
        ll res = (a>0 ? -longinf : longinf);
        for(int d=-2; d<=2; d++) {
          if(a*(tmp+d)<=k) {
            res = (a>0 ? max(tmp+d, res) : min(tmp+d, res));
          }
        }
        return res;
      };
      ll cnt = 0;
      rep(i, N) {
        int j;
        if(A[i] < 0) {
          ll lb = boundary(k, A[i]);
          j = lower_bound(all(A), lb) - begin(A);
          cnt += N - j - (i >= j);
        } else if(A[i] == 0) {
          if(k >= 0) cnt += N-1;
        } else {
          ll ub = boundary(k, A[i]);
          j = upper_bound(all(A), ub) - begin(A);
          cnt += j - (i < j);
        }
      }
      assert(cnt%2==0);
      return cnt/2 < K;
    };

    ll ng = longinf;
    ll ok = -longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      if(test(mid)) ok = mid;
      else ng = mid;
    }
    return ok+1;
  };

  cout << bsearch() << endl;
  return 0;
}
