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
  ll N; int M;
  cin >> N >> M;
  vector<ll> X(M);
  rep(i, M) {
    cin >> X[i];
    X[i]--;
  }
  auto bsearch = [&]() {
    auto test = [&](ll k) {
      // cout << k << ": ";
      ll mn = 0;
      rep(i, M) {
        // cout << mn+1 << ' ';
        if(k < X[i]-mn) {
          // cout << "x" << endl;
          return false;
        }
        mn = max({X[i], X[i]+k-2*(X[i]-mn), X[i]+(k-(X[i]-mn))/2}) + 1;
        if(i != M-1) mn = min(X[i+1], mn);
      }
      // cout << (mn >= N-1 ? "o" : "x") << endl;
      return (mn >= N);
    };

    ll ng = -1, ok = longinf;
    while(abs(ok-ng) > 1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endl;
  return 0;
}
