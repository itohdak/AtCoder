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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  map<vector<int>, vector<int>> mp;
  vector<int> cur(26);
  rep(i, n) {
    if(i < k) cur[s[i]-'a']++;
    else {
      mp[cur].push_back(i);
      cur[s[i-k]-'a']--;
      cur[s[i]-'a']++;
    }
  }
  mp[cur].push_back(n);
  bool ok = false;
  for(auto& ele: mp) {
    auto& v = ele.second;
    if(v.back()-v.front() >= k) ok = true;
  }
  cout << (ok ? "YES" : "NO") << "\n";
  return 0;
}
