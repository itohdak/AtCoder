#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
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
  int n; cin >> n;
  vector<string> S(n);
  unordered_map<string, int> ss;
  map<int, int> size;
  int mn = inf;
  rep(i, n) {
    cin >> S[i];
    reverse(all(S[i]));
    ss[S[i]]++;
    size[S[i].size()]++;
    mn = min((int)S[i].size(), mn);
  }
  ll ans = 0;
  rep(i, n) {
    vector<bool> alpha(26);
    while(S[i].size() >= 0) {
      if(S[i].size()+1 < mn) break;
      rep(k, 26) if(alpha[k]) {
        S[i] += char('a'+k);
        if(size.find(S[i].size()) != size.end() && ss.find(S[i]) != ss.end()) ans++;
        S[i].pop_back();
      }
      if(S[i].size() == 0) break;
      alpha[S[i].back()-'a'] = true;
      S[i].pop_back();
    }
  }
  ans -= n;
  cout << ans << endk;
  return 0;
}
