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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> H(n), S(n);
  rep(i, n) cin >> H[i] >> S[i];
  auto bsearch = [&]() {
    auto test = [&](ll k) {
      vector<ll> timeLimit(n);
      rep(i, n) {
        if(k-H[i] < 0) return false;
        timeLimit[i] = (k-H[i])/S[i];
      }
      sort(all(timeLimit));
      rep(i, n) if(timeLimit[i] < i) return false;
      return true;
    };
    ll ok = longinf, ng = 0;
    while(ok-ng>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
