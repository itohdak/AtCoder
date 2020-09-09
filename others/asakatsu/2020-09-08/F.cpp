#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<pair<int, int>> p1, p2, p3, p4;
  rep(i, n) {
    int mn = 0;
    int sum = 0;
    for(char c: S[i]) {
      sum += (c=='(' ? 1 : -1);
      chmin(mn, sum);
    }
    if(mn >= 0 && sum >= 0) p1.push_back({mn, sum});
    else if(mn < 0 && sum >= 0) p2.push_back({mn, sum});
    else if(mn == sum) p3.push_back({0, -sum});
    else p4.push_back({mn-sum, -sum});
  }
  // cout << p1 << p2 << p3 << p4 << endk;
  ll tmp1 = 0;
  for(auto p: p1) tmp1 += p.second;
  sort(all(p2), greater<pair<int, int>>());
  for(auto p: p2) {
    if(tmp1+p.first < 0) {
      cout << "No" << endk;
      return 0;
    }
    tmp1 += p.second;
  }
  ll tmp2 = 0;
  for(auto p: p3) tmp2 += p.second;
  sort(all(p4), greater<pair<int, int>>());
  for(auto p: p4) {
    if(tmp2+p.first < 0) {
      cout << "No" << endk;
      return 0;
    }
    tmp2 += p.second;
  }
  cout << (tmp1 == tmp2 ? "Yes" : "No") << endk;
  return 0;
}
