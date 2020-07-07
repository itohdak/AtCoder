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
  vector<ll> A(3*n);
  rep(i, 3*n) cin >> A[i];
  multiset<ll> s1, s2, s3;
  ll sum1=0, sum2=0;
  rep(i, n) {
    s1.insert(A[i]);
    sum1 += A[i];
  }
  REP(i, n, 2*n) {
    s2.insert(A[i]);
    sum2 += A[i];
  }
  REP(i, 2*n, 3*n) {
    if(A[i] < *s2.rbegin()) {
      sum2 += A[i]-*s2.rbegin();
      s3.insert(*s2.rbegin());
      s2.erase(--s2.end());
      s2.insert(A[i]);
    } else {
      s3.insert(A[i]);
    }
  }
  ll ans = sum1 - sum2;
  REP(i, n, 2*n) {
    if(s2.count(A[i])) {
      sum2 += *s3.begin()-A[i];
      s2.erase(s2.find(A[i]));
      s2.insert(*s3.begin());
      s3.erase(s3.begin());
    } else {
      s3.erase(s3.find(A[i]));
    }
    if(A[i] > *s1.begin()) {
      sum1 += A[i]-*s1.begin();
      s1.erase(s1.begin());
      s1.insert(A[i]);
    }
    ans = max(sum1-sum2, ans);
  }
  cout << ans << "\n";
  return 0;
}
