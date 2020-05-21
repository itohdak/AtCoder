#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<ll> W(N);
  vector<int> P(N);
  rep(i, N) cin >> W[i] >> P[i];

  auto test = [&](long double k) {
    vector<int> id(N);
    rep(i, N) id[i] = i;
    sort(all(id), [&](int i, int j) {
        return (P[i]-k)/100.0*W[i] > (P[j]-k)/100.0*W[j];
      });
    double mSalt = 0;
    double mAll = 0;
    rep(i, K) {
      mAll += W[id[i]];
      mSalt += P[id[i]] * W[id[i]] / 100.0;
    }
    return mSalt/mAll*100 >= k;
  };
  auto binary_search = [&]() {
    long double ng = 101, ok = 0;
    while(abs(ok - ng) > 1e-10) {
      long double mid = (ok + ng) / 2;
      if(test(mid)) ok = mid;
      else ng = mid;
    }
    return ok;
  };

  cout << setprecision(10) << binary_search() << endl;
  return 0;
}
