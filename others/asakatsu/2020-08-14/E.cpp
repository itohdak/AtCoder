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
  string s, t; cin >> s >> t;
  int n = s.size();
  map<char, vector<int>> mp;
  rep(i, n) {
    mp[s[i]].push_back(i);
  }
  int m = t.size();
  int cnt = 0;
  int pos = 0;
  rep(i, m) {
    if(!mp.count(t[i])) {
      cout << -1 << endk;
      return 0;
    }
    while(1) {
      auto itr = lower_bound(all(mp[t[i]]), pos);
      if(itr == mp[t[i]].end()) {
        cnt++; pos = 0;
        continue;
      }
      pos = *itr+1;
      break;
    }
  }
  cout << 1LL*cnt*n+pos << endk;
  return 0;
}
