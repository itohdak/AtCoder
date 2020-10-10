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
  int n, m; cin >> n >> m;
  vector<set<int>> G(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].insert(b);
  }
  string s; cin >> s;
  int i = 0;
  while(s[i] == '\"') i++;
  int k = i+1;
  i += 5; // group
  int l = i;
  while('0' <= s[i] && s[i] <= '9') i++;
  int st = atoi(s.substr(l, i-l).c_str())-1;
  vector<bool> aggress(k);
  rep(j, k) {
    if(s[i] == 'w') {
      aggress[j] = true;
      if(j) i += 2;
      else i++;
    }
    if(j != k-1) {
      assert(s[i]=='\"');
      i++;
    }
  }
  vector<set<int>> vst(2);
  vst[0].insert(st);
  int flag = 1;
  rep(i, k) {
    vst[flag].clear();
    rep(j, n) {
      if(aggress[i]) {
        for(int ne: G[j]) {
          if(vst[1-flag].count(ne)) vst[flag].insert(j);
        }
      } else {
        int cnt = 0;
        for(int ne: G[j]) {
          if(vst[1-flag].count(ne)) cnt++;
        }
        if(cnt != vst[1-flag].size()) vst[flag].insert(j);
      }
    }
    flag = 1-flag;
  }
  cout << vst[k%2].size() << "\n";
  return 0;
}
