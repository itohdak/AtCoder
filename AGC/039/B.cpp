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

typedef vector<vector<int> > Matrix;

Matrix dist; // グラフの距離を格納した2次元配列（隣接行列）
             // dist[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はinf、ただしdist[i][i]=0）

bool dfs(vector<vector<char> >& S, vector<int>& check, int N, int tmp, int par) {
  if(par != -1) {
    if(check[tmp] == -1) check[tmp] = 1 - check[par];
    else if(check[tmp] != 1 - check[par]) return false;
    else return true;
  }
  rep(i, N)
    if(S[tmp][i] == '1')
      if(!dfs(S, check, N, i, tmp))
        return false;
  return true;
}

void warshall_floyd(int n) { // nは頂点数
  rep(i, n)      // 経由する頂点
    rep(j, n)    // 開始頂点
      rep(k, n)  // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main() {
  int N;
  cin >> N;
  dist = Matrix(N, vector<int>(N, inf));
  vector<vector<char> > S(N, vector<char>(N));
  rep(i, N) {
    dist[i][i] = 0;
    rep(j, N) {
      cin >> S[i][j];
      if(S[i][j] == '1')
        dist[i][j] = 1;
    }
  }
  vector<int> check(N, -1);
  check[0] = 0;
  bool ret = dfs(S, check, N, 0, -1);
  if(!ret) {
    cout << -1 << endl;
    return 0;
  }
  warshall_floyd(N);
  int M = 0;
  rep(i, N) rep(j, N) M = max(M, dist[i][j]);
  cout << M + 1 << endl;
  return 0;
}

