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
  ll s; cin >> s;
  int n = (int)log10(s)+1;
  ll ans = 0;
  rep(i, 1<<(n-1)) {
    vector<int> v;
    v.push_back(-1);
    rep(j, n-1) if((i>>j)&1) v.push_back(j);
    v.push_back(n-1);
    ll tmp = 0;
    rep(j, v.size()-1) {
      tmp += s/(ll)pow(10, n-1-v[j+1])%(ll)pow(10, (v[j+1]-v[j]));
    }
    ans += tmp;
  }
  cout << ans << endk;
  return 0;
}
