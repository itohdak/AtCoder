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
  int n, k, c; cin >> n >> k >> c;
  string s; cin >> s;
  vector<int> dpl(n), dpr(n);
  rep(i, n) {
    if(i+1<n) dpl[i+1] = max(dpl[i], dpl[i+1]);
    if(s[i]=='o'&&i+c+1<n) dpl[i+c+1] = max(dpl[i]+1, dpl[i+c+1]);
  }
  rrep(i, n) {
    if(i-1>=0) dpr[i-1] = max(dpr[i], dpr[i-1]);
    if(s[i]=='o' && i-(c+1)>=0) dpr[i-(c+1)] = max(dpr[i]+1, dpr[i-(c+1)]);
  }
  map<pair<int, int>, int> cnt;
  rep(i, n) if(s[i]=='o' && dpl[i]+dpr[i]==k-1) cnt[{dpl[i], dpr[i]}]++;
  rep(i, n) {
    if(s[i]=='o' && dpl[i]+dpr[i]==k-1 && cnt[{dpl[i], dpr[i]}]==1) {
      cout << i+1 << "\n";
    }
  }
  return 0;
}
