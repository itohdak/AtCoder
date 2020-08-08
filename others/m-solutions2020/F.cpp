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
  ll ans = longinf;
  ////
  map<ll, set<ll>> mpU, mpD, mpL, mpR;
  for(auto p: mp['U']) {
    mpU[p.first].insert(p.second);
  }
  for(auto p: mp['D']) {
    mpD[p.first].insert(p.second);
  }
  for(auto p: mp['L']) {
    mpL[p.second].insert(p.first);
  }
  for(auto p: mp['R']) {
    mpR[p.second].insert(p.first);
  }
  for(auto ele: mpU) {
    for(auto p: ele.second) {
      auto itr = mpD[ele.first].lower_bound(p);
      if(itr == mpD[ele.first].end()) continue;
      ans = min((*itr-p)*5, ans);
    }
  }
  for(auto ele: mpR) {
    for(auto p: ele.second) {
      auto itr = mpL[ele.first].lower_bound(p);
      if(itr == mpL[ele.first].end()) continue;
      ans = min((*itr-p)*5, ans);
    }
  }
  ////
  map<ll, set<ll>> mpU2, mpD2;
  map<ll, set<ll>> mpU3, mpD3;
  ll mx = 200000;
  for(auto p: mp['U']) {
    ll d = p.second-p.first;
    mpU2[d].insert(p.first);
    d = p.second-(mx-p.first);
    mpU3[d].insert(p.first);
  }
  for(auto p: mp['D']) {
    ll d = p.second+p.first;
    mpD2[d].insert(p.first);
    d = p.second+(mx-p.first);
    mpD3[d].insert(p.first);
  }
  for(auto p: mp['L']) {
    ll d = p.second+p.first;
    if(mpD2.count(d)) {
      auto itr = mpD2[d].upper_bound(p.first);
      if(itr == mpD2[d].begin()) continue;
      --itr;
      ans = min((p.first-*itr)*10, ans);
    }
    d = p.second-p.first;
    if(mpU2.count(d)) {
      auto itr = mpU2[d].upper_bound(p.first);
      if(itr == mpU2[d].begin()) continue;
      --itr;
      ans = min((p.first-*itr)*10, ans);
    }
  }
  for(auto p: mp['R']) {
    ll d = p.second+(mx-p.first);
    if(mpD3.count(d)) {
      auto itr = mpD3[d].lower_bound(p.first);
      if(itr == mpD3[d].end()) continue;
      ans = min((*itr-p.first)*10, ans);
    }
    d = p.second-(mx-p.first);
    if(mpU3.count(d)) {
      auto itr = mpU3[d].lower_bound(p.first);
      if(itr == mpU3[d].end()) continue;
      ans = min((*itr-p.first)*10, ans);
    }
  }
  if(ans == longinf) cout << "SAFE" << "\n";
  else cout << ans << "\n";
  return 0;
}
