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
  int na, nb; cin >> na >> nb;
  set<ll> sta, stb, stAll;
  rep(i, na) {
    ll a; cin >> a;
    sta.insert(a);
    stAll.insert(a);
  }
  rep(i, nb) {
    ll b; cin >> b;
    stb.insert(b);
    stAll.insert(b);
  }
  int cnt = 0;
  for(ll a: sta) if(stb.count(a)) cnt++;
  cout << fixed << setprecision(10) << (ld)cnt/stAll.size() << "\n";
  return 0;
}
