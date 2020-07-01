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
  int H, W;
  cin >> H >> W;
  vector<string> S(H);
  map<char, int> cnt;
  rep(i, H) {
    cin >> S[i];
    rep(j, W) cnt[S[i][j]]++;
  }
  bool ok = true;
  int count[4] = {0};
  for(auto ele: cnt) count[ele.second%4]++;
  // rep(i, 4) cout << count[i] << endl;
  if(H%2 && W%2) {
    if(count[1]+count[3]!=1 || count[2]+count[3]>H/2+W/2) ok = false;
  } else if(H%2) {
    if(count[1]+count[3] || count[2]+count[3]>W/2) ok = false;
  } else if(W%2) {
    if(count[1]+count[3] || count[2]+count[3]>H/2) ok = false;
  } else {
    if(count[1]+count[2]+count[3]) ok = false;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
