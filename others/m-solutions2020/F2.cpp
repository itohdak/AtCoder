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
  int n; cin >> n;
  vector<ll> X(n), Y(n);
  vector<char> U(n);
  map<char, vector<pair<ll, ll>>> mp;
  rep(i, n) {
    cin >> X[i] >> Y[i] >> U[i];
    mp[U[i]].push_back({X[i], Y[i]});
  }
  ////
  ll ans = longinf;
  {
    map<ll, vector<pair<ll, char>>> mpv;
    for(auto ele: mp['U']) mpv[ele.first].push_back({ele.second, 'U'});
    for(auto ele: mp['D']) mpv[ele.first].push_back({ele.second, 'D'});
    for(auto& ele: mpv) {
      auto& v = ele.second;
      sort(all(v));
      if(v.size() > 1) {
        rep(i, v.size()-1) {
          if(v[i].second=='U' && v[i+1].second=='D') {
            ans = min((v[i+1].first-v[i].first)*5, ans);
          }
        }
      }
    }
  }
  {
    map<ll, vector<pair<ll, char>>> mpv;
    for(auto ele: mp['R']) mpv[ele.second].push_back({ele.first, 'R'});
    for(auto ele: mp['L']) mpv[ele.second].push_back({ele.first, 'L'});
    for(auto& ele: mpv) {
      auto& v = ele.second;
      sort(all(v));
      if(v.size() > 1) {
        rep(i, v.size()-1) {
          if(v[i].second=='R' && v[i+1].second=='L') {
            ans = min((v[i+1].first-v[i].first)*5, ans);
          }
        }
      }
    }
  }
  ////
  vector<pair<char, char>> P = {{'R', 'U'}, {'U', 'L'}, {'L', 'D'}, {'D', 'R'}};
  rep(k, 4) {
    map<ll, vector<pair<ll, char>>> mpv;
    char c1 = P[k].first, c2 = P[k].second;
    for(auto ele: mp[c1]) {
      ll x = ele.first-100000, y = ele.second-100000;
      rep(i, k) { // rotate 90 deg
        ll nx = y, ny = -x;
        x = nx, y = ny;
      }
      x += 100000, y += 100000;
      mpv[x+y].push_back({x, c1});
    }
    for(auto ele: mp[c2]) {
      ll x = ele.first-100000, y = ele.second-100000;
      rep(i, k) { // rotate 90 deg
        ll nx = y, ny = -x;
        x = nx, y = ny;
      }
      x += 100000, y += 100000;
      mpv[x+y].push_back({x, c2});
    }
    for(auto& ele: mpv) {
      auto& v = ele.second;
      sort(all(v));
      if(v.size() > 1) {
        rep(i, v.size()-1) {
          if(v[i].second==c1 && v[i+1].second==c2) {
            ans = min((v[i+1].first-v[i].first)*10, ans);
          }
        }
      }
    }
  }
  if(ans == longinf) cout << "SAFE" << "\n";
  else               cout << ans << "\n";
  return 0;
}
