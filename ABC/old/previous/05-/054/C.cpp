#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REP(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

vector<vector<int> > E; // edges
vector<bool> vis;
int ans;
int N;
void dfs(int tmp, int par, int value){
  if(vis[tmp]) return;
  if(value+1 == N) {
    ans++;
    return;
  }
  vis[tmp] = true;
  for(int c: E[tmp])
    if(c != par)
      dfs(c, tmp, value+1);
  vis[tmp] = false;
}

int main() {
  int M;
  cin >> N >> M;
  E = vector<vector<int> >(N);
  vis = vector<bool>(N);
  rep(i, M) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  ans = 0;
  dfs(0, -1, 0);
  cout << ans << endl;
  return 0;
}

