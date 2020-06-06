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
  vector<ll> neg, pos;
  ll z = 0, n = 0, p = 0;
  rep(i, N) {
    ll a;
    cin >> a;
    if(a == 0) z++;
    else if(a > 0) pos.push_back(a);
    else neg.push_back(-a);
  }
  sort(all(neg));
  sort(all(pos));
  n = neg.size(), p = pos.size();
  ll cnt1 = n*p;
  ll cnt2 = z*(z-1)/2 + z*(N-z);
  ll cnt3 = n*(n-1)/2 + p*(p-1)/2;
  assert(cnt1 + cnt2 + cnt3 == N*(N-1)/2);

  auto solve1 = [&]() {
    auto test = [&](ll k) {
      ll cnt = 0;
      int j = p;
      rep(i, n) {
        while(j>0 && neg[i]*pos[j-1]>=k) j--;
        cnt += p - j;
      }
      return cnt < K;
    };

    ll ng = 0, ok = longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    cout << -ok+1 << endl;
  };

  auto solve2 = [&]() {
    auto test = [&](ll k) {
      ll cnt = 0;
      int j = n;
      rep(i, n) {
        while(j>0 && neg[i]*neg[j-1]>k) j--;
        cnt += j-(i<j);
      }
      j = p;
      rep(i, p) {
        while(j>0 && pos[i]*pos[j-1]>k) j--;
        cnt += j-(i<j);
      }
      assert(cnt%2==0);
      return cnt/2 < K-cnt1-cnt2;
    };

    ll ng = longinf, ok = 0;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    cout << ok+1 << endl;
  };

  if(K <= cnt1) {
    solve1();
  } else if(K <= cnt1 + cnt2) {
    cout << 0 << endl;
  } else {
    solve2();
  }
  return 0;
}
