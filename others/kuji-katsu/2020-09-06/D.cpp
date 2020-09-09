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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> cnt;
  {
    int i = 0;
    int flag = 1;
    while(i < n) {
      int tmp = i;
      while(i < n && s[i] == '0'+flag) i++;
      cnt.push_back(i-tmp);
      flag = 1-flag;
    }
  }
  int ans = 0;
  if(cnt.size() <= k*2+1) cout << n << endk;
  else {
    int tmp = accumulate(cnt.begin(), cnt.begin()+k*2+1, 0);
    REP(i, k*2+1, cnt.size()) {
      chmax(ans, tmp);
      tmp -= cnt[i-2*k-1]+cnt[i-2*k];
      tmp += cnt[i]+(i+1<cnt.size() ? cnt[i+1] : 0);
      i++;
    }
    chmax(ans, tmp);
    cout << ans << endk;
  }
  return 0;
}
