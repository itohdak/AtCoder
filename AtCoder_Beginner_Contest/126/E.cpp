#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric> // accumulate(v.begin(), v.end(), 0)

using namespace std;
#define ll long long

#define MAX_N 100000

int par[MAX_N]; // 親の番号
int depth[MAX_N];
int nGroup[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
    nGroup[i] = 1;
  }
}
// 木の根を求める
int root(int x){
  if(par[x] == x){ // 根
    return x;
  } else {
    return par[x] = root(par[x]); // 経路圧縮
  }
}

// xとyが同じ集合に属するか否か
bool same(int x, int y){
  return root(x) == root(y);
}

// xとyの属する集合を併合
void unite(int x, int y){
  x = root(x);
  y = root(y);
  if(x == y) return;

  if(depth[x] < depth[y]){
    par[x] = y;
    nGroup[y] += nGroup[x];
    nGroup[x] = 0;
  } else {
    par[y] = x;
    nGroup[x] += nGroup[y];
    nGroup[y] = 0;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

int main() {
  int N, M;
  cin >> N >> M;
  init(N);
  for(int i=0; i<M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;  y--;
    unite(x, y);
  }
  int ans = 0;
  for(int i=0; i<N; i++)
    if(nGroup[i] != 0)
      ans++;
  cout << ans << endl;
  return 0;
}

