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
  vector<string> t;
  int l = 0, r = 0;
  while(l < (int)s.size()) {
    r++; // mark
    if(r+1<s.size() && s[r+1]>='0' && s[r+1]<='9') {
      r+=2;
    } else {
      r++;
    }
    t.push_back(s.substr(l, r-l));
    l = r;
  }
  // cout << t << endl;
  string mark[] = {"S", "H", "D", "C"};
  string num[] = {"10", "J", "Q", "K", "A"};
  string ans = s;
  rep(i, 4) {
    int cnt = 0;
    string tmp = "";
    for(auto s: t) {
      if(cnt == 5) break;
      bool ok = false;
      rep(j, 5) if(s == mark[i]+num[j]) ok = true;
      if(ok) {
        cnt++;
        continue;
      }
      tmp += s;
    }
    if(tmp.size() < ans.size()) ans = tmp;
  }
  cout << (ans=="" ? "0" : ans) << "\n";
  return 0;
}
