#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

struct edge {
  int to;
  ll cost;
  edge(int t, ll c): to(t), cost(c) {};
};

using P = pair<ll, int>;

int N;
vector<vector<edge>> G;
vector<ll> d;
vector<int> par;
void dijkstra(int s) {
  priority_queue<P, vector<P>, greater<P> > que;
  d = vector<ll>(N, longinf);
  par = vector<int>(N, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top();
    que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;

    for (int i=0; i<(int)G[v].size(); ++i) {
      edge e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
	d[e.to] = d[v] + e.cost;
	que.push(P(d[e.to], e.to));
	par[e.to] = v;
      }
    }
  }
}

int main() {
  string f, l;
  cin >> f >> l;
  int len = f.size();

  int M;
  cin >> M;
  set<string> S;
  S.insert(f);
  S.insert(l);
  rep(i, M) {
    string s;
    cin >> s;
    S.insert(s);
  }
  vector<string> ve(all(S));

  N = ve.size();
  G = vector<vector<edge>>(N);
  rep(i, N) rep(j, N) {
    int cnt = 0;
    rep(k, len) if(ve[i][k] != ve[j][k]) cnt++;
    if(cnt == 1) {
      G[i].push_back(edge(j, 1));
      G[j].push_back(edge(i, 1));
    }
  }

  int start, goal;
  rep(i, N) {
    if(ve[i] == f) start = i;
    if(ve[i] == l) goal = i;
  }
  dijkstra(start);

  if(d[goal] == longinf) cout << -1 << endl;
  else if(d[goal] == 0) cout << 0 << endl << f << endl << l << endl;
  else {
    cout << d[goal]-1 << endl;
    vector<string> ans;
    int tmp = goal;
    ans.push_back(ve[tmp]);
    while(par[tmp] != -1) {
      tmp = par[tmp];
      ans.push_back(ve[tmp]);
    }
    reverse(all(ans));
    for(string a: ans) cout << a << endl;
  }
  return 0;
}
