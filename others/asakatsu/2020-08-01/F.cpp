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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  map<string, vector<int>> mp;
  string cnt(26, '0');
  rep(i, k) cnt[s[i]-'a']++;
  mp[cnt].push_back(0);
  bool ans = false;
  REP(i, k, n) {
    cnt[s[i-k]-'a']--;
    cnt[s[i]-'a']++;
    if(mp.count(cnt) && upper_bound(all(mp[cnt]), i-k+1-k) != mp[cnt].begin()) {
      ans = true;
      break;
    }
    mp[cnt].push_back(i-k+1);
    // cout << mp << "\n";
  }
  cout << (ans ? "YES" : "NO") << "\n";
  return 0;
}
