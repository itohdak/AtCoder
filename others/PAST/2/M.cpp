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
  int D, N;
  ll L;
  cin >> D >> L >> N;
  vector<int> C(D);
  map<int, vector<pair<int, int>>> mp;
  rep(i, D) {
    cin >> C[i];
    --C[i];
    if(mp.count(C[i])) {
      int cnt = mp[C[i]].back().first;
      int day = mp[C[i]].back().second;
      if(day < i-L) {
        mp[C[i]].emplace_back(cnt+(i-day)/L+1, i);
      } else {
        mp[C[i]].emplace_back(cnt+1, i);
      }
    } else {
      mp[C[i]].emplace_back(1, i);
    }
  }
  rep(i, N) {
    int k, f;
    ll t;
    cin >> k >> f >> t;
    --k;
    int cnt = 0;
  }
  return 0;
}
