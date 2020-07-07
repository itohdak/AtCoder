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
  int N; ll W;
  cin >> N >> W;
  vector<ll> v(N), w(N);
  rep(i, N) cin >> v[i] >> w[i];
  auto solve1 = [&]() {
    map<ll, ll> mp, mp2;
    int n = N/2;
    int m = N-n;
    rep(i, 1<<n) {
      ll curV = 0, curW = 0;
      rep(j, n) {
        if((i>>j)&1) {
          curV += v[j];
          curW += w[j];
        }
      }
      mp[curW] = max(curV, mp[curW]);
    }
    ll prev = 0;
    for(auto& ele: mp) {
      ele.second = max(prev, ele.second);
      prev = ele.second;
    }
    rep(i, 1<<m) {
      ll curV = 0, curW = 0;
      rep(j, m) {
        if((i>>j)&1) {
          curV += v[n+j];
          curW += w[n+j];
        }
      }
      mp2[curW] = max(curV, mp2[curW]);
    }
    prev = 0;
    for(auto& ele: mp2) {
      ele.second = max(prev, ele.second);
      prev = ele.second;
    }
    ll ans = 0;
    for(auto ele: mp) {
      auto itr = mp2.upper_bound(W-ele.first);
      if(itr == mp2.begin()) continue;
      itr--;
      ans = max(ele.second+itr->second, ans);
    }
    cout << ans << "\n";
  };
  auto solve2 = [&]() {
    ll mx = *max_element(all(w));
    ll wmax = mx*N;
    vector<vector<ll>> dp(N+1, vector<ll>(wmax+1));
    rep(i, N) {
      rep(j, wmax+1) {
        dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
        if(j+w[i]<=wmax) {
          dp[i+1][j+w[i]] = max(dp[i][j]+v[i], dp[i+1][j+w[i]]);
        }
      }
    }
    ll ans = 0;
    rep(i, min(W, wmax)+1) {
      ans = max(dp[N][i], ans);
    }
    cout << ans << "\n";
  };
  auto solve3 = [&]() {
    ll mx = *max_element(all(v));
    ll vmax = mx*N;
    vector<vector<ll>> dp(N+1, vector<ll>(vmax+1, longinf));
    dp[0][0] = 0;
    rep(i, N) {
      rep(j, vmax+1) {
        dp[i+1][j] = min(dp[i][j], dp[i+1][j]);
        if(j+v[i]<=vmax) {
          dp[i+1][j+v[i]] = min(dp[i][j]+w[i], dp[i+1][j+v[i]]);
        }
      }
    }
    ll ans = 0;
    rep(i, vmax+1) {
      if(dp[N][i]<=W) ans = max((ll)i, ans);
    }
    cout << ans << "\n";
  };
  if(N <= 30) {
    solve1();
  } else if(*max_element(all(w)) <= 1000) {
    solve2();
  } else {
    solve3();
  }
  return 0;
}
