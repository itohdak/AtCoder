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
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  map<char, int> mp;
  for(char c: s) mp[c]++;
  int m = 0;
  for(auto ele: mp) {
    if(ele.second % 2) {
      m++;
    }
  }
  if(m == 0) {
    cout << s.size() << endk;
  } else {
    int rem = s.size()-m;
    cout << (rem/2/m*2)+1 << endk;
  }
  return 0;
}
