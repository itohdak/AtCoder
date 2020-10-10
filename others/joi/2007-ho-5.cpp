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

ll gcd(ll x, ll y) {
  if(x > y)
    return gcd(y, x);
  else if(x == 0)
    return y;
  else
    return gcd(y % x, x);
}
ll lcm(ll x, ll y) {
  ll g = gcd(x, y);
  return g * (x / g) * (y / g);
}

vector<vector<int>> G;
vector<int> Tpl;
/* topological sort */
vector<bool> vis;
void dfs(int cur) {
  if(vis[cur]) return;
  vis[cur] = true;
  for(int ne: G[cur]) dfs(ne);
  Tpl.push_back(cur);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<pair<ll, ll>> ratio(n);
  G = vector<vector<int>>(n);
  vis = vector<bool>(n);
  vector<int> RB(n, -1);
  rep(i, n) {
    ll p, q; int r, b;
    cin >> p >> q >> r >> b;
    ll g = gcd(p, q);
    ratio[i] = {p/g, q/g};
    if(r != 0) {
      G[r-1].push_back(i);
      RB[r-1] = 0;
    }
    if(b != 0) {
      G[b-1].push_back(i);
      RB[b-1] = 1;
    }
  }
  rep(i, n) dfs(i);
  reverse(all(Tpl));
  vector<pair<ll, ll>> mass(n);
  ll ans = 0;
  for(int i: Tpl) {
    ll l = lcm(ratio[i].first*max(mass[i].first, 1LL),
               ratio[i].second*max(mass[i].second, 1LL));
    ll sum = l/ratio[i].first + l/ratio[i].second;
    if(RB[i] == 0) {
      mass[G[i][0]].first = sum;
    } else if(RB[i] == 1) {
      mass[G[i][0]].second = sum;
    } else {
      ans = sum;
    }
  }
  cout << ans << endk;
  return 0;
}
