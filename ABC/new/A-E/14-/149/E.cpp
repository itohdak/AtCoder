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
  int N;
  ll M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  vector<ll> sum(N+1);
  rep(i, N) sum[i+1] = sum[i] + A[i];
  // cout << sum << endl;

  if(M == N*N) {
    cout << sum[N] * 2 * N << endl;
    return 0;
  }

  ll val = 0;
  int mn = 0;
  ll cnt = 0;
  auto test = [&](ll t) {
    cnt = 0;
    val = 0;
    mn = 0;
    rep(i, N) {
      auto j = lower_bound(all(A), t-A[i]) - begin(A);
      if(j > 0) {
        mn = max(A[i]+A[j-1], mn);
      }
      val += (sum[N]-sum[j]) + A[i] * (N-j);
      cnt += (N-j);
    }
    return cnt <= M;
  };
  auto binary_search = [&]() {
    ll ng = 0, ok = 200005;
    while(abs(ok - ng) > 1) {
      ll mid = (ok + ng) / 2;
      if(test(mid)) ok = mid;
      else ng = mid;
    }
    return ok;
  };
  ll mx = binary_search();
  test(mx);
  cout << val+(M-cnt)*mn << endl;
  return 0;
}
