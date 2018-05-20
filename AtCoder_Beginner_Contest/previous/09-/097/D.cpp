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
int rank_of_tree[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    rank_of_tree[i] = 0;
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

  if(rank_of_tree[x] < rank_of_tree[y]){
    par[x] = y;
  } else {
    par[y] = x;
    if(rank_of_tree[x] == rank_of_tree[y])
      rank_of_tree[x]++;
  }
}

int main(){
  int N, M;
  cin >> N >> M;
  int P[N];
  for(int i=0; i<N; i++){
    cin >> P[i];
    P[i]--; // 0 <= P[i] <= N-1
  }

  init(N);
  for(int i=0; i<M; i++){
    int x, y;
    cin >> x >> y;
    unite(x-1, y-1);
  }

  int ret = 0;
  for(int i=0; i<N; i++)
    if(same(P[i], i))
      ret++;
  cout << ret << endl;

  return 0;
}

