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
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll sum = accumulate(all(A), 0LL);
  ll m = N*(N+1)/2;
  if(sum % m != 0) {
    cout << "NO" << endl;
  } else {
    ll k = sum / m;
    ll cnt = 0;
    bool ok = true;
    rep(i, N) {
      int j = (i+1)%N;
      ll sub = k-(A[j]-A[i]);
      if(sub < 0 || sub % N != 0) {
        ok = false;
        break;
      }
      cnt += sub / N;
    }
    if(ok && cnt == k) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
