#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
  int n, q; cin >> n >> q;
  vector<ll> A(n);
  vector<ll> sum(n+1), odd(n+1), even(n+1);
  rep(i, n) {
    cin >> A[i];
    odd[i+1] = odd[i];
    even[i+1] = even[i];
    sum[i+1] = sum[i] + A[i];
    if(i%2) odd[i+1] += A[i];
    else even[i+1] += A[i];
  }
  vector<int> B;
  rep(i, n) {
    int m = n-i;
    B.push_back((A[i]+A[i+m/2])/2+1);
  }
  // cout << B << endk;
  vector<ll> X(q);
  rep(i, q) {
    cin >> X[i];
    int ret = upper_bound(all(B), X[i]) - B.begin();
    // cout << ret << endk;
    ll ans = 0;
    if(n%2) ans += odd[ret];
    else    ans += even[ret];
    ans += sum[ret+(n-ret)/2]-sum[ret];
    cout << sum[n]-ans << endk;
  }
  return 0;
}
