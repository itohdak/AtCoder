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

ll toll(string s) {
  int n = s.size();
  ll ret = 0;
  ll pw = 1;
  rrep(i, n) {
    ret += (s[i]-'0') * pw;
    pw *= 10;
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n);
  ll pw = 1;
  rep(i, 9) pw *= 10;
  rep(i, n) {
    string s; cin >> s;
    int m = s.size();
    int j = 0;
    while(j<m && s[j]!='.') j++;
    if(j == m) {
      A[i] = toll(s) * pw;
    } else {
      string t(9, '0');
      REP(k, j+1, m) t[k-j-1] = s[k];
      A[i] += toll(s.substr(0, j)) * pw;
      A[i] += toll(t);
    }
  }
  vector<pair<int, int>> cnt(n);
  int mx = 60;
  vector<vector<ll>> sum(mx, vector<ll>(mx));
  rep(i, n) {
    int cnt2 = 0, cnt5 = 0;
    ll a = A[i];
    while(a % 2 == 0) {
      cnt2++;
      a /= 2;
    }
    while(a % 5 == 0) {
      cnt5++;
      a /= 5;
    }
    sum[cnt2][cnt5]++;
    cnt[i].first = cnt2;
    cnt[i].second = cnt5;
  }
  rep(i, mx) rep(j, mx-1) sum[i][j+1] += sum[i][j];
  rep(j, mx) rep(i, mx-1) sum[i+1][j] += sum[i][j];
  assert(sum[mx-1][mx-1]==n);
  ll ans = 0;
  rep(i, n) {
    if(cnt[i].first >= 18 && cnt[i].second >= 18) {
      ans += sum[mx-1][mx-1];
    } else if(cnt[i].first >= 18) {
      ans += sum[mx-1][mx-1] - sum[mx-1][18-cnt[i].second-1];
    } else if(cnt[i].second >= 18) {
      ans += sum[mx-1][mx-1] - sum[18-cnt[i].first-1][mx-1];
    } else {
      ans += sum[mx-1][mx-1] - sum[18-cnt[i].first-1][mx-1] - sum[mx-1][18-cnt[i].second-1] + sum[18-cnt[i].first-1][18-cnt[i].second-1];
    }
    if(A[i]%1000000000LL==0) ans--;
  }
  assert(ans%2==0);
  cout << ans/2 << endk;
  return 0;
}
