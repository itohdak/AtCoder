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
  string s; cin >> s;
  int l = 0, r = 0;
  int k = 0;
  string prev = "";
  int n = s.size();
  while(l < n) {
    r = l+1;
    while(r < n && s.substr(l, r-l) == prev) r++;
    if(prev != s.substr(l, r-l)) k++;
    prev = s.substr(l, r-l);
    l = r;
  }
  cout << k << "\n";
  return 0;
}
