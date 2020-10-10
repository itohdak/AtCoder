#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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
const ll mod2 = 998244353;
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
  string f, l; cin >> f >> l;
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  if(f == l) {
    cout << 0 << endk << f << endk << l << endk;
    return 0;
  }
  S.push_back(f);
  S.push_back(l);
  vector<vector<edge>> G(n+2);
  rep(i, n+2) rep(j, n+2) {
    int diff = 0;
    rep(k, f.size()) {
      if(S[i][k] != S[j][k]) diff++;
    }
    if(diff == 1) {
      G[i].push_back({j, 1});
    }
  }
  dijkstra(n, n+2, G);
  if(d[n+1] == longinf) {
    cout << -1 << endk;
    return 0;
  }
  cout << d[n+1]-1 << endk;
  vector<string> ans;
  {
    int tmp = n+1;
    while(par[tmp] != -1) {
      ans.push_back(S[tmp]);
      tmp = par[tmp];
    }
    ans.push_back(S[tmp]);
  }
  reverse(all(ans));
  for(string a: ans) cout << a << endk;
  return 0;
}
