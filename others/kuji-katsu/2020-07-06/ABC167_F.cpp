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
  int n; cin >> n;
  vector<string> S(n);
  vector<vector<pair<int, int>>> T(4);
  int sum = 0;
  rep(i, n) {
    cin >> S[i];
    int cur = 0; int mn = 0;
    for(char c: S[i]) {
      cur += (c=='(' ? 1 : -1);
      mn = min(cur, mn);
    }
    sum += cur;
    if(cur >= 0) {
      if(mn == 0) T[0].emplace_back(mn, cur);
      else        T[1].emplace_back(mn, cur);
    } else {
      if(mn == cur) T[2].emplace_back(mn-cur, 0-cur);
      else          T[3].emplace_back(mn-cur, 0-cur);
    }
  }
  bool ok = true;
  if(sum != 0) ok = false;
  {
    int cur = 0;
    for(auto ele: T[0]) cur += ele.second;
    sort(all(T[1]), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
      });
    for(auto ele: T[1]) {
      if(cur+ele.first < 0) ok = false;
      cur += ele.second;
    }
  }
  {
    int cur = 0;
    for(auto ele: T[2]) cur += ele.second;
    sort(all(T[3]), [&](pair<int, int> p1, pair<int, int> p2) {
        if(p1.first == p2.first) return p1.second > p2.second;
        return p1.first > p2.first;
      });
    for(auto ele: T[3]) {
      if(cur+ele.first < 0) ok = false;
      cur += ele.second;
    }
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
