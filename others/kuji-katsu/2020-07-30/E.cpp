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
  vector<int> P(n), pos(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
    pos[P[i]] = i;
  }
  pos.push_back(-1);
  int l = 0;
  int mx = 0;
  rep(r, n) {
    if(pos[r] > pos[r+1]) {
      mx = max(r-l+1, mx);
      l = r+1;
    }
  }
  cout << n-mx << "\n";
  return 0;
}
