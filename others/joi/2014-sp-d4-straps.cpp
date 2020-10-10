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
  ll ans = 0;
  int cnt = 0;
  vector<ll> noterm;
  vector<pair<ll, int>> neg;
  rep(i, n) {
    int a; ll b;
    cin >> a >> b;
    if(a == 0) {
      noterm.push_back(b);
    } else if(b < 0) {
      neg.push_back({b, a});
    } else {
      ans += b;
      cnt += a-1;
    }
  }
  sort(all(noterm), greater<ll>());
  sort(all(neg), greater<pair<ll, int>>());
  return 0;
}
