#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

typedef vector<vector<int> > Matrix;

Matrix d; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はinf、ただしd[i][i]=0）

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
  int n, m;
  cin >> n;

  d = Matrix(n, vector<int>(n, inf));
  for (int i = 0; i < n; i++) d[i][i] = 0;

  cin >> m;
  for (int i = 0; i < m; i++) {
    int from, to, cost;
    cin >> from >> to >> cost;
    d[from][to] = cost;
  }

  warshall_floyd(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && d[i][j] != inf)
        cout << i << "から" << j << "へのコスト: " << d[i][j] << endl;
    }
  }

  return 0;
}

