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
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int h, w; cin >> h >> w;
  vector<string> A(h);
  map<char, int> mp;
  rep(i, h) {
    cin >> A[i];
    rep(j, w) mp[A[i][j]]++;
  }
  int nOdd = 0;
  int nEven = 0;
  int nFour = 0;
  for(auto ele: mp) {
    if(ele.second%2) nOdd++;
    else if(ele.second%4==0) nFour++;
    else nEven++;
  }
  if(h%2==0 && w%2==0) {
    if(nOdd>0 || nEven>0) cout << "No" << "\n";
    else cout << "Yes" << "\n";
  } else if(h%2==0) {
    if(nOdd>0 || nEven>h/2) cout << "No" << "\n";
    else cout << "Yes" << "\n";
  } else if(w%2==0) {
    if(nOdd>0 || nEven>w/2) cout << "No" << "\n";
    else cout << "Yes" << "\n";
  } else {
    if(nOdd!=1 || nEven>h/2+w/2) cout << "No" << "\n";
    else cout << "Yes" << "\n";
  }
  return 0;
}
