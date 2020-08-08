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
  vector<ll> A(n), sum(n+1);
  rep(i, n) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
  }
  vector<ll> sumOrig(n+1);
  copy(all(sum), begin(sumOrig));
  ll ans = longinf;
  rep(j, 2) {
    copy(all(sumOrig), begin(sum));
    ll tmp = 0;
    ll diff = 0;
    int flag = j;
    rep(i, n) {
      if(flag==1 && sum[i+1]+diff<=0) {
        tmp += 1-(sum[i+1]+diff);
        diff += 1-(sum[i+1]+diff);
      } else if(flag==0 && sum[i+1]+diff>=0) {
        tmp += (sum[i+1]+diff)+1;
        diff -= (sum[i+1]+diff)+1;
      }
      // cout << tmp << ' ' << diff << endk;
      flag = 1-flag;
    }
    ans = min(tmp, ans);
  }
  cout << ans << endk;
  return 0;
}
