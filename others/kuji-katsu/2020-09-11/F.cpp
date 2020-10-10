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
  ll n, k; cin >> n >> k;
  vector<ll> A(n);
  vector<ll> neg, pos;
  ll zero = 0;
  rep(i, n) {
    cin >> A[i];
    if(A[i] < 0) neg.push_back(A[i]);
    else if(A[i] == 0) zero++;
    else pos.push_back(A[i]);
  }
  sort(all(neg));
  sort(all(pos));
  ll nneg = 1LL * neg.size() * pos.size();
  ll nzero = zero * (n-1) - zero * (zero-1) / 2;
  if(k <= nneg) {
    k--;
    auto count = [&](ll t) {
      assert(t < 0);
      ll cnt = 0;
      for(ll ne: neg) {
        cnt += end(pos)-lower_bound(all(pos), (abs(t)+abs(ne)-1)/abs(ne));
      }
      return cnt;
    };
    auto bsearch = [&]() {
      auto test = [&](ll t) {
        return count(t) <= k;
      };
      ll ok = -longinf, ng = 0;
      while(abs(ok-ng) > 1) {
        ll mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll ret = bsearch();
    cout << (count(ret) < k+1 ? ret+1 : ret) << endk;
  } else if(k <= nneg+nzero) {
    cout << 0 << endk;
  } else {
    ll rem = k-(nneg+nzero)-1;
    for(ll& ne: neg) ne *= -1;
    reverse(all(neg));
    // cout << neg << endk;
    // cout << pos << endk;
    auto count = [&](ll t) {
      assert(t > 0);
      ll cnt = 0;
      rep(i, neg.size()) {
        auto itr = upper_bound(all(neg), t/neg[i]);
        cnt += max((int(itr-begin(neg))-i-1), 0);
      }
      rep(i, pos.size()) {
        auto itr = upper_bound(all(pos), t/pos[i]);
        cnt += max((int(itr-begin(pos))-i-1), 0);
      }
      return cnt;
    };
    auto bsearch = [&]() {
      auto test = [&](ll t) {
        return count(t) <= rem;
      };
      ll ok = 1, ng = longinf;
      while(abs(ok-ng) > 1) {
        ll mid = (ok+ng)/2;
        // cout << mid << ' ' << count(mid) << endk;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    ll ret = bsearch();
    cout << (count(ret) < rem+1 ? ret+1 : ret) << endk;
  }
  return 0;
}
