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
  int n; cin >> n;
  vector<ll> A(3*n); rep(i, 3*n) cin >> A[i];
  multiset<ll> s1, s2, s3;
  ll sum1=0, sum2=0;
  rep(i, n) {
    s1.insert(A[i]);
    sum1 += A[i];
  }
  REP(i, n, 3*n) {
    s2.insert(A[i]);
    sum2 += A[i];
  }
  while((int)s2.size() > n) {
    ll mx = *s2.rbegin();
    s3.insert(mx);
    s2.erase(s2.find(mx));
    sum2 -= mx;
  }
  ll ans = sum1-sum2;
  REP(i, n, 2*n) {
    if(s3.count(A[i])) {
      s3.erase(s3.find(A[i]));
      s1.insert(A[i]);
      ll mn = *s1.begin();
      sum1 += A[i]-mn;
      s1.erase(s1.find(mn));
    } else {
      s2.erase(s2.find(A[i]));
      ll mn = *s3.begin();
      sum2 += mn-A[i];
      s3.erase(s3.find(mn));
      s2.insert(mn);
      s1.insert(A[i]);
      mn = *s1.begin();
      sum1 += A[i]-mn;
      s1.erase(s1.find(mn));
    }
    ans = max(sum1-sum2, ans);
  }
  cout << ans << "\n";
  return 0;
}
