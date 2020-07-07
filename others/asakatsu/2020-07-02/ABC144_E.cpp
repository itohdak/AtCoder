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
  ll K;
  cin >> N >> K;
  vector<ll> A(N), F(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];
  sort(all(A));
  sort(all(F), greater<ll>());
  auto bsearch = [&]() {
    auto test = [&](ll k) {
      ll cur = 0;
      rep(i, N) cur += max(A[i]-k/F[i], 0LL);
      return cur <= K;
    };

    ll ok = longinf, ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << "\n";
  return 0;
}
