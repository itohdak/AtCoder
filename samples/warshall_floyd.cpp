#include "header.hpp"

// グラフの距離を格納した2次元配列（隣接行列）
// dist[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はinf、ただしdist[i][i]=0）
vector<vector<ll>> dist;

void warshall_floyd(int n) {
  rep(i, n) rep(j, n) rep(k, n) {
    dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  }
}

void warshall_floyd_discription(int n) { // nは頂点数
  rep(i, n)      // 経由する頂点
    rep(j, n)    // 開始頂点
      rep(k, n)  // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main() {
  int n, m;
  cin >> n;

  dist = vector<vector<ll>>(n, vector<ll>(n, longinf));
  rep(i, n) dist[i][i] = 0;

  cin >> m;
  rep(i, m) {
    int from, to, cost;
    cin >> from >> to >> cost;
    dist[from][to] = cost;
  }

  warshall_floyd(n);

  rep(i, n) {
    rep(j, n) {
      if (i != j && dist[i][j] != longinf)
        cout << i << "から" << j << "へのコスト: " << dist[i][j] << endl;
    }
  }

  return 0;
}

