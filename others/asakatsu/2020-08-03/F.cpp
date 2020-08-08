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
  set<tuple<int, int, int>> st;
  vector<pair<string, string>> Ts(n);
  rep(i, n) {
    cin >> Ts[i].first >> Ts[i].second;
    for(string s: {Ts[i].first, Ts[i].second}) {
      int h = atoi(s.substr(0, 2).c_str());
      int m = atoi(s.substr(3).c_str());
      int val = h*100+m;
      int io = (s==Ts[i].first);
      st.insert({val, io, i});
      if(val+2400 < 3600) st.insert({val+2400, io, i});
    }
  }
  set<int> attend;
  vector<set<int>> share(n);
  for(auto ele: st) {
    int i = get<2>(ele);
    if(attend.count(i)) {
      attend.erase(i);
    } else {
      for(int a: attend) {
        share[i].insert(a);
        share[a].insert(i);
      }
      attend.insert(i);
    }
  }
  auto check = [&](int k) {
    set<int> vacant;
    rep(i, k) vacant.insert(i);
    vector<int> C(n, -1), D(n, -1);
    for(auto ele: st) {
      int i = get<2>(ele);
      if(C[i] != -1) {
        vacant.insert(C[i]);
        C[i] = -1;
      } else {
        if(vacant.empty()) return false;
        if(D[i] != -1 && !vacant.count(D[i])) return false;
        for(int v: vacant) {
          bool ok = true;
          for(int j: share[i]) {
            if(D[j] == v) {
              ok = false;
              break;
            }
          }
          if(ok) C[i] = v;
          else continue;
        }
        if(C[i] == -1) return false;
        D[i] = C[i];
        vacant.erase(C[i]);
      }
    }
    return true;
  };
  REP(i, 1, n+1) {
    if(check(i)) {
      cout << i << "\n";
      return 0;
    }
  }
  return 0;
}
