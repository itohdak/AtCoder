#include <bits/stdc++.h>
// #include <atcoder/all>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w, d; cin >> h >> w >> d;
  vector<vector<int>> A(h, vector<int>(w));
  vector<pair<int, int>> pos(h*w);
  rep(i, h) rep(j, w) {
    cin >> A[i][j];
    pos[--A[i][j]] = {i, j};
  }
  vector<ll> sum(h*w);
  rep(i, h*w) {
    if(i+d < h*w) {
      auto p1 = pos[i+d];
      auto p2 = pos[i];
      sum[i+d] += sum[i] + abs(p1.first-p2.first) + abs(p1.second-p2.second);
    }
  }
  int q; cin >> q;
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    l--; r--;
    cout << sum[r] - sum[l] << endk;
  }
  return 0;
}
