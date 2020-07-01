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
  int N; ll C;
  cin >> N >> C;
  vector<ll> X(N+2), V(N+2);
  rep(i, N) cin >> X[i+1] >> V[i+1];
  X[N+1] = C;
  // cout << X << V << endl;
  vector<ll> sumL(N+2), sumR(N+2);
  rep(i, N+1) sumL[i+1] = sumL[i]+V[i+1];
  rep(i, N+1) sumR[N-i] = sumR[N+1-i]+V[N-i];
  // cout << sumL << sumR << "\n";
  rep(i, N+2) sumL[i] -= X[i];
  rrep(i, N+2) sumR[i] -= C-X[i];
  // cout << sumL << sumR << "\n";
  ll ans = 0;
  {
    map<ll, set<int, greater<int>>> mp;
    multiset<ll, greater<ll>> se;
    rep(i, N+2) {
      se.insert(sumR[i]);
      mp[sumR[i]].insert(i);
    }
    rep(i, N+1) {
      se.erase(se.find(sumR[i]));
      ll maxR = *se.begin();
      ll cur = sumL[i] + maxR - min(X[i], C-X[*mp[maxR].begin()]);
      ans = max(ans, cur);
    }
  }
  {
    map<ll, set<int>> mp;
    multiset<ll, greater<ll>> se;
    rep(i, N+2) {
      se.insert(sumL[i]);
      mp[sumL[i]].insert(i);
    }
    for(int i=N+1; i>0; i--) {
      se.erase(se.find(sumL[i]));
      ll maxL = *se.begin();
      ll cur = sumR[i] + maxL - min(C-X[i], X[*mp[maxL].begin()]);
      ans = max(ans, cur);
    }
  }
  cout << ans << "\n";
  return 0;
}
