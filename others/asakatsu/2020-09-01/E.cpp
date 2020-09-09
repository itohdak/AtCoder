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
  int n; cin >> n;
  vector<ll> A(n), sum(n+1);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  ll ans = longinf;
  {
    ll tmp = 0;
    ll cnt = 0;
    rep(i, n) {
      if(i%2==0) {
        if(sum[i+1]+tmp<=0) {
          cnt += 1-(sum[i+1]+tmp);
          tmp += 1-(sum[i+1]+tmp);
        }
      } else {
        if(sum[i+1]+tmp>=0) {
          cnt += (sum[i+1]+tmp)+1;
          tmp -= (sum[i+1]+tmp)+1;
        }
      }
    }
    chmin(ans, cnt);
  }
  {
    ll tmp = 0;
    ll cnt = 0;
    rep(i, n) {
      if(i%2==0) {
        if(sum[i+1]+tmp>=0) {
          cnt += (sum[i+1]+tmp)+1;
          tmp -= (sum[i+1]+tmp)+1;
        }
      } else {
        if(sum[i+1]+tmp<=0) {
          cnt += 1-(sum[i+1]+tmp);
          tmp += 1-(sum[i+1]+tmp);
        }
      }
    }
    chmin(ans, cnt);
  }
  cout << ans << endk;
  return 0;
}
