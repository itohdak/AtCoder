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

int getPar(int i) {
  return (i+1)/2-1;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<ll> V(N), W(N);
  rep(i, N) cin >> V[i] >> W[i];
  ll Q;
  cin >> Q;
  vector<int> qv(Q);
  vector<ll> qL(Q);
  rep(i, Q) {
    cin >> qv[i] >> qL[i];
    qv[i]--;
  }

  ll MAX = *max_element(all(qL))+1;
  int K = ceil(log2(N))/2;
  vector<vector<ll>> dp(1<<K, vector<ll>(MAX));
  rep(i, 1<<K) {
    if(i >= N) continue;
    int par = getPar(i);
    if(par == -1) {
      dp[i][W[i]] = V[i];
      continue;
    }
    rep(j, MAX) {
      dp[i][j] = max(dp[par][j], dp[i][j]);
      if(j+W[i] < MAX) {
        dp[i][j+W[i]] = max(dp[par][j]+V[i], dp[i][j+W[i]]);
      }
    }
  }
  rep(i, 1<<K) {
    if(i >= N) continue;
    rep(j, MAX) {
      if(j) dp[i][j] = max(dp[i][j-1], dp[i][j]);
    }
  }
  rep(i, Q) {
    int v = qv[i]; ll L = qL[i];
    int tmp = v;
    vector<vector<pair<ll, ll>>> vv(2);
    vv[0].emplace_back(0, 0);
    int flag = 1;
    while(tmp >= 1<<K) {
      vv[flag].clear();
      for(auto& ele: vv[1-flag]) {
        ll w = ele.first;
        ll v = ele.second;
        vv[flag].emplace_back(ele);
        vv[flag].emplace_back(w+W[tmp], v+V[tmp]);
      }
      flag = 1-flag;
      tmp = getPar(tmp);
    }
    ll mx = 0;
    for(auto& ele: vv[1-flag]) {
      ll w = ele.first;
      ll v = ele.second;
      if(L-w < MAX && L-w >= 0) {
        mx = max(v+dp[tmp][L-w], mx);
      }
    }
    cout << mx << endl;
  }
  return 0;
}
