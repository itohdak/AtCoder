#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int W, H;
  cin >> W >> H;
  vector<ll> P(W), Q(H);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  rep(i, W) { cin >> P[i]; que.push(make_pair(P[i], 0)); }
  rep(i, H) { cin >> Q[i]; que.push(make_pair(Q[i], 1)); }
  ll ans = 0;
  int cntP=H+1, cntQ=W+1;
  while(!que.empty()) {
    auto top = que.top();
    que.pop();
    if(top.second == 0) {
      ans += top.first * cntP;
      cntQ--;
    } else {
      ans += top.first * cntQ;
      cntP--;
    }
  }
  cout << ans << endl;
  return 0;
}
