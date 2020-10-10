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

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

vector<ll> d;
vector<int> par;
void dijkstra(int s, int N, vector<vector<edge>>& G) {
  priority_queue<P, vector<P>, greater<P>> que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;

    for(int i=0; i<(int)G[v].size(); i++) {
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        par[e.to] = v;
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, r, t; cin >> n >> m >> r >> t;
  vector<vector<edge>> G(n);
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    G[a].push_back({b, c});
    G[b].push_back({a, c});
  }
  ll ans = 0;
  rep(i, n) { // goal
    dijkstra(i, n, G);
    map<int, ll> cnt;
    rep(j, n) {
      if(i != j) {
        cnt[d[j]]++;
      }
    }
    ll prev = 0;
    for(auto& ele: cnt) {
      ele.second += prev;
      prev = ele.second;
    }
    for(auto ele=cnt.begin(); ele!=cnt.end(); ele++) {
      ll j = ele->first; // rabbit
      ll k = (1LL*j*t-1)/r; // turtle
      auto itr = cnt.upper_bound(k);
      if(itr == cnt.begin()) continue;
      if(ele == cnt.begin()) {
        ans += 1LL*(ele->second)*((--itr)->second-(j<=k));
      } else {
        ans += 1LL*(ele->second-(--ele)->second)*((--itr)->second-(j<=k));
        ++ele;
      }
    }
  }
  cout << ans << endk;
  return 0;
}
