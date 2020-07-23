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
  vector<ll> W(n); rep(i, n) cin >> W[i];
  vector<ll> cur;
  rep(i, n) {
    ll mn = longinf;
    int mni = -1;
    rep(j, cur.size()) {
      if(cur[j] >= W[i] && cur[j] < mn) {
        mn = cur[j];
        mni = j;
      }
    }
    if(mni == -1) {
      cur.push_back(W[i]);
    } else {
      cur[mni] = W[i];
    }
  }
  cout << cur.size() << "\n";
  return 0;
}
