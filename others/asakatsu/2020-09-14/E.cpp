#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  if(s == string(20, 'z') || s == "a") {
    cout << "NO" << endk;
    return 0;
  }
  int cnt = 0;
  rep(i, n) cnt += s[i]-'a'+1;
  string ans;
  while(cnt > 26) {
    ans += 'z';
    cnt -= 26;
  }
  ans += char('a'+cnt-1);
  if(ans == s) {
    if(ans.size() == 1) {
      ans[0]--;
      ans += 'a';
      cout << ans << endk;
    } else {
      ans[0]--;
      ans.back()++;
      cout << ans << endk;
    }
  } else {
    cout << ans << endk;
  }
  // bool allA = true;
  // rep(i, n) if(s[i] != 'a') allA = false;
  // if(allA) {
  //   cout << string(n-2, 'a') << 'b' << endk;
  // } else if(n == 20) {
  //   string ans = s;
  //   int t = -1;
  //   rep(i, n) if(s[i] == 'z') t = i;
  //   if(t == -1) rep(i, n) if(s[i] != 'a') t = i;
  //   int u = -1;
  //   rep(i, n) if(i != t && s[i] != 'z') u = i;
  //   assert(u != -1);
  //   swap(ans[t], ans[u]);
  //   cout << ans << endk;
  // } else {
  //   string ans(n+1, 'a');
  //   cnt -= n+1;
  //   rep(i, n+1) ans[i] += cnt/(n+1);
  //   cnt %= n+1;
  //   rep(i, cnt) ans[i]++;
  //   cout << ans << endk;
  // }
  return 0;
}
