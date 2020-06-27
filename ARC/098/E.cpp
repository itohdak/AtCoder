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
  int N, K, Q;
  cin >> N >> K >> Q;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll ans = longinf;
  rep(i, N) {
    ll X = A[i];
    vector<ll> Y;
    multiset<ll> tmp;
    rep(j, N) {
      if(A[j] < X) {
        // cout << X << ' ' << A[j] << endl;
        if((int)tmp.size() >= K) {
          auto itr = tmp.begin();
          rep(k, tmp.size()-K+1) {
            Y.push_back(*itr);
            itr++;
          }
        }
        tmp.clear();
      } else {
        tmp.insert(A[j]);
      }
    }
    auto itr = tmp.begin();
    rep(k, tmp.size()-K+1) {
      Y.push_back(*itr);
      itr++;
    }
    sort(all(Y));
    // cout << X << ' ' << Y << endl;
    if((int)Y.size() >= Q) {
      ans = min(Y[Q-1]-Y[0], ans);
    }
  }
  cout << ans << endl;
  return 0;
}
