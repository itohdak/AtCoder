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
  vector<string> A(H);
  map<char, int> mp;
  rep(i, H) {
    cin >> A[i];
    rep(j, W) mp[A[i][j]]++;
  }
  bool ok = true;
  if(H%2==0 && W%2==0) {
    for(auto ele: mp) if(ele.second%4!=0) ok = false;
  } else if(H%2==0 || W%2==0) {
    int cnt = (H%2==0 ? H : W)/2;
    for(auto ele: mp) {
      if(ele.second%2!=0) ok = false;
      else if(ele.second%4!=0) {
        if(cnt==0) ok = false;
        cnt--;
      }
    }
  } else {
    int cnt = (H-1)/2+(W-1)/2;
    int one = 0;
    for(auto ele: mp) {
      if(ele.second%2!=0) one++;
      else if(ele.second%4!=0) {
        if(cnt==0) ok = false;
        cnt--;
      }
    }
    if(one != 1) ok = false;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
