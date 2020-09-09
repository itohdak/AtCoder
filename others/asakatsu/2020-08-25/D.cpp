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
  int n; ll h; cin >> n >> h;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  priority_queue<pair<ll, int>> q;
  rep(i, n) {
    q.push({A[i], 1});
    q.push({B[i], 0});
  }
  ll ans = 0;
  while(!q.empty() && h>0) {
    if(q.top().second == 0) {
      ans++;
      h -= q.top().first;
      q.pop();
    } else {
      ans += (h+q.top().first-1)/q.top().first;
      h = 0;
    }
  }
  cout << ans << endk;
  return 0;
}
