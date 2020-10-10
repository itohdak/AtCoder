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
  int h, w, m; cin >> h >> w >> m;
  vector<int> H(m), W(m);
  map<int, int> cntH, cntW;
  set<pair<int, int>> st;
  rep(i, m) {
    cin >> H[i] >> W[i];
    H[i]--; W[i]--;
    st.insert({H[i], W[i]});
    cntH[H[i]]++;
    cntW[W[i]]++;
  }
  int mxH = 0, mxW = 0;
  vector<int> mxi, mxj;
  for(auto ele: cntH) {
    if(ele.second > mxH) {
      mxi.clear();
      mxi.push_back(ele.first);
    } else if(ele.second == mxH) {
      mxi.push_back(ele.first);
    }
    chmax(mxH, ele.second);
  }
  for(auto ele: cntW) {
    if(ele.second > mxW) {
      mxj.clear();
      mxj.push_back(ele.first);
    } else if(ele.second == mxW) {
      mxj.push_back(ele.first);
    }
    chmax(mxW, ele.second);
  }
  ll ans = mxH + mxW;
  for(int i: mxi) {
    for(int j: mxj) {
      if(!st.count({i, j})) {
        cout << ans << endk;
        return 0;
      }
    }
  }
  cout << ans-1 << endk;
  return 0;
}
