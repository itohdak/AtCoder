#include <bits/stdc++.h>
// #include "/home/itohdak/AtCoder/000/print.hpp"
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

vector<vector<int>> G;
vector<ll> A;
vector<int> ans;
vector<ll> lis;
deque<pair<int, ll>> q;
void dfs(int tmp, int par) {
  auto it = lower_bound(all(lis), A[tmp]);
  q.emplace_back((int)(it-lis.begin()), *it);
  *it = A[tmp];
  ans[tmp] = lower_bound(all(lis), longinf) - lis.begin();
  for(int ne: G[tmp]) {
    if(ne != par) dfs(ne, tmp);
  }
  auto b = q.back();
  lis[b.first] = b.second;
  q.pop_back();
}
int main() {
  int N;
  cin >> N;
  A = vector<ll>(N);
  ans = vector<int>(N);
  rep(i, N) cin >> A[i];
  G = vector<vector<int>>(N);
  rep(i, N-1) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  lis = vector<ll>(N, longinf);
  dfs(0, -1);
  rep(i, N) cout << ans[i] << endl;
  return 0;
}
