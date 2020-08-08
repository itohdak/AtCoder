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
  vector<int> A(n); rep(i, n) cin >> A[i];
  map<int, int> mp;
  rep(i, n) mp[A[i]]++;
  if(mp.size() > 2) {
    cout << "No\n";
  } else if(mp.size() == 2) {
    ll a = mp.begin()->first;
    ll b = mp.rbegin()->first;
    if(a == b-1) {
      ll nCol = b;
      ll na = mp[a];
      ll m = nCol-na;
      if(m <= 0) cout << "No\n";
      else if(mp[b] < 2*m) cout << "No\n";
      else cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    ll a = mp.begin()->first;
    if(a == n-1) cout << "Yes\n";
    else if(n >= 2*a) cout << "Yes\n";
    else cout << "No\n";
  }
  return 0;
}
