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
  map<ll, int> cnt1;
  vector<ll> D(n); rep(i, n) cin >> D[i], cnt1[D[i]]++;
  int m; cin >> m;
  map<ll, int> cnt2;
  vector<ll> T(m); rep(i, m) cin >> T[i], cnt2[T[i]]++;
  for(auto ele: cnt2) {
    if(cnt1[ele.first] < ele.second) {
      cout << "NO" << "\n";
      return 0;
    }
  }
  cout << "YES" << "\n";
  return 0;
}
