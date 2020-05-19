#include <iostream>

using namespace std;

#define MAX_N 100000

int par[MAX_N]; // 親の番号
int depth[MAX_N];

// n要素で初期化
void init(int n){
  for(int i=0; i<n; i++){
    par[i] = i;
    depth[i] = 0;
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
  } else {
    par[y] = x;
    if(depth[x] == depth[y])
      depth[x]++;
  }
}

int main(){
  init(MAX_N);
  int N, Q;
  cin >> N >> Q;
  for(int i=0; i<Q; i++) {
    int p, a, b;
    cin >> p >> a >> b;
    if(p == 0) {
      unite(a, b);
    } else {
      if(root(a) == root(b))
	cout << "Yes" << endl;
      else
	cout << "No" << endl;
    }
  }
  return 0;
}
